/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book_of_knowledge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:12:46 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:14:17 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(int move)
{
	if (move == 0)
		ft_putstr("sa\n");
	else if (move == 1)
		ft_putstr("sb\n");
	else if (move == 2)
		ft_putstr("ss\n");
	else if (move == 3)
		ft_putstr("pb\n");
	else if (move == 4)
		ft_putstr("pa\n");
	else if (move == 5)
		ft_putstr("ra\n");
	else if (move == 6)
		ft_putstr("rb\n");
	else if (move == 7)
		ft_putstr("rr\n");
	else if (move == 8)
		ft_putstr("rra\n");
	else if (move == 9)
		ft_putstr("rrb\n");
	else
		ft_putstr("rrr\n");
}

void	read_the_book(int *book_of_knowledge)
{
	int	page;

	page = 0;
	while (book_of_knowledge[page] != -1)
	{
		print_moves(book_of_knowledge[page]);
		page++;
	}
	free (book_of_knowledge);
}

int	book_of_knowledge(int loop, int move)
{
	static int	*book_of_knowledge;
	static int	start = 0;

	if (start == 0)
	{	
		book_of_knowledge = malloc((loop + 2) * sizeof(int));
		book_of_knowledge[loop + 1] = -1;
		start = 1;
	}
	book_of_knowledge[loop] = move;
	if (loop == 0)
		read_the_book(book_of_knowledge);
	return (1);
}
