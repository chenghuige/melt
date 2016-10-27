#pragma once
#include <string>
#ifdef _WIN32
#include <WinSock2.h>
#include <WS2tcpip.h>
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef int socklen_t;
typedef SOCKET socket_t;
#define CLOSESOCK closesocket
#else
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
typedef int socket_t;
#define CLOSESOCK close
#endif
using namespace std;
size_t ar_buf_size;
struct node_socks
{
std::string current_master;
socket_t parent;
socket_t children[2];
~node_socks();
node_socks ();
};
{
for(size_t i;
f(buf1[i], buf2[i]);
}
void all_reduce_init(const string master_location, const size_t unique_id, const size_t total, const size_t node, node_socks& socks);
{
size_t my_bufsize;
if(my_bufsize > 0)
{
int write_size;
if(write_size < 0)
{
cerr<<"Write to parent failed "<<my_bufsize<<" "<<write_size<<" "<<parent_sent_pos<<" "<<left_read_pos<<" "<<right_read_pos<<endl;
throw exception();
}
parent_sent_pos +;
}
}
{
fd_set fds;
FD_ZERO(&fds);
if(child_sockets[0] != -1)
FD_SET(child_sockets[0],&fds);
if(child_sockets[1] != -1)
FD_SET(child_sockets[1],&fds);
socket_t max_fd;
size_t child_read_pos[2];
int child_unprocessed[2];
char child_read_buf[2][ar_buf_size+sizeof(T)-1];
size_t parent_sent_pos;
if(child_sockets[0] == -1)
{
child_read_pos[0];
}
if(child_sockets[1] == -1)
{
child_read_pos[1];
}
while (parent_sent_pos < n || child_read_pos[0] < n || child_read_pos[1] < n)
{
if(parent_sock != -1)
pass_up<T>(buffer, child_read_pos[0], child_read_pos[1], parent_sent_pos, parent_sock, n);
if(parent_sent_pos >;
if(child_read_pos[0] < n || child_read_pos[1] < n)
{
if (max_fd > 0 && select((int)max_fd,&fds,NULL, NULL, NULL) == -1)
{
cerr << "select: " << strerror(errno) << endl;
throw exception();
}
for(int i;
{
if(child_sockets[i] != -1 && FD_ISSET(child_sockets[i],&fds))
{
if(child_read_pos[i] == n)
{
cerr<<"I think child has no data to send but he thinks he has "<<FD_ISSET(child_sockets[0],&fds)<<" "<<FD_ISSET(child_sockets[1],&fds)<<endl;
throw exception();
}
size_t count;
int read_size;
if(read_size == -1)
{
cerr << "recv from child: " << strerror(errno) << endl;
throw exception();
}
addbufs<T, f>((T*)buffer + child_read_pos[i]/sizeof(T), (T*)child_read_buf[i], (child_read_pos[i] + read_size)/sizeof(T) - child_read_pos[i]/sizeof(T));
child_read_pos[i] +;
int old_unprocessed;
child_unprocessed[i];
for(int j;
{
child_read_buf[i][j];
}
if(child_read_pos[i] == n)
FD_CLR(child_sockets[i],&fds);
}
else if(child_sockets[i] != -1 && child_read_pos[i] != n)
FD_SET(child_sockets[i],&fds);
}
}
if(parent_sock == -1 && child_read_pos[0] == n && child_read_pos[1] == n)
parent_sent_pos;
}
}
void broadcast(char* buffer, const size_t n, const socket_t parent_sock, const socket_t * child_sockets);
{
if(master_location != socks.current_master)
all_reduce_init(master_location, unique_id, total, node, socks);
reduce<T, f>((char*)buffer, n*sizeof(T), socks.parent, socks.children);
broadcast((char*)buffer, n*sizeof(T), socks.parent, socks.children);
}
