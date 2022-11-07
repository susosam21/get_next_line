#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strjoin(char *s1, char *buff);
size_t ft_strlen(const char *str);
char *get_next_line(int fd);

#endif