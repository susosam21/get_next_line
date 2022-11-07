#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char *ft_strjoin(char *s1, char *buff)
{
	char *sr1;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (buff)
	{
		sr1 = (char *)malloc(ft_strlen(s1) + ft_strlen(buff) + 1);
		if (!sr1)
			return (NULL);
		while (s1[j] != 0)
			sr1[i++] = s1[j++];
		j = 0;
		while (buff[j] != 0)
			sr1[i++] = buff[j++];
		sr1[i] = 0;
		free(buff);
		free(s1);
		return (sr1);
	}
	return (0);
}