/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:33:00 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/26 13:49:18 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_argz_list(void)
{
	ft_putstr_fd("\nPOSSIBLE ARGUMENTS:\n", 1);
	ft_putstr_fd("=====================\n\n", 1);
	ft_putstr_fd("mandelbroot\n\n", 1);
	ft_putstr_fd("julia, x, y\n\n", 1);
}

void	scan_jul_arg(char *argv)
{
	int	z;

	z = 0;
	while (argv[z] != ',' && argv[z] != '.' && argv[z])
	{
		if (argv[z] != ',' && argv[z] != '.'
			&& argv[z] != '-' && argv[z] != '+'
			&& (argv[z] < '0' || argv[z] > '9'))
			quick_kill(JUL_ARGZ);
		if (argv[z] == '-' && (argv[z + 1] < '0' || argv[z + 1] > '9'))
			quick_kill(JUL_ARGZ);
		if (argv[z] == '+' && (argv[z + 1] < '0' || argv[z + 1] > '9'))
			quick_kill(JUL_ARGZ);
		z++;
	}
	if (argv[z] == '\0')
		return ;
	z++;
	while (argv[z])
	{
		if (argv[z] < '0' || argv[z] > '9')
			quick_kill(JUL_ARGZ);
		z++;
	}
}

void	check_jul_argz(int argc, char **argv)
{
	int	z;

	z = 0;
	if (argc != 4)
		quick_kill(NB_ARGZ);
	scan_jul_arg(argv[2]);
	scan_jul_arg(argv[3]);
}

void	error_check(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd(NB_ARGZ, 1);
		print_argz_list();
		quick_kill(NULL);
	}
	if (argc == 2 && ft_strncmp("mandelbroot", argv[1], 11) == 0)
		return ;
	if (ft_strncmp("julia", argv[1], 11) == 0)
	{
		check_jul_argz(argc, argv);
		return ;
	}
	print_argz_list();
	quick_kill(NULL);
}
