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
		return (sr1);
	}
	return (0);
}

char *ft_strdup(const char *src)
{
	char *dp;
	int i;

	i = 0;
	while (src[i])
		i++;
	dp = (char *)malloc(i * sizeof(char) + 1);
	if (!dp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dp[i] = src[i];
		i++;
	}
	dp[i] = '\0';
	return (dp);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *temp;
	size_t j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		temp = (char *)malloc(sizeof(char) * 1);
		temp[0] = 0;
		return (temp);
	}
	if (len < ft_strlen(s))
		temp = (char *)malloc(len + 1);
	else
	{
		temp = (char *)malloc((ft_strlen(s) - (size_t)start));
		len = ft_strlen(s);
	}
	if (temp == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		temp[j++] = s[start++];
	temp[j] = 0;
	return (temp);
}
