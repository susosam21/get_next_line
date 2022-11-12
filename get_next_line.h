#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFF_SIZE 4

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strjoin(char *s1, char *buff);
size_t ft_strlen(const char *str);
char *get_next_line(int fd);
char *ft_strdup(const char *src);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif