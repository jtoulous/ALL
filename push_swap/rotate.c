/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:42:51 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:43:37 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *pos_tracker, int *sep)
{
	int	tmp;
	int	z;
	int	start;

	z = last_index(-1) - 1;
	tmp = pos_tracker[*sep];
	start = *sep;
	while (start < z)
	{
		pos_tracker[start] = pos_tracker[start + 1];
		start++;
	}
	pos_tracker[start] = tmp;
}	

void	rotate_b(int *pos_tracker, int *sep)
{
	int	tmp;
	int	z;
	int	start;

	start = *sep - 1;
	z = 0;
	tmp = pos_tracker[start];
	while (start >= 1)
	{
		pos_tracker[start] = pos_tracker[start - 1];
		start--;
	}
	pos_tracker[0] = tmp;
}	

void	rr(int *pos_tracker, int *sep)
{
	rotate_a(pos_tracker, sep);
	rotate_b(pos_tracker, sep);
}
