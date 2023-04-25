/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:39:37 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/18 13:17:08 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int z);
int			ft_isalpha(int z);
int			ft_isascii(int z);
int			ft_isdigit(int z);
int			ft_isprint(int z);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
int			ft_charcnt(const char *str, char c);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strtrim(const char *s, const char *set);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		free_loop(char **str);
void		ft_putchar(char ch);
void		ft_putstr(char *str);
void		s_trimage(char *str, int trim_size);
void		free_free(void *str1, void *str2);
void		quick_kill(char *err_msg);
double		ft_atof(char *str);

#endif
