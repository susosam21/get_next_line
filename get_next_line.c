/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:29:41 by hmohamed          #+#    #+#             */
/*   Updated: 2022/11/06 17:38:15 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char	*str;
	size_t	buff_size;
	char	*buff;
	size_t	i;

	buff = malloc(buff_size);
	i = read(fd, buff, buff_size);
	while (i > 0 && check(buff))
	{
		str = ft_strjoin(str, buff);
		i = read(fd, buff, buff_size);
	}
	str = ft_strjoin(str, buff);
	return(str);
}
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char	*str;
	size_t	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s :", get_next_line(fd));
	return (0);
}
