/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aanttila <aanttila@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 14:59:27 by aanttila       #+#    #+#                */
/*   Updated: 2019/12/13 20:41:55 by aanttila      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUF_SIZE 5

#include <strings.h>

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*buf;
	char			str[BUF_SIZE + 1];
	int i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	ret = 1;
	while (ret != 0)
	{
		bzero(str, BUF_SIZE);
		ret = read(fd, str, BUF_SIZE);
		str[BUF_SIZE] = '\0';
		printf("(%d) read[%d] : %s\n", ret, i, str);
		i++;
		buf = ft_strjoin(buf, str, i, BUF_SIZE);
		printf("buf : %s\n", buf);
		if (ft_strchr(buf, '\n') != 0)
		{
			printf("\nnew line found\n\n");
			*line = ft_strdup(buf);
			buf = buf + ft_strichr(buf, '\n');
			return (*ft_strchr(*line, '\n'));
		}
	}
//	if (close(fd) == -1)
//		return (1);
	return (0);
}

int		main(void)
{
	char *line;
	get_next_line(1, &line);
	get_next_line(1, &line);
	return (0);
}




/*
char *str -> read(fd, str, bufsize)
join my str + static buff -> so you save all the things 
but so that you can also overwrite str everytime.
search in buff for '\n' (with strchr)
add everything up to that newline from buff into line

strdup until newline into line;
*line = ft_strcdup('\n', buff);
buff = strchr('\n') + 1;
 */
