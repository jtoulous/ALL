/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilityz_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:31:45 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:34:23 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	possibilityz_rb(int move, int *sep)
{
	move++;
	if (*sep == 2)
	{
		while (move != 0 && move != 3 && move != 4 && move != 8 && move != 11)
			move++;
	}
	else
	{
		while (move != 0 && move != 1 && move != 2 && move != 3
			&& move != 4 && move != 6 && move != 7 && move != 8
			&& move != 11)
			move++;
	}
	return (move);
}

int	possibilityz_rr(int move, int *sep)
{
	move++;
	if (*sep == 2)
	{
		while (move != 0 && move != 3 && move != 4 && move != 8 && move != 11)
			move++;
	}
	else
	{
		while (move != 0 && move != 1 && move != 2 && move != 3
			&& move != 4 && move != 5 && move != 6 && move != 7
			&& move != 11)
			move++;
	}
	return (move);
}

int	possibilityz_rra(int move, int *sep)
{
	move++;
	if (*sep == 0)
	{
		while (move != 0 && move != 3 && move != 8 && move != 11)
			move++;
	}
	else if (*sep == 1)
	{
		while (move != 0 && move != 3 && move != 4 && move != 8 && move != 11)
			move++;
	}
	else
	{
		while (move != 0 && move != 1 && move != 2 && move != 3
			&& move != 4 && move != 6 && move != 8 && move != 10
			&& move != 11)
			move++;
	}
	return (move);
}

int	possibilityz_rrb(int move, int *sep)
{
	move++;
	if (*sep == 2)
	{
		while (move != 0 && move != 3 && move != 4 && move != 5 && move != 11)
			move++;
	}
	else
	{
		while (move != 0 && move != 1 && move != 2 && move != 3
			&& move != 4 && move != 5 && move != 9 && move != 10
			&& move != 11)
			move++;
	}
	return (move);
}

int	possibilityz_rrr(int move, int *sep)
{
	move++;
	if (*sep == 2)
	{
		while (move != 0 && move != 3 && move != 4 && move != 8 && move != 11)
			move++;
	}
	else
	{
		while (move != 0 && move != 1 && move != 2 && move != 3
			&& move != 4 && move != 8 && move != 9 && move != 10
			&& move != 11)
			move++;
	}
	return (move);
}
