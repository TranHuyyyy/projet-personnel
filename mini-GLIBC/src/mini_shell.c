#include "mini_lib.h"
#include <unistd.h>
#include <sys/wait.h>

#define BUF_SIZE 64

int mini_help_exec(char **args){
    mini_printf("\n++++++++++++++++++++++++++++++++++++++++SIMPLE SHELL MANUAL++++++++++++++++++++++++++++++++++++++++\n");
    mini_printf("\n+    mini_touch file_name                Create a file                                            +\n");
    mini_printf("\n+    mini_cp source_file dest_file       Copy source_file to dest_file                            +\n");
    mini_printf("\n+    mini_echo line                      Print the number of lines in the file                    +\n");
    mini_printf("\n+    mini_cat file_name                  Print out the contents of the file                       +\n");
    mini_printf("\n+    mini_head -n <N> file_name          Print the first N lines of the file                      +\n");
    mini_printf("\n+    mini_tail -n <N> file_name          Print the last N lines of the file                       +\n");
    mini_printf("\n+    mini_clean file_name                Empty file if one exists and create a file otherwise     +\n");
    mini_printf("\n+    mini_grep word file_name            Print out all lines containing this word                 +\n");
    mini_printf("\n+    wc file_name                        Print the number of words in the file                    +\n");
    mini_printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    mini_printf("\n");
    mini_printf("\n");
}

int execute_command(char** args){
    int state;
    pid_t pid, wpid;

    pid = fork();
    if (pid == 0){
        int state = execve(args[0], args, NULL);
        if(state == -1) 
            mini_perror("Command not found\n");
        mini_exit();
    }else if (pid < 0)
        mini_perror("in execute_command pid < 0");
    else{
        do
            wpid = waitpid(pid, &state, WUNTRACED);
        while (!WIFEXITED(state) && !WIFSIGNALED(state));
    }

    return 1;
}

char **split_command(char *line){
    char **tokens = mini_calloc(sizeof(char *), BUF_SIZE);
    for(int i = 0; i < BUF_SIZE; i++) 
        tokens[i] = mini_calloc(sizeof(char), BUF_SIZE);
    int i = 0; 
    int j = 0; 
    int k = 0; 

    while (line[i] != '\0'){
        if (line[i] == ' '){
            tokens[j][k] = '\0';
            j++;
            k = 0;
        }else
            tokens[j][k++] = line[i];
        i++;
    }
    tokens[j][k] = '\0';
    tokens[j+1] = NULL;
    
    return tokens;
}

int remove_enter_in_buffer(char* buffer){
    int k;
    for (k = 0; k < mini_strlen(buffer); k++){
        if(buffer[k] == '\n') {
            buffer[k] = '\0';
            break;
        }
    }

    return k;
}

char *read_command(void) {
    struct MYFILE *mini_stdin = mini_fopen("/dev/stdin", 'b');

    int max_size = 1024;
    int position = 0;
    char *buffer = mini_calloc(sizeof(char), max_size);
    int c;

    while (1){
        c = mini_fgetc(mini_stdin);
        if (c == -1 || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        }else
            buffer[position] = c;
        position++;
    }
}

void mini_shell_loop(void){
    char exit[] = "exit";
    char *command = mini_calloc(sizeof(char), 1024);
    char **args;
    int state;

    do{
        mini_printf("> ");
        mini_exit_string();
        mini_scanf(command, 1024);
        remove_enter_in_buffer(command);

        if(mini_strcmp(command, exit) == 0)
            break;
        
        args = split_command(command);
        state = execute_command(args);

    }while (mini_strcmp(command, exit) != 0);
}
