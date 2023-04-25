/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_remaster_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:42 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:22:58 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_signs(char *argv, int z, int y)
{
	while (argv[z])
	{
		if (argv[z] == '-' || argv[z] == '+')
		{
			y = z - 1;
			z++;
			while (argv[z])
			{
				if ((argv[z] < '0' || argv[z] > '9') && argv[z] != ' ')
					return (0);
				z++;
			}
			while (y >= 0)
			{
				if (argv[y] != ' ')
					return (0);
				y--;
			}
			return (1);
		}
		z++;
	}
	return (1);
}

int	check_signs_two(char *argv)
{
	int	z;

	z = 0;
	while (argv[z] != '-' && argv[z] != '+' && argv[z])
		z++;
	if (argv[z] == '\0')
		return (1);
	if (argv[z + 1] < '0' || argv[z + 1] > '9')
		return (0);
	return (1);
}

int	check_arg_in_str(char *argv)
{
	int	z;

	z = 0;
	while (argv[z] == ' ')
		z++;
	if (check_signs(argv, 0, 0) != 1 || check_signs_two(argv) != 1)
		return (0);
	if (argv[z] == '-')
		z++;
	while (argv[z])
	{
		if ((argv[z] < '0' || argv[z] > '9') && argv[z] != ' '
			&& argv[z] != '+' && argv[z] != '-')
			return (0);
		z++;
	}
	if (compare_limitz_int(argv, "2147483647") != 1)
		return (0);
	return (1);
}

int	check_arg_in_int(int *argz, int z)
{
	int	x;
	int	y;

	y = 1;
	x = 0;
	while (x < z)
	{
		while (y < z)
		{
			if (argz[y] == argz[x])
				return (0);
			y++;
		}
		x++;
		y = x + 1;
	}
	return (1);
}
