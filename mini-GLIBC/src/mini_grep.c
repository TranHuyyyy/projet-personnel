#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if(argc != 3)
        mini_perror("Argument error\n");

    mini_grep(argv[2], argv[1]);

    return 0;
}