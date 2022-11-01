#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include "../server/multiprocess/connection.h"

class MsgQueue
{
private:
    MsgQueue();

public:
    static MsgQueue* getInstance();

public:
    void initMsgQueue();
    void listeningMsg();
    void sendingMsg();

private:
    char* client_queue_name;
    mqd_t qd_server, qd_client;
    struct mq_attr attr;
};

#endif // MSGQUEUE_H
