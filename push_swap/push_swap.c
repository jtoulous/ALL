/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:36:52 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:38:30 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	*simplify(int *argz)
{
	int	x;
	int	*simplified;

	x = 0;
	simplified = malloc(sizeof(int) * (last_index(-1) + 1));
	if (!simplified)
		return (NULL);
	while (x < last_index(-1))
	{
		simplified[x] = position_of_x(argz, x);
		x++;
	}
	free (argz);
	return (simplified);
}	

int	*remaster(int argc, char **argv)
{
	int	*argz;
	int	*remastered;

	argz = errorz(argc, argv);
	if (!argz)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	remastered = simplify(argz);
	if (!remastered)
		return (NULL);
	return (remastered);
}

int	last_check(int *tab_remastered)
{
	int	z;
	int	y;
	int	last;

	z = 0;
	y = 1;
	last = last_index(-1);
	while (z < last)
	{
		while (y < last)
		{
			if (tab_remastered[y] < tab_remastered[z])
				return (1);
			y++;
		}
		z++;
		y = z + 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*tab_remastered;
	int	*sep;
	int	separator;

	separator = 0;
	sep = &separator;
	tab_remastered = remaster(argc, argv);
	if (!tab_remastered)
		return (0);
	if (last_check(tab_remastered) != 1)
	{	
		free (tab_remastered);
		return (0);
	}
	if (last_index(-1) > 5)
		radix(tab_remastered, sep);
	else
		broute_force(tab_remastered, sep);
	return (0);
}
