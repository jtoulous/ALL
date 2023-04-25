/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broute_force.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:23:50 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:26:24 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_tracker(int *pos_tracker, int opt)
{
	static int	*pos_tab;

	if (opt == -1)
	{
		pos_tab = pos_tracker;
		return (NULL);
	}
	return (pos_tab);
}

void	broute_force(int *pos_tracker, int *sep)
{
	int	max_moves;
	int	rek_check;

	rek_check = 0;
	stack_tracker(pos_tracker, -1);
	max_moves = 1;
	while (rek_check != 1)
	{
		rek_check = rek_me_daddy(max_moves, 0, -1, sep);
		*sep = 0;
		max_moves++;
	}
	free(pos_tracker);
}

int	security_check(int *sep, int loop, int max_moves)
{
	static int	last;

	if (!last)
		last = last_index(-1);
	if (loop > max_moves || *sep > (last - last / 4))
		return (0);
	return (1);
}

int	rek_me_daddy(int max_moves, int loop, int prev, int *sep)
{
	int			move;
	int			dd_check;
	static int	*pos_tracker;

	if (!pos_tracker)
		pos_tracker = stack_tracker(NULL, 1);
	dd_check = 0;
	move = -1;
	if (security_check(sep, loop, max_moves) != 1)
		return (2);
	while (move < 11)
	{
		move = randomness_optimization(move, prev, sep, loop);
		if (move != 11)
		{
			apply_move(pos_tracker, move, sep);
			if (check_soluce(pos_tracker, sep) == 1
				|| rek_me_daddy(max_moves, loop + 1, move, sep) == 1)
				return (book_of_knowledge(loop, move));
			reverse_move(pos_tracker, move, sep);
		}	
	}
	return (0);
}

int	randomness_optimization(int move, int prev, int *sep, int loop)
{
	if (loop == 0)
		return (first_move(move));
	if (prev == 0)
		return (possibilityz_sa(move, sep));
	if (prev == 1)
		return (possibilityz_sb(move, sep));
	if (prev == 2)
		return (possibilityz_ss(move, sep));
	if (prev == 3)
		return (possibilityz_pb(move, sep));
	if (prev == 4)
		return (possibilityz_pa(move, sep));
	if (prev == 5)
		return (possibilityz_ra(move, sep));
	if (prev == 6)
		return (possibilityz_rb(move, sep));
	if (prev == 7)
		return (possibilityz_rr(move, sep));
	if (prev == 8)
		return (possibilityz_rra(move, sep));
	if (prev == 9)
		return (possibilityz_rrb(move, sep));
	if (prev == 10)
		return (possibilityz_rrr(move, sep));
	return (11);
}
