/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:44:04 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/20 08:13:02 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(int *stacks, int *sep)
{
	int		bit;
	int		max_nbr;
	t_list	*soluce;

	soluce = NULL;
	max_nbr = max_nbr_value(stacks);
	bit = 0;
	while (bit < max_nbr)
	{
		apply_this_round(stacks, sep, &soluce, bit);
		push_it_back(sep, &soluce);
		bit++;
	}
	print_soluce(soluce);
	free_lst(soluce);
	free (stacks);
}

void	print_soluce(t_list *soluce)
{
	t_list	*tmp;

	tmp = soluce;
	while (tmp)
	{
		if (tmp->move == 0)
			ft_putstr("ra\n");
		else if (tmp->move == 1)
			ft_putstr("pb\n");
		else
			ft_putstr("pa\n");
		tmp = tmp->next;
	}
}

void	push_it_back(int *sep, t_list **soluce)
{
	while (*sep > 0)
	{
		push(sep, 1);
		lstadd_back(soluce, lstnew(2));
	}
}

void	apply_this_round(int *stacks, int *sep, t_list **soluce, int bit)
{
	int	last;
	int	z;

	z = 0;
	last = last_index(-1);
	while (z < last)
	{
		if (((stacks[*sep] >> bit & 1) == 1))
		{	
			rotate_a(stacks, sep);
			lstadd_back(soluce, lstnew(0));
		}
		else
		{	
			push(sep, 2);
			lstadd_back(soluce, lstnew(1));
		}
		z++;
	}	
}
