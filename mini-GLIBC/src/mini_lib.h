#ifndef MINI_LIB
#define MINI_LIB

//---------------------------------------------
struct malloc_element{
    void *zone_element;
    int size;
    int state;
    struct malloc_element *next_malloc;
};
//-----------------------------------------------------

//-----------------------------------------------------
extern struct malloc_element *malloc_list;
void *mini_calloc(int size_element, int number_element);
void mini_free(void* ptr);
void mini_exit();
//-------------------------------------------------------

//--------------------------------------------------------
void mini_printf(char *text);
int mini_scanf(char *buffer, int size_buffer);
int mini_strlen(char *s);
int mini_strcpy(char *s, char *d);
int mini_strcmp(char *s1, char *s2);
char *mini_int_to_str(int value);
int mini_str_to_int(char *s);
void mini_perror(char *message);
void mini_exit_string();
//-------------------------------------------------------

//-----------------------------------------------------
struct MYFILE{
    int fd;
    void *buffer_read;
    void *buffer_write;
    int ind_read;
    int ind_write;
};

struct FILE_list{
    struct MYFILE *file;
    struct FILE_list *next;
};
//-----------------------------------------------------

//------------------------------------------------------
extern struct FILE_list *file_list;
struct MYFILE *mini_fopen(char *file, char mode);
int mini_fread(void *buffer, int size_element, int number_element, struct MYFILE *file);
int mini_fwrite(void *buffer, int size_element, int number_element, struct MYFILE *file);
int mini_fflush(struct MYFILE *file);
int mini_fclose(struct MYFILE *file);
int mini_fgetc(struct MYFILE *file);
int mini_fputc(struct MYFILE *file, char c);
struct MYFILE *mini_touch(char *file_name);
void mini_cp(char *src, char *dest);
void mini_echo(char *buffer);
void mini_cat(char *file_name);
void mini_head(int n, char *file_name);
void mini_tail(int n, char *file_name);
void mini_clean(char *file_name);
void mini_grep(char *file_name, char *word);  
void wc(char *file_name);
void mini_exit_io();
//------------------------------------------------------

//--------------------------------------------------------
int mini_help_exec(char **args);
int execute_command(char** args);
char **split_command(char *line);
int remove_enter_in_buffer(char* buffer);
char *read_command(void);
void mini_shell_loop(void);
//--------------------------------------------------------

#endif
