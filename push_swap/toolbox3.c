/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:50:10 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/20 08:13:26 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	z;

	z = 0;
	while (s[z])
	{
		ft_putchar_fd(s[z], fd);
		z++;
	}
}

int	position_of_x(int *argz, int x)
{
	int			pos;
	int			z;
	static int	last;

	pos = 0;
	z = 0;
	if (!last)
		last = last_index(-1);
	while (z < last)
	{
		if (argz[z] < argz[x])
			pos++;
		z++;
	}
	return (pos);
}

int	check_soluce(int *pos_tracker, int *sep)
{
	int			z;
	static int	last;

	if (!last)
		last = last_index(-1);
	z = 0;
	if (*sep != 0)
		return (0);
	while (z < last)
	{
		if (pos_tracker[z] != z)
			return (0);
		z++;
	}
	return (1);
}

void	free_lst(t_list *lst)
{
	t_list	*prev;

	prev = lst;
	lst = lst->next;
	while (lst->next != NULL)
	{
		free(prev);
		prev = lst;
		lst = lst->next;
	}
	free(prev);
	free(lst);
}
