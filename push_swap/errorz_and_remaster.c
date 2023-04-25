/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorz_and_simplify.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:14:46 by jtoulous          #+#    #+#             */
/*   Updated: 2022/12/20 11:17:01 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	for_min_int(char *argv, int z, char *min_int)
{
	int	y;

	z++;
	y = 0;
	while (argv[z] && min_int[y])
	{
		if (argv[z] > min_int[y])
			return (0);
		if (argv[z] < min_int[y])
			return (1);
		z++;
		y++;
	}
	if (argv[z] != ' ' && argv[z] != '\0')
		return (0);
	return (1);
}

int	count_lenght(char *argv)
{
	int	count;
	int	z;

	z = 0;
	count = 1;
	while (argv[z] < '0' || argv[z] > '9')
		z++;
	while (argv[z] >= '0' && argv[z] <= '9')
	{
		count++;
		z++;
	}
	if (count <= 10)
		return (1);
	return (0);
}

int	compare_limitz_int(char *argv, char *max_int)
{
	int	z;
	int	y;

	z = 0;
	y = 0;
	if (count_lenght(argv) == 1)
		return (1);
	while (argv[z] == ' ')
		z++;
	if (argv[z] == '-')
		return (for_min_int(argv, z, "2147483648"));
	while (argv[z] && max_int[y])
	{
		if (argv[z] > max_int[y])
			return (0);
		if (argv[z] < max_int[y])
			return (1);
		z++;
		y++;
	}
	if (argv[z] != ' ' && argv[z] != '\0')
		return (0);
	return (1);
}

int	find_smallest(int *argz)
{
	int	z;
	int	top_stck;

	z = 0;
	top_stck = 0;
	while (z != last_index(-1))
	{
		if (argz[z] < argz[top_stck])
			top_stck = z;
		z++;
	}
	return (top_stck);
}

int	*errorz(int argc, char **argv)
{
	int	*argz;
	int	z;

	z = 1;
	if (argc <= 2)
		return (NULL);
	argz = malloc(sizeof(int) * (argc + 1));
	if (!argz)
		return (NULL);
	while (z < argc)
	{
		if (argv[z][0] == '\0' || check_arg_in_str(argv[z]) != 1)
			return (exit_error(argz));
		argz[z - 1] = atoi(argv[z]);
		z++;
	}
	last_index(z - 1);
	if (check_arg_in_int(argz, z - 1) != 1)
		return (exit_error(argz));
	return (argz);
}
