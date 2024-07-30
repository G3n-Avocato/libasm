#ifndef LIBASM_H
# define LIBASM_H

//strlen //strcpy //strcmp //strdup
#include <string.h>
//write //read
#include <unistd.h>
//printf 
#include <stdio.h>
//malloc //atoi
#include <stdlib.h>
//open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//isdigit
#include <ctype.h>

size_t   ft_strlen(const char* str);
char*    ft_strcpy(char *dest, const char* src);
int      ft_strcmp(const char *s1, const char *s2);
ssize_t  ft_write(int fd, const void *buf, size_t nbyte);
ssize_t  ft_read(int fd, void *buf, size_t nbyte);
char*    ft_strdup(const char* s);

#endif