#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>

/*
int main(int argc, char **argv){
    if (argc != 2)
        mini_perror("Argument error\n");
    struct MYFILE *file = mini_fopen(argv[1], 'b');
    char c = mini_fgetc(file);

    while (c != -1){
        char *buffer = mini_calloc(sizeof(char), 2);
        buffer[0] = c;
        mini_printf(buffer);
        c = mini_fgetc(file);
    }
    
    return 0;
}

*/

int main(int argc, char **argv){
    if (argc != 2) {
        mini_perror("Argument error\n");
        return 1; // Thoát với mã lỗi
    }

    struct MYFILE *file = mini_fopen(argv[1], 'b');
    if (file == NULL) {
        mini_perror("Error opening file\n");
        return 1; // Thoát với mã lỗi
    }

    int c = mini_fgetc(file);
    while (c != -1){
        char *buffer = mini_calloc(sizeof(char),2);
        buffer[0] = c;
        buffer[1] = '\0'; // Thêm null terminator
        mini_printf(buffer);
        mini_free(buffer);
        c = mini_fgetc(file);
    }

    mini_fclose(file); // Đóng tệp sau khi sử dụng

    return 0;
}

