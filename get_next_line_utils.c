/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aanttila <aanttila@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 19:41:00 by aanttila       #+#    #+#                */
/*   Updated: 2019/12/13 20:35:04 by aanttila      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*dst;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (s1[i2] != '\0')
	{
		i2++;
	}
	i2++;
	dst = (char *)malloc(i2 * sizeof(char));
	if (dst == NULL)
		return (0);
	while (i < i2)
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}

int		ft_strichr(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (i + 1);
		i++;
	}
	if ((char)c == '\0')
		return (i + 1);
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int k, int buf_size)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(((k * buf_size) * (buf_size + 1)) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < ((k * buf_size) - buf_size))
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
