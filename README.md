# MELT是一个机器学习包，主要特色是丰富的实验特性支持，注重训练速度优化，它的设计目标
## 方便的机器学习各种算法在各种数据平台(单机,mpi, hadoop,gpu)的实验。  
## 提供丰富的实验支持和机器学习数据分析支持(MELT本身的支持及多个外围脚本支持)  
## 训练时候的特征动态选择 –incl   -excl支持  
## 多种normalizer,calibrator可供选择(优化速度的minmax normalizer，还提供gauss和bin normalizer)  
## Python接口的支持  
## 特征重要度打印，如GBDT,LinearSVM均支持   
## GBDT模型的单次预测重要度展示，gbdt树模型的图片打印，模型输出到C++/PYTON/PHP代码  
## 迭代模型如GBDT，LinearSVM均支持迭代过程中的validating，early stop  
## Predictor内部整合normalizer和calibrator更加方便使用。   
## 良好的扩展性 支持其它开源线性模型的引入（sofia,liblinear,libsvm,lightgbm）
## 加入你自己的模型  
## 场景及特性 
通过在命令行执行melt命令完成单机实验  
标配设置:   交叉验证, 训练+测试, 训练 + 测试 + 预测(线上), 特征选择(指定部分特征，或指定去掉部分特征  
任务： 二元分类，多分类，回归，排序  
Learners:   boosted trees, SVMs, logistic regression, stochastic gradient descent, perceptron, VW, bagging, etc.  
MPI:  大规模数据并行算法  
参数扫描(Parameter sweeps):   单机的参数扫描及hadoop，mpi版本参数扫描.  
提供数据分析对比支持  
数据输入格式建议采用melt默认的稠密或者稀疏表示格式，同时也直接LibSVM格式的输入  

# 使用melt进行LightGBM训练与上线 

# 使用示例  
完整环境在lightgbm路径下 直接使用lightgbm训练参考lightgbm-train-test.sh   
使用melt调用lightgbm训练参考 run-rank.sh run-regression.sh   
也可以使用 sh run.sh 将会执行3个训练实验，和一个python接口的预测/debug信息展示 
1. melt train_data -c tt -test test_data -cl lightgbm -cls lightgbm-rank.conf 
-cl 表示classifier -cl light | lgbm | gbm | lg 都表示使用lightgbm处理   
-cls classifierSetting所有非melt内部算法的第三方都通过 -cls 设置第三方库自身的命令行参数  
2. melt train_data -c tt -test test_data -cl lightgbm -cls lightgbm-rank.conf,num_trees=200   
3. melt train_data -c tt -test test_data -cl lightgbm -cls lightgbm-rank.conf,num_trees=200 -incl i:33-55   
这相当于调用 lightgbm config=lightgbm-rank.conf以及 lightgbm config=lightgbm-rank.conf num_tress=200    
4. melt train_data -c tt -test test_data -cl lightgbm -cls lightgbm-regression.conf,num_trees=200 -incl i:33-55 --metric rank   
这里使用regression算法，但是仍然按照rank评估NDCG ,注意label需要是0-4的整数，如果label 有>4  需要手动设置 -gains    
如果lable是浮点数那么rank评估值计算top1准确率    
5.  melt train_data -cl lightgbm -cls lightgbm-regression.conf   
默认command是交叉验证，这里进行5交叉    
conf的写法参考 [https://github.com/Microsoft/LightGBM/blob/master/examples/lambdarank/train.conf]( https://github.com/Microsoft/LightGBM/blob/master/examples/lambdarank/train.conf)  
# 使用melt的和直接使用LightGBM的区别  
- melt对LightGBM做了封装，也就是说melt读取文本文件生成内部数据结构再转换进行LightGBM的训练
- 和直接使用LightGBM的区别  
1. 性能损失 如果不是超大数据可以忽略不计，melt的读取也非常快，转换代价基本可以忽略  
2. 大文件处理，melt目前采用全部读入内存的方式，因此如果是超出内存大小的数据，不能使用melt的方式  
   可以直接用lightgbm训练配置文件设置  
```
two_round, default=false, type=bool, alias=two_round_loading,use_two_round_loading
by default, LightGBM will map data file to memory and load features from memory. This will provide faster data loading speed. But it may out of memory when the data file is very big.
set this to true if data file is too big to fit in memory.
```  
3. 结果diff，结果的diff主要原因是LightGBM的分桶利用了部分数据默认50000样本随机，这部分随机和melt的instances随机逻辑略有不同
   但是不影响模型训练效果，diff源自随机性。  
   melt如果设置随机种子-rs为固定数值，lightgbm采用其配置文件默认的随机设置,不进行feature和bagging数据采样，那么每次训练结果保持不变。
4. 局限，melt暂时不支持多分类，lightgbm本身已经支持多分类和初始score输入。  
# 使用melt的收益
使用melt训练的主要好处在易用性，体现在  
## 多种输入格式的支持  
1. melt同lightgbm一样支持libsvm,tsv,csv格式，同时melt也直接支持malloc rank格式的样本(无需其他设置直接解析malloc rank格式数据) 
2. lightgbm的rank需要样本提供query文件，并且保证数据文件要按照query排序  
3. melt数据格式可以通过 --name 0,1 -group 0 来表示前两列对应是名称，第一列是groupKey/query 或者--rank=1等价(-name 0,1 -group 0)   
4. melt支持内部默认的dense和sparse数据格式，其中sparse数据格式类似libsvm但是在label后面的第一列表示特征数目
## 更好的支持特征命名  
  melt可以通过以下几种方式提供特征命名信息
1. --header=1 确认输出有header信息 如   query,doc,label,name1,name2,name3....
2. 采用默认可解析header，样本数据第一行#开头   如 #query,doc,label,name1,name2..
3. 在当前路径下提供feature_name.txt里面的数据格式  
name1   #comment  
name2   #comment  
...  
## 特征匹配的支持  
  lightgbm支持在conf中设置要去掉的特征，但是没有melt的特征匹配完善    
  melt提供更方便的特征匹配支持 -incl, -excl 
1. -incl i:0-44 表示 只使用0-44 45个特征
2. -excl i:3-22,50-64 表示去掉3-22和50-64的特征
3. -incl ^idf  表示只使用特征名称是idf开头的特征
4. -exc new,old 表示去掉特征名称匹配到new或者old的特征
5. -incl ^idf -excl new,old 表示只使用idf开头的特征，同时再去掉这里面能够匹配到new或者old的特征  
melt处理机制会将不使用的特征对应的全部置为0，而lightgbm转换后再处理的时候，会默认去掉所有样本对应特征值一样的特征不参与训练(但是仍然特征索引占位)
## 复用melt的处理框架  
melt支持train,test,train-test,cross validation等这些都可以直接复用，lightgbm目前还不支持交叉验证    
另外方便在相同环境测试不同算法效果，melt同时封装了liblinear,libsvm,vw,sofia-ml第三方算法库，同时自带linearSVM和gbdt二分类回归算法  
melt另外支持一些比较有用的模式
1. melt data_file -c si  #展示数据文件信息
```
mlt train -c tt --rank=1 -c si
I1118 07:49:16.736133  7969 Melt.h:59] _cmd.randSeed --- [1649160588]
I1118 07:49:16.736424  7969 Melt.h:1360] omp_get_num_procs() --- [12]
I1118 07:49:16.736796  7969 Melt.h:1362] gezi::get_num_threads() --- [12]
I1118 07:49:16.736873  7969 Melt.h:1365] commandStr --- [si]
I1118 07:49:16.736915  7969 InstanceParser.cpp:63] Using rank format data and not set --group by default will use first column as groupKey
I1118 07:49:16.736991  7969 time_util.h:107] ParseInputDataFile started
I1118 07:49:16.986577  7969 InstanceParser.h:541] _labelIdx --- [2]
I1118 07:49:16.986609  7969 InstanceParser.h:600] Try load feature names from feature_name.txt
I1118 07:49:16.987864  7969 InstanceParser.h:790]  CreateInstancesFromSparseFormat
I1118 07:49:17.792853  7969 InstanceParser.h:1091] kFormatNames[_fileFormat] --- [sparse]
I1118 07:49:17.792888  7969 InstanceParser.h:1092] _instances.NumFeatures() --- [559]
I1118 07:49:17.792896  7969 InstanceParser.h:1093] _instances.Count() --- [306886]
I1118 07:49:17.796424  7969 InstanceParser.h:1095] positiveCount --- [284624]
I1118 07:49:17.796463  7969 InstanceParser.h:1097] positiveRatio --- [0.9274584047496465]
I1118 07:49:17.796489  7969 InstanceParser.h:1103] numLabels --- [5]
I1118 07:49:17.802233  7969 InstanceParser.h:1111] Label:0 Count:22262
I1118 07:49:17.802260  7969 InstanceParser.h:1111] Label:1 Count:164836
I1118 07:49:17.802266  7969 InstanceParser.h:1111] Label:2 Count:38070
I1118 07:49:17.802273  7969 InstanceParser.h:1111] Label:3 Count:52331
I1118 07:49:17.802278  7969 InstanceParser.h:1111] Label:4 Count:29387
I1118 07:49:17.802284  7969 InstanceParser.h:1118] _instances.NumGroups() --- [43150]
I1118 07:49:17.806154  7969 InstanceParser.h:1123] denseCount -- [0] denseRatio -- [0]
I1118 07:49:17.806185  7969 InstanceParser.h:1124] IsDenseFormat() --- [0]
I1118 07:49:17.806197  7969 InstanceParser.h:1125] _instances.schema.tagNames:0 1 
I1118 07:49:17.806205  7969 InstanceParser.h:1126] _instances.schema.attributeNames:
I1118 07:49:17.806212  7969 InstanceParser.h:1127] _instances.schema.groupKeys:0 
I1118 07:49:17.806218  7969 InstanceParser.h:1128] _instances.schema.featureNames --- 559
I1118 07:49:17.806227  7969 InstanceParser.h:1128] 549       f549:new_idf_ranktext_vip
I1118 07:49:17.806234  7969 InstanceParser.h:1128] 550       f550:new_idf_ranktext_simid
I1118 07:49:17.806241  7969 InstanceParser.h:1128] 551       f551:new_idf_query
I1118 07:49:17.806246  7969 InstanceParser.h:1128] 552       f552:new_idf_query_simid
I1118 07:49:17.806279  7969 InstanceParser.h:1128] 553       f553:new_idf_query_ematch
I1118 07:49:17.806285  7969 InstanceParser.h:1128] 554       f554:new_idf_query_top1ematch
I1118 07:49:17.806290  7969 InstanceParser.h:1128] 555       f555:new_idf_query_top1match
I1118 07:49:17.806296  7969 InstanceParser.h:1128] 556       f556:new_tfidf_tf
I1118 07:49:17.806301  7969 InstanceParser.h:1128] 557       f557:new_tfidf_ranktext_all_simid
I1118 07:49:17.806306  7969 InstanceParser.h:1128] 558       f558:new_tfidf_ranktext_vip
I1118 07:49:17.806313  7969 InstanceParser.h:1129] _instances.schema.featureNames.NumFeatures() --- [559]
I1118 07:49:17.806319  7969 InstanceParser.h:1130] _instances.schema.featureNames.NumFeatureNames() --- [559]
I1118 07:49:17.806332  7969 time_util.h:118] ParseInputDataFile finished using:       [1069.31 ms] (1.06931 s)

```
2. melt data_file -c fss #fss表示featureStatusShow

```
mlt train -c tt --rank=1 -c fss
I1118 07:54:50.291501  8197 Melt.h:59] _cmd.randSeed --- [3262480143]
I1118 07:54:50.291765  8197 Melt.h:1360] omp_get_num_procs() --- [12]
I1118 07:54:50.292135  8197 Melt.h:1362] gezi::get_num_threads() --- [12]
I1118 07:54:50.292209  8197 Melt.h:1365] commandStr --- [fss]
I1118 07:54:50.292246  8197 time_util.h:107] FeatureStatus! -vl >= 0 to print warning of possible no use features started
I1118 07:54:50.292309  8197 InstanceParser.cpp:63] Using rank format data and not set --group by default will use first column as groupKey
I1118 07:54:50.292419  8197 time_util.h:107] ParseInputDataFile started
I1118 07:54:50.540861  8197 InstanceParser.h:541] _labelIdx --- [2]
I1118 07:54:50.540894  8197 InstanceParser.h:600] Try load feature names from feature_name.txt
I1118 07:54:50.542520  8197 InstanceParser.h:790]  CreateInstancesFromSparseFormat
I1118 07:54:51.349625  8197 time_util.h:118] ParseInputDataFile finished using:       [1057.17 ms] (1.05716 s)
Finished [ 306886 ] (0.186903 s)100% |*******************************************|
I1118 07:54:51.536661  8197 FeatureStatus.h:159] Write result to train.featurestatus
I1118 07:54:51.536783  8197 FeatureStatus.h:161] Write csv result to train.featurestatus.csv
65:f65:title_ner_MDL is always taking value: [0:0]                           |
66:f66:title_ner_PDT is always taking value: [0:0]
68:f68:title_pre_is_。 is always taking value: [0:0]                         |
69:f69:title_avg_pre_is_。 is always taking value: [0:0]
70:f70:title_pre_is_、 is always taking value: [0:0]
71:f71:title_avg_pre_is_、 is always taking value: [0:0]
78:f78:title_pre_is_” is always taking value: [0:0]                         |
79:f79:title_avg_pre_is_” is always taking value: [0:0]                     |
142:f142:title_post_is_。 is always taking value: [0:0]                       |
143:f143:title_avg_post_is_。 is always taking value: [0:0]
144:f144:title_post_is_、 is always taking value: [0:0]
145:f145:title_avg_post_is_、 is always taking value: [0:0]
152:f152:title_post_is_” is always taking value: [0:0]                       |
153:f153:title_avg_post_is_” is always taking value: [0:0]
281:f281:desc_ner_MDL is always taking value: [0:0]*****                      |
282:f282:desc_ner_PDT is always taking value: [0:0]
284:f284:desc_pre_is_。 is always taking value: [0:0]
285:f285:desc_avg_pre_is_。 is always taking value: [0:0]
286:f286:desc_pre_is_、 is always taking value: [0:0]****                     |
287:f287:desc_avg_pre_is_、 is always taking value: [0:0]
294:f294:desc_pre_is_” is always taking value: [0:0]****                     |
295:f295:desc_avg_pre_is_” is always taking value: [0:0]
358:f358:desc_post_is_。 is always taking value: [0:0]********                |
359:f359:desc_avg_post_is_。 is always taking value: [0:0]
360:f360:desc_post_is_、 is always taking value: [0:0]
361:f361:desc_avg_post_is_、 is always taking value: [0:0]
368:f368:desc_post_is_” is always taking value: [0:0]*********               |
369:f369:desc_avg_post_is_” is always taking value: [0:0]*****               |
465:f465:click_ner_MDL is always taking value: [0:0]******************        |
466:f466:click_ner_PDT is always taking value: [0:0]
Finished [ 559 ] (0.008675 s)100% |*******************************************|
I1118 07:54:51.681234  8197 time_util.h:118] FeatureStatus! -vl >= 0 to print warning of possible no use features finished using: [1388.95 ms] (1.38895 s)
```
查看生成的feature status文件
```
more train.featurestatus
FeatureName	Mean	PosMean	NegMean	PosMin	NegMin	PosMax	NegMax	Var	PosVar	NegVar
f0:title_ok	mean:0.705236	min:0	max:1	posMean:0.708858	negMean:0.658926	posMin:0	negMin:0	posMax:1	negMax:1	var:0.207879	posVar:0.206379	negVar:0.224753	
f1:title_num_matches	mean:1.1761	min:0	max:54	posMean:1.19418	negMean:0.945018	posMin:0	negMin:0	posMax:54	negMax:17	var:2.09061	posVar:2.15983	negVar:1.14805	
f2:title_num_distinct_matches	mean:1.0452	min:0	max:47	posMean:1.06156	negMean:0.835999	posMin:0	negMin:0	posMax:47	negMax:11	var:1.34379	posVar:1.38599	negVar:0.757029	
f3:title_book_count	mean:0.0111703	min:0	max:10	posMean:0.011654	negMean:0.00498607	posMin:0	negMin:0	posMax:10	negMax:6	var:0.0266475	posVar:0.0280664	negVar:0.008465
32	
f4:title_num_distinct_matches_weight	mean:2.38964	min:0	max:99.7132	posMean:2.43418	negMean:1.82024	posMin:0	negMin:0	posMax:99.7132	negMax:25.77	var:8.10253	posVar:8.35914	negVar:4.47227	
f5:title_num_strict_exact_matches	mean:0.0215194	min:0	max:6	posMean:0.0221942	negMean:0.0128919	posMin:0	negMin:0	posMax:6	negMax:2	var:0.0252729	posVar:0.0261918      negVar:0.013445	

```
## 更好的特征重要度支持
### lightgbm会在生成的模型文件最后展示特征重要度，这里的特征重要度是用特征在模型生成的所有树中的出现次数来表示的
```
feature importances:
f482:old_examplar=302
f480:old_Term_freq_weight=232
f471:total_wordrank=208
f468:keyword_length=156
f481:old_Keyword_length=146
f548:new_idf_ranktext_all_simid=133
f535:old_ner_PER=132
f547:new_tuwen_showandtell_char=132
f546:new_tuwen_showandtell=102
f550:new_idf_ranktext_simid=92
f475:old_Title_freq=69
f542:new_tuwen_bow=63
f453:click_startswith_wordrank=61
f543:new_tuwen_rnn=49
f479:old_Clickquery_freq=43
f271:desc_ner_PER=38
f55:title_ner_PER=38
f53:title_sum_texts_weight=37
f538:old_ner_BRD=37
f16:title_startswith_wordrank=36
f48:title_avg_offset=29
```
### 使用melt训练会在产出的模型路径默认./model文件夹下面提供model.featureGain.txt，提供了按照特征的分裂收益累加计算的特征重要度信息，并且做了归一化处理
```
more ./model/model.featureGain.txt 
0:f471:total_wordrank                           1
1:f546:new_tuwen_showandtell                    0.718685
2:f480:old_Term_freq_weight                     0.619463
3:f482:old_examplar                             0.561995
4:f481:old_Keyword_length                       0.524525
5:f548:new_idf_ranktext_all_simid               0.443716
6:f468:keyword_length                           0.427941
7:f542:new_tuwen_bow                            0.404851
8:f535:old_ner_PER                              0.364947
9:f543:new_tuwen_rnn                            0.356774
10:f550:new_idf_ranktext_simid                  0.227524
11:f547:new_tuwen_showandtell_char              0.196125
```
### melt支持单次预测特征重要度的展示
melt训练过程 使用参数--wr=1会打印预测结果到./result/0.inst.txt（可以通过--rf a.txt配置为打印到a.txt)  
默认会设置 --writeDebug=1 展示debug信息也就是特征预测重要度信息，默认展示top5可以通过-numDebugs=10来修改为top10
```
mlt train -c tt -t test --rank=1 -cl lgb -cls lightgbm-rank.conf --wr=1 --rf result.txt^C
gezi@localhost:~/work/keywords/train/v2/zhongce/text$ more ./result.txt 
Instance	GroupKey	True	Predicted	NDCG@1	NDCG@2	NDCG@3	DCG@1	DCG@2	DCG@3	MaxDCG@1	MaxDCG@2	MaxDCG@3	Debug
3448460368,430059535|总经理	3448460368,430059535	1	-0.654047	100	100	92.8479	21.6404	35.294	37.4581	21.6404	35.294	40.3434	f482:old_examplar:-2.6698:-2,f480:old_Term_freq_weight:-2.40761:1,f547:new_tuwe
n_showandtell_char:0.889376:0.521313,f546:new_tuwen_showandtell:0.574118:0.50291,f543:new_tuwen_rnn:0.567754:0.696085
3448460368,430059535|江南汽车	3448460368,430059535	2	-1.13479	100	100	92.8479	21.6404	35.294	37.4581	21.6404	35.294	40.3434	f482:old_examplar:-2.28336:-2,f480:old_Term_freq_weight:-1.95214:1,f546
:new_tuwen_showandtell:-1.71251:0.267359,f548:new_idf_ranktext_all_simid:1.61797:15512,f543:new_tuwen_rnn:-1.02027:-0.0176351
3448460368,430059535|众泰	3448460368,430059535	2	-1.47698	100	100	92.8479	21.6404	35.294	37.4581	21.6404	35.294	40.3434	f480:old_Term_freq_weight:-1.4014:1,f546:new_tuwen_showandtell:-1.38943:0.27982
6,f543:new_tuwen_rnn:-1.09378:-0.0204482,f482:old_examplar:0.693243:-2,f542:new_tuwen_bow:-0.493574:0.275686
3448460368,430059535|吴建中	3448460368,430059535	3	-0.150239	100	100	92.8479	21.6404	35.294	37.4581	21.6404	35.294	40.3434	f482:old_examplar:-3.1043:-2,f480:old_Term_freq_weight:-2.60871:1,f548:new_idf_
ranktext_all_simid:1.05964:9867,f535:old_ner_PER:0.649271:1,f546:new_tuwen_showandtell:0.609997:0.56614
3448460368,430059535|应建仁	3448460368,430059535	3	-0.352779	100	100	92.8479	21.6404	35.294	37.4581	21.6404	35.294	40.3434	f548:new_idf_ranktext_all_simid:2.65718:197,f482:old_examplar:-2.30219:-2,f480:
```
单次预测特征重要度的计算是通过计算特征在预测路径分裂前后的差值累加得到的。  
## melt支持无依赖的c++接口预测上线
melt训练 -c train模式 设置 --mcustorm=1 则生成的  model.bin文件(默认在 ./model路径下 可以通过 -m 修改)  可以直接利用无编译依赖的GbdtPredictor.h头文件读取预测,具体参考工具包inference目录
## melt提供预测和单次预测特征重要度的python接口 

### melt的python预测接口
#### 统一的python接口(libmelt)
不仅仅限于gbdt，melt支持的其它模型如线性svm模型liblinear，同样可以只用统一的python预测接口  
注意--mcustom=1生成的模型 LoadPredictor(string path, string modelName = "", bool isText = false, bool useCustomModel = false)  
需要设置 useCustomModel=True
```
In [1]: import gezi.nowarning

In [2]: from libmelt import PredictorFactory, Vector

In [3]: predictor = PredictorFactory.LoadPredictor('./model/')
WARNING: Logging before InitGoogleLogging() is written to STDERR
I1118 09:41:41.317528 25865 LoadSave.h:32] gbdtRanking try load from ./model/

In [4]: predictor.Predict(Vector('21:12.5,33:22.3'))
Out[4]: -1.207006727

In [5]: predictor = PredictorFactory.LoadPredictor('./LightGBM_model.txt')
W1118 09:42:03.366194 25865 PredictorFactory.cpp:181] Can not get model info, so judge it as predictor of default type: lambdarank
I1118 09:42:03.366287 25865 LoadSave.h:55] gbdtRanking try load as text from ./LightGBM_model.txt
I1118 09:42:03.366322 25865 GbdtPredictor.h:348] Loading from text file ./LightGBM_model.txt of LightGBM format
I1118 09:42:03.367594 25865 GbdtPredictor.h:240] numFeatures --- [559]
I1118 09:42:03.381628 25865 GbdtPredictor.h:310] _trees.size() --- [100]
I1118 09:42:03.382040 25865 GbdtPredictor.h:332] Per_feature_gain print top 10 -vl 0 will print only top 10, -vl 1 will print top 50, -vl 2 will print all
I1118 09:42:03.382071 25865 Predictor.h:806] Try load feature names from ./feature_name.txt
0:f471:total_wordrank                           1
1:f546:new_tuwen_showandtell                    0.712731
2:f480:old_Term_freq_weight                     0.613357
3:f482:old_examplar                             0.557893
4:f481:old_Keyword_length                       0.516144
5:f548:new_idf_ranktext_all_simid               0.421158
6:f468:keyword_length                           0.39352
7:f542:new_tuwen_bow                            0.389431
8:f535:old_ner_PER                              0.370457
9:f543:new_tuwen_rnn                            0.361138

In [6]: predictor.Predict(Vector('21:12.5,33:22.3'))
Out[6]: -1.207006727
```
#### gbdt专用python接口(libgbdt)
与统一接口类似，用法见下面单次特征重要度预测
### melt的python单次预测特征重要度接口 
```
In [2]: from libgbdt import GbdtPredictor, Vector

In [3]: predictor = GbdtPredictor('./LightGBM_model.txt')
WARNING: Logging before InitGoogleLogging() is written to STDERR
I1118 10:42:01.142372  3170 LoadSave.h:55] gbdt try load as text from ./LightGBM_model.txt
I1118 10:42:01.142452  3170 GbdtPredictor.h:360] Loading from text file ./LightGBM_model.txt of LightGBM format
I1118 10:42:01.143805  3170 GbdtPredictor.h:245] numFeatures --- [559]
I1118 10:42:01.157310  3170 GbdtPredictor.h:322] _trees.size() --- [100]
I1118 10:42:01.157353  3170 Predictor.h:806] Try load feature names from ./feature_name.txt
I1118 10:42:01.158872  3170 GbdtPredictor.h:344] Per_feature_gain print top 10 -vl 0 will print only top 10, -vl 1 will print top 50, -vl 2 will print all
0:f471:total_wordrank                           1
1:f546:new_tuwen_showandtell                    0.712731
2:f480:old_Term_freq_weight                     0.613357
3:f482:old_examplar                             0.557893
4:f481:old_Keyword_length                       0.516144
5:f548:new_idf_ranktext_all_simid               0.421158
6:f468:keyword_length                           0.39352
7:f542:new_tuwen_bow                            0.389431
8:f535:old_ner_PER                              0.370457
9:f543:new_tuwen_rnn                            0.361138

In [4]: fe = Vector('0:1,1:1,2:1,4:1.77017,11:1,18:0.122528,19:1.34781,20:1,21:0.122528,22:1.34781,23:1,24:1,31:0.122528,32:1.34781,33:1,34:0.122528,35:1.34781,36:1.77017,43:0.216896,44:2.38586,45:1,46:0.122528,47:1.34781,48:13,50:1,51:1,52:1,53:1.77017,128:1,129:1,200:1,201:1,468:6,469:3,470:1,471:0.122528,472:1.77017,473:1,474:1,475:1,480:1,481:3,482:-2,521:1.77017,542:0.597565,543:0.696085,544:0.609126,545:0.702186,546:0.50291,547:0.521313,548:3.7336e+06,549:699743,550:511960,551:4,552:4,555:2,556:2,557:30.2658,558:26.9169')

In [5]: predictor.Predict(fe)
Out[5]: -0.6264205382000001

In [6]: print '\n'.join(predictor.SortedGainStrVec(fe, topNum=5))
f480:old_Term_freq_weight:-2.70486:1
f482:old_examplar:-2.59336:-2
f547:new_tuwen_showandtell_char:0.7709:0.521313
f546:new_tuwen_showandtell:0.520602:0.50291
f468:keyword_length:0.431322:6

```
## c++二进制的debug工具 gbdt_predict
在tools路径下 
```
gbdt_predict -m LightGBM_model.txt -f '0:1,1:1,2:1,4:1.77017,11:1,18:0.122528,19:1.34781,20:1,21:0.122528,22:1.34781,23:1,24:1,31:0.122528,32:1.34781,33:1,34:0.122528,35:1.34781,36:1.77017,43:0.216896,44:2.38586,45:1,46:0.122528,47:1.34781,48:13,50:1,51:1,52:1,53:1.77017,128:1,129:1,200:1,201:1,468:6,469:3,470:1,471:0.122528,472:1.77017,473:1,474:1,475:1,480:1,481:3,482:-2,521:1.77017,542:0.597565,543:0.696085,544:0.609126,545:0.702186,546:0.50291,547:0.521313,548:3.7336e+06,549:699743,550:511960,551:4,552:4,555:2,556:2,557:30.2658,558:26.916'
I1118 10:00:56.809183 28321 LoadSave.h:55] gbdt try load as text from LightGBM_model.txt
I1118 10:00:56.809365 28321 GbdtPredictor.h:348] Loading from text file LightGBM_model.txt of LightGBM format
I1118 10:00:56.810501 28321 GbdtPredictor.h:240] numFeatures --- [559]
I1118 10:00:56.823609 28321 GbdtPredictor.h:310] _trees.size() --- [100]
I1118 10:00:56.823645 28321 Predictor.h:806] Try load feature names from ./feature_name.txt
I1118 10:00:56.824920 28321 GbdtPredictor.h:332] Per_feature_gain print top 10 -vl 0 will print only top 10, -vl 1 will print top 50, -vl 2 will print all
0:f471:total_wordrank                           1
1:f546:new_tuwen_showandtell                    0.712731
2:f480:old_Term_freq_weight                     0.613357
3:f482:old_examplar                             0.557893
4:f481:old_Keyword_length                       0.516144
5:f548:new_idf_ranktext_all_simid               0.421158
6:f468:keyword_length                           0.39352
7:f542:new_tuwen_bow                            0.389431
8:f535:old_ner_PER                              0.370457
9:f543:new_tuwen_rnn                            0.361138
I1118 10:00:56.825709 28321 gbdt_predict.cc:47] predictorName: -- Notice for non gbdt binary classification model, proababilty is meaning less
I1118 10:00:56.825742 28321 gbdt_predict.cc:52] predict -- [-0.626421] probablity -- [-0.626421]
I1118 10:00:56.826164 28321 gbdt_predict.cc:78] Per feature gain for this predict, sortByGain: 1
0:f480:old_Term_freq_weight                     	-2.70486	480:1
1:f482:old_examplar                             	-2.59336	482:-2
2:f547:new_tuwen_showandtell_char               	0.7709	547:0.521313
3:f546:new_tuwen_showandtell                    	0.520602	546:0.50291
4:f468:keyword_length                           	0.431322	468:6
5:f545:new_tuwen_rnn_bi                         	0.385684	545:0.702186
6:f543:new_tuwen_rnn                            	0.382433	543:0.696085
7:f542:new_tuwen_bow                            	0.349407	542:0.597565
8:f555:new_idf_query_top1match                  	0.314287	555:2
9:f548:new_idf_ranktext_all_simid               	-0.282919	548:3.7336e+06
10:f47:title_avg_normed_wordrank_weight         	0.271767	47:1.34781
11:f550:new_idf_ranktext_simid                  	-0.204529	550:511960
12:f45:title_avg_matches_weight                 	0.194325	45:1
13:f34:title_avg_wordrank_real                  	0.177239	34:0.122528
14:f257:desc_num_start_matches_weight           	0.176843	257:0
15:f554:new_idf_query_top1ematch                	0.161948	554:0
16:f43:title_wordrank_weight                    	0.160418	43:0.216896
17:f46:title_avg_wordrank_weight                	0.134556	46:0.122528
18:f469:keyword_unicode_length                  	-0.132079	469:3
```
展示第一棵树的预测路径
```
gbdt_predict -m LightGBM_model.txt -t 0 -f '0:1,1:1,2:1,4:1.77017,11:1,18:0.122528,19:1.34781,20:1,21:0.122528,22:1.34781,23:1,24:1,31:0.122528,32:1.34781,33:1,34:0.122528,35:1.34781,36:1.77017,43:0.216896,44:2.38586,45:1,46:0.122528,47:1.34781,48:13,50:1,51:1,52:1,53:1.77017,128:1,129:1,200:1,201:1,468:6,469:3,470:1,471:0.122528,472:1.77017,473:1,474:1,475:1,480:1,481:3,482:-2,521:1.77017,542:0.597565,543:0.696085,544:0.609126,545:0.702186,546:0.50291,547:0.521313,548:3.7336e+06,549:699743,550:511960,551:4,552:4,555:2,556:2,557:30.2658,558:26.916' 
I1118 10:03:04.561481 28535 LoadSave.h:55] gbdt try load as text from LightGBM_model.txt
I1118 10:03:04.561647 28535 GbdtPredictor.h:348] Loading from text file LightGBM_model.txt of LightGBM format
I1118 10:03:04.562968 28535 GbdtPredictor.h:240] numFeatures --- [559]
I1118 10:03:04.576159 28535 GbdtPredictor.h:310] _trees.size() --- [100]
I1118 10:03:04.576195 28535 Predictor.h:806] Try load feature names from ./feature_name.txt
I1118 10:03:04.577467 28535 GbdtPredictor.h:332] Per_feature_gain print top 10 -vl 0 will print only top 10, -vl 1 will print top 50, -vl 2 will print all
0:f471:total_wordrank                           1
1:f546:new_tuwen_showandtell                    0.712731
2:f480:old_Term_freq_weight                     0.613357
3:f482:old_examplar                             0.557893
4:f481:old_Keyword_length                       0.516144
5:f548:new_idf_ranktext_all_simid               0.421158
6:f468:keyword_length                           0.39352
7:f542:new_tuwen_bow                            0.389431
8:f535:old_ner_PER                              0.370457
9:f543:new_tuwen_rnn                            0.361138
I1118 10:03:04.578189 28535 gbdt_predict.cc:47] predictorName: -- Notice for non gbdt binary classification model, proababilty is meaning less
I1118 10:03:04.578217 28535 gbdt_predict.cc:52] predict -- [-0.626421] probablity -- [-0.626421]
I1118 10:03:04.578239 28535 gbdt_predict.cc:71] Print tree: 0
$[471] f471:total_wordrank 0.12253 <= 0.19798 ?
|  $[546] f546:new_tuwen_showandtell 0.50291 <= 0.50020 ?
|  |  [548] f548:new_idf_ranktext_all_simid 3733600.00000 <= 256634.00000 ?
|  |  |  [469] f469:keyword_unicode_length 3.00000 <= 4.50000 ?
|  |  |  |  [482] f482:old_examplar -2.00000 <= 0.51275 ?
|  |  |  |  |  -0.0298153
|  |  |  |  |  [471] f471:total_wordrank 0.12253 <= 0.08275 ?
|  |  |  |  |  |  -0.0233632
|  |  |  |  |  |  -0.00122999
|  |  |  |  [482] f482:old_examplar -2.00000 <= 0.52598 ?
|  |  |  |  |  -0.0126085
|  |  |  |  |  0.0137746
|  |  |  [482] f482:old_examplar -2.00000 <= 0.47890 ?
|  |  |  |  -0.0409305
|  |  |  |  [471] f471:total_wordrank 0.12253 <= 0.07121 ?
|  |  |  |  |  -0.0360865
|  |  |  |  |  [469] f469:keyword_unicode_length 3.00000 <= 2.50000 ?
|  |  |  |  |  |  -0.0301188
|  |  |  |  |  |  -0.0082769
|  |  $[469] f469:keyword_unicode_length 3.00000 <= 4.50000 ?
|  |  |  $[471] f471:total_wordrank 0.12253 <= 0.07836 ?
|  |  |  |  [481] f481:old_Keyword_length 3.00000 <= 3.50000 ?
|  |  |  |  |  -0.0277535
|  |  |  |  |  [479] f479:old_Clickquery_freq 0.00000 <= 0.50000 ?
|  |  |  |  |  |  -0.0156884
|  |  |  |  |  |  0.0041274
|  |  |  |  $[547] f547:new_tuwen_showandtell_char 0.52131 <= 0.57042 ?
|  |  |  |  |  $[-0.0042237]
|  |  |  |  |  0.0127872
|  |  |  [471] f471:total_wordrank 0.12253 <= 0.06837 ?
|  |  |  |  [482] f482:old_examplar -2.00000 <= 0.54051 ?
|  |  |  |  |  -0.00946544
|  |  |  |  |  0.0109279
|  |  |  |  [542] f542:new_tuwen_bow 0.59757 <= 0.64964 ?
|  |  |  |  |  0.0104062
|  |  |  |  |  0.0288594
|  [468] f468:keyword_length 6.00000 <= 4.50000 ?
|  |  [55] f55:title_ner_PER 0.00000 <= 0.50000 ?
|  |  |  [546] f546:new_tuwen_showandtell 0.50291 <= 0.36023 ?
|  |  |  |  -0.0262891
|  |  |  |  [471] f471:total_wordrank 0.12253 <= 0.41764 ?
|  |  |  |  |  -0.00869735
|  |  |  |  |  0.00875897
|  |  |  0.0362065
|  |  [543] f543:new_tuwen_rnn 0.69608 <= 0.56176 ?
|  |  |  [471] f471:total_wordrank 0.12253 <= 0.52321 ?
|  |  |  |  [482] f482:old_examplar -2.00000 <= 0.44422 ?
|  |  |  |  |  [480] f480:old_Term_freq_weight 1.00000 <= 1.50000 ?
|  |  |  |  |  |  -0.0196232
|  |  |  |  |  |  0.00265214
|  |  |  |  |  [481] f481:old_Keyword_length 3.00000 <= 4.50000 ?
|  |  |  |  |  |  0.0100783
|  |  |  |  |  |  0.032422
|  |  |  |  [480] f480:old_Term_freq_weight 1.00000 <= 1.50000 ?
|  |  |  |  |  0.010391
|  |  |  |  |  0.0357248
|  |  |  [471] f471:total_wordrank 0.12253 <= 0.50000 ?
|  |  |  |  [481] f481:old_Keyword_length 3.00000 <= 4.50000 ?
|  |  |  |  |  0.0239055
|  |  |  |  |  0.0384573
|  |  |  |  [475] f475:old_Title_freq 1.00000 <= 0.50000 ?
|  |  |  |  |  0.0306819
|  |  |  |  |  0.0429537

```
