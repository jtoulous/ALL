/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:27:39 by jtoulous          #+#    #+#             */
/*   Updated: 2022/11/03 18:28:18 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 41
# endif
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*read_the_fkin_file(int fd, char *buf, char *line);
char	*clean(char *buf, size_t z, size_t y);
int		ft_strlen(char *line, char *buf);
char	*copy(char *buf, char *line, size_t	z, size_t y);
int		newline_check(char *buf);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*copy_2(char buf, char *line, char *new_line, size_t z);

#endif
