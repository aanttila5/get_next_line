/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aanttila <aanttila@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:49:49 by aanttila       #+#    #+#                */
/*   Updated: 2020/02/03 19:14:53 by aanttila      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strichr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (c == '\0')
		return (i + 1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (1);
	while (s[index] != '\0' && s[index] != '\n')
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strshift(char *str)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (str[i] != '\n' && str[i] != '\0' && i <= (BUFFER_SIZE + 1))
		i++;
	i++;
	while (str[i] != '\0')
	{
		str[i2] = str[i];
		i++;
		i2++;
	}
	while (i2 < BUFFER_SIZE + 1)
	{
		str[i2] = '\0';
		i2++;
	}
	return (str);
}
