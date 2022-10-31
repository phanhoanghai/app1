#include "readsharemem.h"
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;

static ReadShareMem* m_instance;

ReadShareMem::ReadShareMem()
{

}

ReadShareMem *ReadShareMem::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new ReadShareMem();
    }
    return m_instance;
}

std::string ReadShareMem::getSharemem()
{
    key_t key = ftok("data",65);

    int shmid = shmget(key, 1024, 0666|IPC_CREAT);

    char* str = (char*) shmat(shmid,(void*)0,0);

    printf("Data read from memory: %s\n",str);

    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}
