/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aanttila <aanttila@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:50:30 by aanttila       #+#    #+#                */
/*   Updated: 2020/02/03 18:46:55 by aanttila      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		get_next_line(int fd, char **line);
int		ft_strichr(char *s, char c);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strshift(char *str);
size_t	ft_strlen(char *s);
int		ft_error(char **line, char *str);
char	*ft_linefill(char **line, char *str, int *retval);
char	*ft_read(char *str, int *retval, int ret, int fd);

#endif
