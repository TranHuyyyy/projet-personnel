#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv){
    struct MYFILE *file = mini_calloc(sizeof(struct MYFILE), 1);
    int fd;
    if (argc != 2)
        mini_perror("Argument error\n");

    if ((fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) ) == -1){
        mini_perror("error create file");
        _exit(1);
    }

    file->fd = fd;
    file->ind_read = -1;
    file->ind_write = -1;

    return 0;
}