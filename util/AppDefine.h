#ifndef APPDEFINE_H
#define APPDEFINE_H

#ifndef COMMON_H_
#define COMMON_H_

#include <string>

const std::string json_defined_datas[7] = {"index", "name", "assem", "cplus", "js", "qml", "openGL"};

#define SERVER_QUEUE_NAME   "/sp-example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

#define CHECK(x) \
    do { \
        if (!(x)) { \
            fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
            perror(#x); \
            exit(-1); \
        } \
    } while (0) \

#define ROUNDF(f, c) (((float)((int)((f) * (c))) / (c)))

#endif /* #ifndef COMMON_H_ */

#endif // APPDEFINE_H
