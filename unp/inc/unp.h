#ifndef __UNP_H__
#define __UNP_H__

#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#endif

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define LISTENQ     1024
#define MAXLINE     4096
#define BUFFSIZE    8192
#define SERV_PORT   9877

#define SA struct sockaddr

char* sock_ntop(const struct sockaddr*, socklen_t);

#endif
