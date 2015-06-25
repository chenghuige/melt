#!/usr/bin/env python
# -*- coding: utf-8 -*-
#file    h2cc.py
#author  pku_goldenlock@qq.com
#date    20150625

#.h convert to interface only.h


import sys,re,getopt,os

def usage():
    """ 
        Run the program like this
        
        ./h2cc.py abc.h ok.cc
        It will read abc.h and append the fuctions 
        to be implemented to ok.cc
        
        or 
           ./h2cc.py abc.h         #will create abc.cc
           ./h2cc.py abc.h cpp     #will create abc.cpp
        """


pattern_comment = re.compile(r'^\s*//')
#传入一个打开的文件(我们要生成的或者已经存在要分析处理)的handle，如abc.cc
#调用该函数者负责关闭该文件,该函数只负责处理
stack_class = []                #----存储class name
stack_namespace = []

abstract_classes = set()
abstract_class_out = open('abstract_class.txt', 'a')

input_file = ''


#       value_type& Value(index_type index) ----------- line
#       {  -------------------------------here and below as content
#           return values[index];
#      }
def pyplusplus_hack(line, content):
    global abstract_class_out
    global abstract_classes
    global stack_class
    global input_file
    vec_ref_pattern = re.compile(r'return.+?\[.+?\];')   
    lines = line.split('\n')
    need_comment = False
    return_nonconst_ref = False
    for i in range(len(lines)):
        lines[i] = lines[i].replace('override', '')
        line = lines[i].strip().replace('inline', '').strip()
        l = line.split()
        if len(l) > 1 and l[0] == 'static' and (l[1].endswith('&') or l[1].endswith('*')):
            need_comment = True
            break
        if line.find('&&') >= 0:
            need_comment = True 
            break 
        if line.replace(' ','').endswith(')=0'):
            full_class_name = '::'.join(stack_namespace) + '::' + '::'.join(stack_class) 
            if not full_class_name in abstract_classes:
                abstract_class_out.write("%s\t%s\n"%(full_class_name, input_file))
                abstract_classes.add(full_class_name)
            need_comment = True
            break 
        if len(l) > 1 and (l[0].endswith('&') or l[0].endswith('*')):
            return_nonconst_ref = True
    if return_nonconst_ref:
        contents = content.split('\n')
        i = len(contents) -1
        find = False
        while i >= 0:
            #确保最后一个return是正确书写的没有干扰
            if vec_ref_pattern.search(contents[i]):
                find = True
                break
            i -= 1
        if find:
            need_comment = True
    if need_comment:
        lines = ['//' + line for line in lines if line != '']
    return '\n'.join(lines) + '\n'


def count_pair(line, pl, pr, nl, nr):
    pos = -1
    i = 0
    for item in line:
        if item == pl:
            nl += 1
        elif item == pr:
            nr += 1
            if nl == nr and pos == -1:
                pos = i
        i += 1
    return nl,nr,pos

def count_bracket(line, nl, nr):
    return count_pair(line, '(', ')', nl, nr)

def count_pair_reverse(line, pl, pr, nl, nr):
    pos = -1
    i = len(line) - 1
    while i >= 0:
        item = line[i]
        if item == pl:
            nl += 1
        elif item == pr:
            nr += 1
            if nl == nr and pos == -1:
                pos = i
        i -= 1
    return nl,nr,pos



