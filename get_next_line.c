/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:29:41 by hmohamed          #+#    #+#             */
/*   Updated: 2022/11/13 14:56:51 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	check(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	freeline(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*next(char **str, int i)
{
	int		j;
	char	*temp;
	char	*line;

	if (i <= 0 && *str == NULL)
		return (NULL);
	else
		j = 0;
	while ((*str)[j] != '\n' && (*str)[j] != '\0')
		j++;
	if ((*str)[j] == '\n')
	{
		line = ft_substr(*str, 0, j + 1);
		temp = ft_strdup(&((*str)[j + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			freeline(str);
	}
	else
	{
		line = ft_strdup(*str);
		freeline(str);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*str;
	int			i;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str, buff);
			free(str);
			str = temp;
		}
		if (check(str))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (next(&str, i));
}

// int main()
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("test.text", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
// 	return (0);
// }
