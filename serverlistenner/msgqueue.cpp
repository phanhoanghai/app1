#include "msgqueue.h"
#include "util/AppDefine.h"
#include <QDebug>
#include "thread"

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

bool MsgQueue::initMsgQueue()
{
    thread t1 (&MsgQueue::listeningMsg, this);
    t1.detach();
    return true;
}

void MsgQueue::listeningMsg()
{

}

void MsgQueue::sendingMsg()
{
    qDebug() << client_queue_name <<  "/sp-example-client-%d" << getpid() << Qt::endl;

    if ((qd_client = mq_open (client_queue_name, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        qDebug() << "Client: mq_open (client)" << Qt::endl;
        exit (1);
    }

    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
        qDebug() << "Client: mq_open (server)" << Qt::endl;
        exit (1);
    }

    char in_buffer [MSG_BUFFER_SIZE];

    qDebug() << "Ask for a token (Press <ENTER>): " << Qt::endl;

    char temp_buf [10];

    while (fgets (temp_buf, 2, stdin)) {

        // send message to server
        if (mq_send (qd_server, client_queue_name, strlen (client_queue_name) + 1, 0) == -1) {
            qDebug() << "Client: Not able to send message to server" <<  Qt::endl;
            continue;
        }

        // receive response from server

        if (mq_receive (qd_client, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            qDebug() << "Client: mq_receive" << Qt::endl;
            exit (1);
        }

        qDebug() << "Client: Token received from server: " << Qt::endl;
        qDebug() << "Ask for a token (Press ): " << Qt::endl;
    }


    if (mq_close (qd_client) == -1) {
        perror ("Client: mq_close");
        exit (1);
    }

    if (mq_unlink (client_queue_name) == -1) {
        perror ("Client: mq_unlink");
        exit (1);
    }
    printf ("Client: bye\n");
}
