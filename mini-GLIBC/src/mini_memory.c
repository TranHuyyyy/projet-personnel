#include <unistd.h>
#include <errno.h>
#include "mini_lib.h"
#include <sys/syscall.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

struct malloc_element *malloc_list = NULL;

void *mini_calloc(int size_element, int number_element){
    int size_total = size_element * number_element;
    if (number_element < 0){
        mini_perror("Number of element must be greater than or equal to 0");
    }

    if (malloc_list != NULL){
        struct malloc_element *temp = malloc_list;
        while (temp != NULL){
            if (temp->state == 0 && size_total <= temp->size){
                int i = 0;
                while (i < size_total){
                    *((char*)temp->zone_element + i) = '\0';
                    i++;
                }
                return temp->zone_element;
            }
            temp = temp->next_malloc;
        }
    }

    void *buffer = sbrk(size_total);

    if (buffer == (void*) - 1){
        mini_perror("An error occurred while allocating using sbrk");
        return NULL;
    }

    int j = 0;
    while (j < size_total){
        *((char*)buffer + j) = '\0';
        j++;
    }

    if (malloc_list == NULL){
        malloc_list = sbrk(sizeof(struct malloc_element));
        malloc_list->zone_element = buffer;
        malloc_list->size = size_total;
        malloc_list->state = 1;
        malloc_list->next_malloc = NULL;
    }
    else {
        struct malloc_element* next = sbrk(sizeof(struct malloc_element));
        next->zone_element = buffer;
        next->size = size_total;
        next->state = 1;
        next->next_malloc = malloc_list;
        malloc_list = next;
    }

    return buffer;
}

void mini_free(void *ptr){
    struct malloc_element *temp = malloc_list;
    while (temp != NULL) {
        if (temp->zone_element == ptr){
            temp->state = 0;
        }
        temp = temp->next_malloc;
    }
}

void mini_exit(){
    mini_exit_string();
    mini_exit_io();
    _exit(EXIT_SUCCESS);
}