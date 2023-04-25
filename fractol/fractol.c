/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:33:59 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 11:34:01 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	error_check(argc, argv);
	if (ft_strncmp("mandelbroot", argv[1], 11) == 0)
		mandel();
	if (ft_strncmp("julia", argv[1], 5) == 0)
		julia(ft_atof(argv[2]), ft_atof(argv[3]));
	return (0);
}
