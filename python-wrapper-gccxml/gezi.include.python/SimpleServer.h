#ifndef SIMPLE_SERVER_H_
#define SIMPLE_SERVER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/wait.h>
#include <unistd.h>
#include <memory.h>
#include "log_util.h"
#include "ul_net.h"
#include "nshead.h"
template<typename _Func, int MAXLEN = 204800 >
class SimpleServer
{
private:
int _listenfd;
int _port;
_Func& _func;
enum
{
OVERTIME = 100,
LISTENQ = 5,
};
public:
SimpleServer(int port, _Func& func);
int init();
int process_request(int connfd);
int work();
int run();
};
#endif
