#include "msgqueue.h"
#include "util/AppDefine.h"
#include <QDebug>
#include <thread>
#include <string>
#include <stdio.h>
#include "../server/multiprocess/connection.h"

using namespace std;

static MsgQueue* m_instance;

MsgQueue::MsgQueue()
{
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
}

MsgQueue *MsgQueue::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new MsgQueue();
    }
    return m_instance;
}

void MsgQueue::initMsgQueue()
{
    //    static bool isAlreadyInit = false;

    //    if (!isAlreadyInit) {
    //        isAlreadyInit = true;
    //    } else {
    //        return;
    //    }

    sprintf (client_queue_name, "/sp-example-client-%d", getpid ());
    qDebug("hai phan %s", client_queue_name);

    if ((qd_client = mq_open (client_queue_name, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Client: mq_open (client)");
        exit (1);
    }

    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
        perror ("Client: mq_open (server)");
        exit (1);
    }

    thread t1 (&MsgQueue::listeningMsg, this);
    t1.detach();
}

void MsgQueue::listeningMsg()
{

}

void MsgQueue::sendingMsg()
{
    initMsgQueue();
    qDebug("hai phan : %s", client_queue_name);

    char in_buffer [MSG_BUFFER_SIZE];
    char temp_buf [10];

    while (fgets (temp_buf, 2, stdin)) {
        if (mq_send (qd_server, client_queue_name, strlen (client_queue_name) + 1, 0) == -1) {
            perror ("Client: Not able to send message to server");
            continue;
        }

        if (mq_receive (qd_client, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            perror ("Client: mq_receive");
            exit (1);
        }
    }


    if (mq_close (qd_client) == -1) {
        perror ("Client: mq_close");
        exit (1);
    }

    if (mq_unlink (client_queue_name) == -1) {
        perror ("Client: mq_unlink");
        exit (1);
    }
    printf ("<Client> Quitting...\n");
}