#转化核心函数,当前比较乱,代码重复,一个循环中代码太长了 TODO 
#基本实现就是按照栈处理名称,区分是否class域的函数,忽略.h中已经实现函数{}内部的内容
def h2interface(input_file, output_file = ''):
    """
        kernal function given a .h file
        convert to a .cc one with
        all the functions properly listed
        """
    global pattern_comment

    global abstract_class_out
    global abstract_classes

    #----核心的函数匹配模式
    pattern = re.compile(r"""(^[\s]*)             #leading withe space,we will find and delete after
    		                 ([a-zA-Z~_]            # void int likely the first caracter v or i...
    						.* 
    						[)]                   #we find )
    						#(?!\s*=\s*0)          #if we find = 0  which means pur virtual we will not match after
                            #(?=\s*=\s*0) 
    						(?!.*{)              # we do not want the case int abc() const { return 1;}
                            .*)
    						(;.*)                 #we want to find ; and after for we will replace these later
    						\n$
    						""",re.VERBOSE | re.MULTILINE | re.DOTALL)
    
    #----处理virtual,explicit,friend,static 
    pattern2 = re.compile(r'(virtual\s+|explicit\s+|friend\s+|static\s+)')   
    
    #----开头的空白
    leading_space_pattern = re.compile('(^[\s]*)[a-zA-Z~_]')   
    
    #我们默认函数都会有 如 abc(  abc ( 这样的模式存在
    #但是operator 是个例外,类名要加在operaotr前面，而且不存在上面的模式
    #operator = ()     ClassName::operator = ()
    #pattern_func_name = re.compile(r'([a-zA-Z0-9~_\-]+\s*[(]|operator.*[(])')   
    #难道替换不是仅仅替换括号里面的 而是全部替换? 恩，大括号 必须的 然后用\1没有\0 
    pattern_func_name = re.compile(r'([a-zA-Z0-9~_\-]+\s*|operator.*)[(]') 

    pattern_template = re.compile('^\s*template')
    #pattern_template_end = re.compile('^\s*>\s*$') #TODO why wrong?
    pattern_template_end = re.compile('>\s*$')

    pattern_namespace = re.compile(r'namespace\s+([a-zA-Z0-9~_\-]+)\s*{')       #判断该行是否是 namespace出现 
    #p2 = re.compile(r'class\s*(.*?)\s*{|struct\s*(.*?)\s*{')  
    #.*? 最小匹配  是否class出现,并记录class 名称
    #pattern_class = re.compile(r'^[\s]*(class|struct)\s+([a-zA-Z0-9_\-]+<?)(?!.*;)') 
    #匹配后面的;会造成流程错误,比如下面 gebp_traits;
    #template<typename _LhsScalar, typename _RhsScalar, bool _ConjLhs=false, bool _ConjRhs=false>
    # class gebp_traits;
    # /** \internal \returns b if a<=0, and returns a otherwise. */
    # inline std::ptrdiff_t manage_caching_sizes_helper(std::ptrdiff_t a, std::ptrdiff_t b)
    # {
    #   return a<=0 ? b : a;
    # }
    pattern_class = re.compile(r'^[\s]*(class|struct|interface)\s+([a-zA-Z0-9_\-]+<?)')   
    #modify 09.6.6 可以处理classa a 和 { 不在同一行，但是如果class 后发现;不处理
    #class一定是行开始或者前面可有空白

    pattern_start = re.compile('{')
    pattern_end = re.compile('}')
    
    stack = []                      #----状态可能是normal_now(位于{}中间的时候),class_now,namespace_now
    #stack_class = []                #----存储class name
    global stack_class
    global stack_namespace
    stack_template = []             #----存储template name
    stack_typedef = []              #----存储当前class 作用域下的所有typedef得到的名称,函数返回类型需要
    
    first_convert = True            #是否是第一次生成的实现文件
    
    #--------------------------------------文件处理
    func_sum = 0
    namespace_num = 0
    write_define = 0
    #--------------------------------------------------核心处理循环,逐行处理输入.h文件
    with open(input_file,'r') as f:
        if output_file == '':
            output_file
        f2 = open(output_file,'w')
        m = f.readlines()
        i = 0
        while i < len(m):
            #m[i] = m[i][:m[i].find('//')]
            line = m[i]
            #print line
            #-------------------------------------------判断是注释则略过  re.search(r'^s*$',line) 空行判断
            if re.search(r'^s*$',line) or pattern_comment.search(line): #/n or comment using //
                f2.write(m[i])
                i += 1
                continue
            if re.search('^\s*/[*]', line):              #comment using /*  
                while (not re.search('[*]/\s*$',line)):  # */
                    f2.write(m[i])
                    i += 1
                    line = m[i]
                f2.write(m[i])
                i += 1
                continue
            #---------------------------------------------判断是则define略过
            #define_match = re.search(r'^\s*#define',line)
            define_match = line.lstrip().startswith('#define') 
            if define_match:
                #while re.search(r'^\s*$',line) or re.search(r'\\\s*$', line):
                while line.rstrip().endswith('\\'):
                    f2.write(m[i])
                    i += 1
                    line = m[i]
                f2.write(m[i])
                i += 1
                continue
            #-----------------------------------------------判断是否namespace
            match_namespace = pattern_namespace.search(line)
            two_lines = ''
            if not match_namespace:
                #--尝试看是否两行代表一个namespace
                if i + 1 < len(m) and m[i + 1].lstrip().startswith('{'):
                    two_lines = line.rstrip() + '{'
                    match_namespace = pattern_namespace.search(two_lines)
            if match_namespace:                                   #we face namespace
                stack.append('namespace_now')
                namespace_num += 1
                stack_namespace.append(match_namespace.group(1))
                f2.write(m[i])
                i += 1
                if two_lines != '':
                    f2.write(m[i])
                    i += 1
                continue 


            #----------------------------------------------------判断并处理类里面的typedef
            if (len(stack) > 0 and stack[-1] == 'class_now'):
                pattern_typedef = re.compile(r'typedef\s+.*\s+(.*);')
                match_typedef =  pattern_typedef.search(line)
                if match_typedef:
                    stack_typedef.append(match_typedef.group(1))
            #----------------------------------------------------判断并处理模板情况
            match_template = pattern_template.search(line)
            template_string = ''
            if match_template:
                template_string = line
                find1, find2, pos= count_pair(line, '<', '>', 0, 0)
                while(not find1):
                    #f2.write(m[i])
                    i += 1
                    line = m[i]
                    template_string += line 
                    find1, find2, pos = count_pair(m[i], '<', '>', find1, find2)
                while (pos == -1):
                    #f2.write(m[i])
                    i += 1
                    line = m[i]
                    template_string += line
                    find1, find2, pos = count_pair(m[i], '<', '>', find1, find2)
                #f2.write(m[i])
                i += 1
                line = m[i]
            #--------------------------------------------判断是否是class 或者遇到 { start
            match_class = pattern_class.search(line)  
            match_start = pattern_start.search(line)
            sentence_ends =  line.rstrip().endswith(';')
            if match_class:                  #we face a class 
                if template_string != '':
                    f2.write(template_string)
                    template_string = ''
                if not sentence_ends:
                    stack_template.append(template_string)
                    stack.append('class_now')
                    class_name = match_class.group(2)   #TODO f2.group(1)如果为空则异常
                    #-----------模板类特化或者偏特化的情况 如 class A<u,Node<u> > 为了获得整个名称
                    if '<' in class_name:               
                        k = line.index('<')
                        fit = 1;
                        for l in range(k+1, len(line)):
                            if line[l] == '<':
                                fit += 1
                            if line[l] == '>':
                                fit -= 1
                            if (fit == 0):
                                break
                        class_name += line[k+1:l+1]
                    stack_class.append(class_name)
                    while not match_start:
                        f2.write(m[i])
                        i += 1
                        line = m[i]
                        match_start = pattern_start.search(line)

                    if match_class.group(1) == 'interface':
                        full_class_name = '::'.join(stack_namespace) + '::' + '::'.join(stack_class) 
                        if not full_class_name in abstract_classes:
                            abstract_class_out.write("%s\t%s\n"%(full_class_name, input_file))
                            abstract_classes.add(full_class_name)
                    f2.write(m[i])
                    i += 1
                    continue

            #-------------------------------------------------判断是否是结束符号 }
            match_end = pattern_end.search(line)
            if match_start:
                stack.append('normal_now')
            if match_end:
                #print '$$$', line, len(stack)
                top_status = stack.pop()
                if top_status == 'namespace_now':
                    namespace_num -= 1
                    stack_namespace.pop()
                elif top_status == 'class_now':
                    stack_class.pop()
                    stack_template.pop()
                    stack_typedef = []
            if match_start or match_end:
                f2.write(m[i])   #already done in if match_end
                i += 1
                continue
            #注意我判断是函数只是根据 我看到该行有) 然后 后面有;  important!!
            #------------------------------------------------就像忽略注释一样忽略normal_now状态下的行,因为那是在{}中间的实现
            if len(stack) >0 and stack[-1] == 'normal_now': 
                f2.write(m[i])
                i += 1
                continue
            #---------------------------------------------------------下面我们该处理需要生成实体框架的函数了,
            #------------目前看基本ok，特别复杂代码可能有问题 @TODO 比如 (int a, int b = (3))多出来的()
            #------------另外当前对于类的构造函数是默认输出的，能否也按照函数处理
            #deal with
            #int abc(int a,
            # 		 int b)    #能够处理这种(与)不在同一行的情况
            find1 = re.search('[(]',line)
            if not find1:
                f2.write(m[i])
                i += 1
                continue
            find2 = re.search('[)]',line)
            start_i = i
            space_match = leading_space_pattern.search(line)
            if (find1 and (not find2)):
                i += 1
                line2 = m[i]
                if space_match:
                    line2 = re.sub('^'+space_match.group(1),'',line2)     
                    #注意sub会替换所有的匹配，这里我们只让它替换第一个,count=1，或者对于space 前面加^
                line += line2
                while (i < len(m) and (not re.search('[)]',line2))):
                    i += 1
                    line2 = m[i]
                    line2 = re.sub('^'+space_match.group(1),'',line2)
                    line += line2

            match_start = pattern_start.search(m[i])
            match_end = pattern_end.search(m[i])
            if (match_start):     # like  ) {  or ) {}    int the last line
              if not match_end:
                stack.append('normal_now')
              ii = start_i                #fixed 09.11.17
              while (ii <= i):
                f2.write(m[ii])
                ii += 1
              i += 1
              continue
 
            #here we do the kernel sub  #--------------------------------如果找到,先进行了替换abc();->abc(){}
            #@TODO @? this is important without these will -> #if __GNUC__ > 3 || defined(WIN32)  -> #if __GNUC__ > 3 || defined(WIN32); as function..
            #(line,match) = pattern.subn(r'\2 \n{\n\n}\n\n',line)  
            no_mark = 0
            func_line_temp = line  
            #line2 = line  
            if not re.search(';\s*$', line):    #默认情况下将加上;使得它可以被转移到实现文件中
                line = line.rstrip()
                line += ';\n'
                no_mark = 1
                func_line_temp = line
            if (no_mark) and (not re.search(r'^\s*{\s*$', m[i+1])): 
                ii = start_i   #Temp modified is it ok?
                while (ii <= i):
                  f2.write(m[ii])
                  ii += 1
                i += 1
                continue
            (line,match) = pattern.subn(r'\2\n',line)  #key sub!!! 比如最后的; 去掉void play(); -> void play()
            #print '^^^', line
            #print '[' + line + ']' + '(' +  str(match) + ')'
            #temp add 尝试兼容返回值在单独一行的情况
            if re.search(r'^\s*(inline)?\s*[a-zA-Z0-9_]+\s*$', m[start_i - 1]):
                line = m[start_i - 1] + line
            line = line.lstrip() 
            #match = 1
            if (not match):   
                f2.write(m[i])   
                i += 1
                continue
            #print "###", line
            #-------------------------------------------------------------OK,找到了函数,下面进行处理后输出
            friend_match = re.search('friend ',line)
            #line = pattern2.sub('',line)            #--------------------delete virtural explict friend! 由于现在只是输出interface 所以不去掉！
            func_name = ''
            template_line = ''
            if len(stack_class) > 0 and not friend_match :  #-----类成员函数class status if friend we will not add class name
                line = template_line + template_string +  line;     
                #line = template_line + template_string +  line2;        #must use line2..   
                func_name = re.search('^.*\)',line,re.MULTILINE|re.DOTALL).group()
            else:                  #--------------------------------普通函数(非类成员函数)的情况!
                stack_template.append(template_string)
                if  (stack_template[-1] != ''):
                    template_line = re.sub(r'\s*template','template',stack_template[-1])
                    #------------------delete < class T = a, class U = A(3)> -> <class T, class U>
                    template_line = re.sub('\s*=.*>(\s*)$',r'>\1',template_line) #代码重复,TODO以后整合 
                    template_line = re.sub(r'\s*=.*,',',',template_line)
                    template_line = re.sub(r'\s*=.*','',template_line)
                line = template_line + line
                #line = template_line + line2
                stack_template.pop()
                func_name = re.search('^.*\)',line,re.MULTILINE|re.DOTALL).group()
            #--------------------------------------------------------把已经在头文件定义的代码也拷贝过去
            content = ''
            lmatch = 0
            #特殊的写法对于{单独一行的情况把其上函数在头文件定义的代码也拷贝过去
            if i < len(m) - 1 and re.search(r'^\s*{\s*$', m[i+1]):               
                i = i + 2
                lmatch = 1
                while (lmatch != 0):
                    if (not pattern_comment.search(m[i])) and re.search('{', m[i]): #唯一可能的问题是注释 //  if (n > 1) {i
                        lmatch += 1
                    if (not pattern_comment.search(m[i])) and re.search(r'}',m[i]):
                        lmatch -= 1
                    if space_match:
                        content += re.sub('^'+space_match.group(1),'',m[i])
                    i += 1
                i -= 1
						#-------------------------------------------------------------------------加上上面的注释也拷贝过去                       
            #----------------------------------------------如果函数已经在实现文件中存在,不输出
            #@NOTICE 查看结果debug重要的打印
            #print '----', line #完整的函数 带有上面template
            #print '####',func_line_temp #只有函数 不带template,
            line = pyplusplus_hack(line, content).strip() + ';\n'
            f2.write(line)
            i += 1  #-----------------------------------------------------------------------next line处理下一行
    #------------------------------loop done 处理结束 
    #print('Added %d functions'%func_sum)
    f2.close()


#-----------------------------------------------------------user input
def main(argv):    
    global input_file    
    try:                                
        opts, args = getopt.getopt(argv, "h", ["help"]) 
    except getopt.GetoptError:           
        print(usage.__doc__) 
        sys.exit(2)

    if len(opts) > 0:
        for o, a in opts: 
            if o in ("-h", "--help"): 
                print(usage.__doc__) 
                sys.exit()
    if len(args) > 0:
        input_file = args[0]
        output_file = input_file.replace('.h', '.i')
        if len(args) > 1:
            output_file = args[1]
        h2interface(input_file, output_file)
    else:
        print(usage.__doc__)
        sys.exit()


if __name__ == "__main__":
    main(sys.argv[1:])
