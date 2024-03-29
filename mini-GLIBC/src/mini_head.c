#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if (argc != 4) 
        mini_perror("Argument error\n");
    
    if (mini_strcmp(argv[1], "-n")==0){
        int num_line = mini_str_to_int(argv[2]);
        mini_head(num_line, argv[3]);
    }else 
        mini_perror("-n lacking");
    
    return 0;
}