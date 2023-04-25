/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:49:32 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:49:56 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_value(int *stacks)
{
	int	last;
	int	z;
	int	big_boy;

	z = 0;
	big_boy = 0;
	last = last_index(-1);
	while (z < last)
	{
		if (stacks[z] > stacks[big_boy])
			big_boy = z;
		z++;
	}
	return (stacks[big_boy]);
}

int	max_nbr_value(int *stacks)
{
	int	big;
	int	count;

	count = 0;
	big = biggest_value(stacks);
	while (big / 2 != 0)
	{
		big = big / 2;
		count++;
	}
	if (big % 2 != 0)
		count++;
	return (count);
}

int	ft_strlen(char *str)
{
	int	z;

	z = 0;
	if (str)
	{	
		while (str[z])
			z++;
	}
	return (z);
}

void	ft_putchar(char ch)
{
	write (1, &ch, 1);
}

void	ft_putstr(char *str)
{
	int	y;

	y = 0;
	while (str[y])
	{
		ft_putchar(str[y]);
		y++;
	}
}
