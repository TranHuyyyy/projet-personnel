#include "mini_lib.h"
#include <unistd.h>
#include <sys/wait.h>

void test_mini_memory(){
    char *buffer1 = mini_calloc(sizeof(char), 3);
    buffer1[0] = 'a';
    buffer1[1] = 'b';
    mini_printf("buffer1 is : ");
    mini_printf(buffer1);
    mini_printf("\n");

    mini_free(buffer1);

    char *buffer2 = mini_calloc(sizeof(char), 3);
    if(buffer2[0] == 'a' && buffer2[1] == 'b') 
        mini_printf("Memory wasn't clean before being allocated");

  //  mini_exit();
}

void test_mini_string(){
    mini_printf("What is your name ?\n");
    char *text1 = mini_calloc(sizeof(char), 100);
    int count = mini_scanf(text1, 100);
    mini_printf("Your name is ");
    mini_printf(text1);
    
 //   mini_exit_string();
}

void test_mini_io(){

    mini_touch("file_test.txt");
    struct MYFILE *rw_file = mini_fopen("file_test.txt", 'b');
    char buffer_to_write[] = "Je voudrais devenir 2eme le prof Briffaut";
    mini_fwrite(buffer_to_write, sizeof(char), sizeof(buffer_to_write)-1, rw_file);
    mini_fflush(rw_file);

    rw_file = mini_fopen("file_test.txt", 'b');

    char *buffer_to_read = mini_calloc(sizeof(char), sizeof(buffer_to_write));
    mini_fread(buffer_to_read, sizeof(char), sizeof(buffer_to_write)-1, rw_file);
    mini_printf(buffer_to_read);
    mini_exit_string();
    mini_exit_io();

    struct MYFILE *file = mini_fopen("file_test.txt", 'r');
    if (mini_fclose(file) == -1)
        mini_printf("\nmini_fclose error\n");
    else
        mini_printf("\nSuccessfully close file\n");

  //  mini_exit_io();
}

int main(){
    test_mini_memory();
    mini_printf("------------------------------------\n");
    test_mini_string();
    mini_exit_string();
    mini_printf("------------------------------------\n");
    test_mini_io();
    mini_exit_io();
    mini_printf("------------------------------------\n");

    char **args;
    mini_printf("\nSHELL STARTS, TYPE HELP TO SEE AVAILABLE COMMAND\n");
    mini_help_exec(args);
    mini_shell_loop();

    return 0;
}
