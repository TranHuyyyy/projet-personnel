#include <unistd.h>
#include "mini_lib.h"
#include <errno.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

#define BUF_SIZE 1024

char *buffer;
int ind = -1;

void mini_printf(char *text){
    if (ind == -1){
        buffer = mini_calloc(sizeof(char), BUF_SIZE);
        ind = 0;
    }

    int i = 0;
    while (text[i] != '\0'){
        if (text[i] == '\n' || ind == BUF_SIZE){
            if (text[i] == '\n')
                buffer[ind++] = text[i++];

            write(STDOUT_FILENO, buffer, ind);

            while (ind >= 0)
                buffer[ind--] = '\0';
            ind = 0;
        }
        else 
            buffer[ind++] = text[i++];
    }
}

int mini_scanf(char *buffer, int size_buffer){
    if (size_buffer <= 0){
        mini_perror("Size_buffer must be greater than 0");
        mini_exit();
    }

    int count = read(STDIN_FILENO, buffer, size_buffer - 1);

    if (count == -1){
        mini_perror("Read error");
        mini_exit();
    }
    buffer[count] = '\0';

    return count;
}

int mini_strlen(char *s){
    if (s == NULL){
        mini_perror("String doesn't exist");
        mini_exit();
    }

    char *temp = s;
    int len = 0;

    while (*temp != '\0'){
        len++;
        temp++;
    }

    return len; 
}

int mini_strcpy(char *s, char *d){
    if (s == NULL || d == NULL)
        return -1;
    
    int count = 0;

    while (*s != '\0'){
        *d++ = *s++;
        count++;
    }
}

int mini_strcmp(char *s1, char *s2){
    if (s1 == NULL || s2 == NULL){
        mini_perror("String can't be NULL");
        mini_exit();
    }

    while (*s1 != '\0'){
        if (*s1 != *s2 || *s2 == '\0')
            return -1;
        s1++;
        s2++;
    }

    if (*s2 != '\0')
        return -1;

    return 0;
}

char *mini_int_to_str(int value){
    int digits;
    int k = value;
    while (k != 0){
        k /= 10;
        digits++;
    } 

    char *str_from_val = mini_calloc(sizeof(char), digits + 1);
    *(str_from_val + digits) = '\0';
    for (int i = 0; value != 0; i++){
        int temp = value % 10;
        *(str_from_val + digits - (i + 1)) = (char)(temp + 48);
        value /= 10;
    }

    return str_from_val; 
}

int mini_str_to_int(char *s){
    int int_from_str = 0;
    int base = 10;
    for (int i = 0; s[i] != '\0'; ++i)
        int_from_str = int_from_str * base + s[i] - '0';

    return int_from_str;
}


void mini_perror(char *message){
    char *errno_str = mini_int_to_str(errno);
    mini_printf(message);
    mini_printf("\nWith error code: ");
    mini_printf(errno_str);
    mini_printf("\n");
    _exit(EXIT_SUCCESS);
}

void mini_exit_string(){
    if (ind != -1){
        write(STDOUT_FILENO, buffer, ind);
        ind = -1;
    }
}