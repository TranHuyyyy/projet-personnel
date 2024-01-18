Ex5: 
Si on n'initialise pas le buffer avec des '\0' avant de le renvoyer on peut risquer d'avoir certaines characteres inconnues si on le réutilise en utilisant mini_calloc() après appel mini_free().
Par exemple: Considérons notre buffer n'est pas initialisé avec des '\0'.
On initialise char *buffer1 = mini_calloc(sizeof(char), 3);

  	buffer1 -> [][][]

On met des valeurs dans buffer1 par exemple: buffer1[0] = 'a'
                                             buffer1[1] = 'b' 

                                             buffer1 -> [a][b][]
  
Maintenant, on libère le bloc memoire a buffer1 avec mini_free(buffer1)
On initialise char *buffer2 = mini_calloc(sizeof(char), 3)
Parce qu'on utilise malloc_liste() pour réutiliser le bloc mémoire non-utilisé donc maintenant buffer2 est comme suite
  
	buffer2 -> [a][b][]


Ex6: 
La fonction free() ne libère pas vraiment le bloc mémoire. Son action réelle est qu'elle ne permet plus au pointeur qui possède le bloc de mémoire de posséder ce bloc de mémoire. Après appel free(pointeur) le pointeur ne possède plus ce bloc memoire, il n'est plus autorisé d'écrire et de lire sur ce bloc mémoire


Ex12: 
On initialise un buffer1 avec trois characteres, on mets des valeurs pour buffer1[0] et buffer1[1], puis on libère 
le bloc mémoire du buffer1 en utilisant mini_free(buffer1). On initialise un buffer2, et on vérifie si buffer2[0] 
et buffer2[1] ont des valeurs qu'on a mis précédemment. Si oui notre mini_calloc() n'est pas correcte.


Ex17:
Le problème est si la longueur de notre chaîne de caractères est plus courte que le BUF_SIZE le programme n'écrit pas
notre chaîne a stdin


Ex20: 
Si le nombre de caractères saisis est égal à la taille du buffer, '\0' n'est pas ajouté a la fin du chaîne, donc on lit taille_buffer - 1 caractères et on met '\0' a buffer[taille_buffer]


Ex22: 
Avec mini_strcpy() on ne peut pas savoir la longueur de la chaîne destinée, donc si la longueur de la chaîne source est plus longue que celle de la chaîne destinée. On risque d'avoir "buffer overflow", c'est notamment dangereux en terme de sécurité car les hackeurs peut utilise "buffer overflow" pour mettre des codes executable a notre machine.
	-> creer mini_strncpy() qui prend n comme nombre caractères pour copier 


Ex34: 
Dans mini_fwrite() l’écriture ne sera déclenchée que lorsque le buffer_write sera plein donc si le buffer_write n'était pas plein quand le programme se termine des caractères ne sont pas écrit au fichier.



SIMPLE SHELL MANUAL est dans le programmation main (make main)

++++++++++++++++++++++++++++++++++++++++SIMPLE SHELL MANUAL++++++++++++++++++++++++++++++++++++++++

+    mini_touch file_name                Create a file                                            +

+    mini_cp source_file dest_file       Copy source_file to dest_file                            +

+    mini_echo line                      Print the number of lines in the file                    +

+    mini_cat file_name                  Print out the contents of the file                       +

+    mini_head -n <N> file_name          Print the first N lines of the file                      +

+    mini_tail -n <N> file_name          Print the last N lines of the file                       +

+    mini_clean file_name                Empty file if one exists and create a file otherwise     +

+    mini_grep word file_name            Print out all lines containing this word                 +

+    wc file_name                        Print the number of words in the file                    +

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Taper "exit" pour arrêter programme

