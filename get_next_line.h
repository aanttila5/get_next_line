/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aanttila <aanttila@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:05:58 by aanttila       #+#    #+#                */
/*   Updated: 2019/12/13 20:30:05 by aanttila      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2, int i, int buf_size);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
int		ft_strichr(char *s, int c);

#endif
