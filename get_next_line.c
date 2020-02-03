/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aanttila <aanttila@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:47:07 by aanttila       #+#    #+#                */
/*   Updated: 2020/02/03 19:12:36 by aanttila      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_error(char **line, char *str)
{
	if (*line)
		free(*line);
	if (str)
		ft_bzero(str, BUFFER_SIZE + 1);
	line = NULL;
	return (-1);
}

char		*ft_linefill(char **line, char *str, int *retval)
{
	if (ft_strichr((str), '\n') == 0)
	{
		*line = ft_strjoin(*line, str);
		if (*line == 0)
			*retval = (ft_error(line, str));
		ft_bzero(str, (BUFFER_SIZE + 1));
	}
	else if (ft_strichr(str, '\n') != 0)
	{
		*line = ft_strjoin(*line, str);
		if (*line == 0)
			*retval = (ft_error(line, str));
		ft_strshift(str);
		*retval = 1;
	}
	return (str);
}

char		*ft_read(char *str, int *retval, int ret, int fd)
{
	ft_bzero(str, (BUFFER_SIZE + 1));
	ret = read(fd, str, BUFFER_SIZE);
	if (ret < 0)
		*retval = -1;
	if (ret == 0)
		*retval = 0;
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char		str[BUFFER_SIZE + 1];
	int				ret;
	int				retval;

	retval = BUFFER_SIZE;
	if (fd < 0 || line == NULL)
		return (-1);
	ret = 1;
	*line = (char *)malloc(1 * sizeof(char));
	if (*line == NULL)
		return (-1);
	*line[0] = '\0';
	while (ret != 0 && retval != 0)
	{
		if (str[0] != '\0')
			ft_linefill(line, str, &retval);
		else
			ft_read(str, &retval, ret, fd);
		if (retval == -1 || retval == 1)
			return (retval);
	}
	*line = ft_strjoin(*line, str);
	if (*line == 0)
		return (ft_error(line, str));
	return (0);
}
