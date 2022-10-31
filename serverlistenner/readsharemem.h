#ifndef READSHAREMEM_H
#define READSHAREMEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

class ReadShareMem
{
private:
    ReadShareMem();

public:
    static ReadShareMem* getInstance();
    std::string getSharemem();
};

#endif // READSHAREMEM_H
