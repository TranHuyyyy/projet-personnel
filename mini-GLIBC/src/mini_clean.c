#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if (argc != 2)
        mini_perror("Argument error");
    
    if (open(argv[1], O_TRUNC) == -1){
        mini_touch(argv[1]);
    }
    
    return 0;
}