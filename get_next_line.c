/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:29:41 by hmohamed          #+#    #+#             */
/*   Updated: 2022/11/07 17:46:27 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int check(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char *join(char *str, char *buff)
{
	char *res;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buff[i] != '\n')
		i++;
	res = malloc(i);

	while (j <= i)
	{
		res[j] = *buff++;
		j++;
	}
	res = ft_strjoin(str, res);
	return (res);
}

char *get_next_line(int fd)
{
	char *str;
	unsigned int buff_size;
	static char *buff;
	size_t i;
	int j;
	char *start;

	j = 0;
	buff_size = 4;
	str = NULL;
	i = 0;
	if (buff)
	{
		while (buff[j] != '\n')
			j++;
		j++;
		free(str);
		str = malloc(ft_strlen(buff) - j);
		while (buff[j])
		{
			str[i++] = buff[j++];
		}

		printf("this is: %s \n", buff);
	}
	else
		str = malloc(buff_size);

	buff = malloc(buff_size);

	i = read(fd, buff, buff_size);
	while (i > 0 && check(buff))
	{
		str = ft_strjoin(str, buff);
		buff = malloc(buff_size);
		i = read(fd, buff, buff_size);
	}
	str = join(str, buff);
	free(buff);
	return (str);
}

int main()
{
	char *str;
	int fd;

	fd = open("test.text", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	printf("%s", get_next_line(fd));
	return (0);
}
