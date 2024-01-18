#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if (argc != 4) 
        mini_perror("Argument error\n");
    
    if (mini_strcmp(argv[1], "-n")==0){
        int num_line = mini_int_to_str(argv[2], 10);
        mini_tail(num_line, argv[3]);
    }else 
        mini_perror("-n lacking");
    
    return 0;
}