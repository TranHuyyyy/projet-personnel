CC = gcc
CFLAGS = -Wall

main: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/main.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/main.c -o main

mini_touch: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_touch.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_touch.c -o mini_touch

mini_cp: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_cp.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_cp.c -o mini_cp

mini_echo: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_echo.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_echo.c -o mini_echo

mini_cat: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_cat.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_cat.c -o mini_cat

mini_head: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_head.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_head.c -o mini_head

mini_tail: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_tail.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_tail.c -o mini_tail

mini_clean: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_clean.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_clean.c -o mini_clean

mini_grep: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_grep.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/mini_grep.c -o mini_grep

wc: src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/wc.c
	$(CC) $(CFLAGS) src/mini_memory.c src/mini_string.c src/mini_io.c src/mini_shell.c src/wc.c -o wc

clean:
	rm main mini_touch mini_cp mini_echo mini_cat mini_head mini_tail mini_clean mini_grep wc
