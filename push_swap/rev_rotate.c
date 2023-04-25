/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:42:06 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:42:21 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_a(int *pos_tracker, int *sep)
{
	int	last;
	int	tmp;

	last = last_index(-1) - 1;
	tmp = pos_tracker[last];
	while (last > *sep)
	{
		pos_tracker[last] = pos_tracker[last - 1];
		last--;
	}
	pos_tracker[*sep] = tmp;
}

void	rev_rot_b(int *pos_tracker, int *sep)
{
	int	tmp;
	int	z;

	z = 0;
	tmp = pos_tracker[0];
	while (z < *sep - 1)
	{
		pos_tracker[z] = pos_tracker[z + 1];
		z++;
	}
	pos_tracker[*sep - 1] = tmp;
}

void	rrr(int *pos_tracker, int *sep)
{
	rev_rot_a(pos_tracker, sep);
	rev_rot_b(pos_tracker, sep);
}
