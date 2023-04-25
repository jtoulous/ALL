/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilityz_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:28:04 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:31:23 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_move(int move)
{
	move++;
	while (move != 0 && move != 3 && move != 5 && move != 8 && move != 11)
		move++;
	return (move);
}

int	possibilityz_sa(int move, int *sep)
{
	move++;
	if (*sep == 0)
	{
		while (move != 3 && move != 5 && move != 8 && move != 11)
			move++;
	}
	else if (*sep == 1)
	{
		while (move != 3 && move != 4 && move != 5 && move != 8 && move != 11)
			move++;
	}
	else
	{
		while (move != 3 && move != 4 && move != 5
			&& move != 6 && move != 7 && move != 8
			&& move != 9 && move != 10 && move != 11)
			move++;
	}
	return (move);
}

int	possibilityz_sb(int move, int *sep)
{
	move++;
	if (*sep == 2)
	{
		while (move != 3 && move != 4 && move != 5 && move != 8 && move != 11)
			move++;
	}
	else
	{	
		while (move != 3 && move != 4 && move != 5
			&& move != 6 && move != 7 && move != 8
			&& move != 9 && move != 10 && move != 11)
			move++;
	}
	return (move);
}

int	possibilityz_ss(int move, int *sep)
{
	move++;
	if (*sep == 2)
	{
		while (move != 3 && move != 4 && move != 5 && move != 8 && move != 11)
			move++;
	}
	else
	{	
		while (move != 3 && move != 4 && move != 5
			&& move != 6 && move != 7 && move != 8
			&& move != 9 && move != 10 && move != 11)
			move++;
	}
	return (move);
}

int	possibilityz_pa(int move, int *sep)
{
	move++;
	if (*sep == 0)
	{
		while (move != 0 && move != 5 && move != 8 && move != 11)
			move++;
	}
	else if (*sep == 1)
	{
		while (move != 0 && move != 4 && move != 5 && move != 8 && move != 11)
			move++;
	}
	else
	{
		while (move != 0 && move != 1 && move != 2 && move != 4
			&& move != 5 && move != 6 && move != 7 && move != 8
			&& move != 9 && move != 10 && move != 11)
			move++;
	}
	return (move);
}
