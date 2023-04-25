/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:47:37 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:49:04 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_move(int *pos_tracker, int move, int *sep)
{		
	if (move == 0)
		swap(pos_tracker, sep, 1);
	else if (move == 1)
		swap(pos_tracker, sep, 2);
	else if (move == 2)
		swap(pos_tracker, sep, 3);
	else if (move == 3)
		push(sep, 2);
	else if (move == 4)
		push(sep, 1);
	else if (move == 5)
		rotate_a(pos_tracker, sep);
	else if (move == 6)
		rotate_b(pos_tracker, sep);
	else if (move == 7)
		rr(pos_tracker, sep);
	else if (move == 8)
		rev_rot_a(pos_tracker, sep);
	else if (move == 9)
		rev_rot_b(pos_tracker, sep);
	else if (move == 10)
		rrr(pos_tracker, sep);
}

void	reverse_move(int *pos_tracker, int move, int *sep)
{
	if (move == 0)
		swap(pos_tracker, sep, 1);
	else if (move == 1)
		swap(pos_tracker, sep, 2);
	else if (move == 2)
		swap(pos_tracker, sep, 3);
	else if (move == 3)
		push(sep, 1);
	else if (move == 4)
		push(sep, 2);
	else if (move == 5)
		rev_rot_a(pos_tracker, sep);
	else if (move == 6)
		rev_rot_b(pos_tracker, sep);
	else if (move == 7)
		rrr(pos_tracker, sep);
	else if (move == 8)
		rotate_a(pos_tracker, sep);
	else if (move == 9)
		rotate_b(pos_tracker, sep);
	else if (move == 10)
		rr(pos_tracker, sep);
}

int	last_index(int opt)
{
	static int	last_index;

	if (opt != -1)
		last_index = opt;
	return (last_index);
}

t_list	*lstnew(int content)
{
	t_list	*nw;

	nw = malloc(sizeof(t_list));
	nw->move = content;
	nw->next = NULL;
	return (nw);
}

void	lstadd_back(t_list **head, t_list *nw)
{
	t_list	*tmp;

	tmp = *head;
	if (!*head)
		*head = nw;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nw;
	}
}
