/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:47:00 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:47:03 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *pos_tracker, int *sep, int opt)
{	
	int	tmp;

	if (opt == 1 || opt == 3)
	{	
		tmp = pos_tracker[*sep];
		pos_tracker[*sep] = pos_tracker[*sep + 1];
		pos_tracker[*sep + 1] = tmp;
	}
	if (opt == 2 || opt == 3)
	{
		tmp = pos_tracker[*sep - 1];
		pos_tracker[*sep - 1] = pos_tracker[*sep - 2];
		pos_tracker[*sep - 2] = tmp;
	}	
}
