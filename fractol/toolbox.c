/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:38:57 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 11:41:50 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pxl_put(t_data *data, int x, int y, int color)
{
	char	*pix;

	pix = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)pix = color;
}

int	value_check(t_data *data)
{
	double	res;

	res = data->z_r * data->z_r + data->z_i * data->z_i;
	if (res >= 4)
		return (0);
	return (1);
}

void	create_img(t_data *data, int opt)
{
	data->img = mlx_new_image(data->mlx, win_size('x', opt),
			win_size('y', opt));
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	if (opt == 1)
		draw_mandel(data);
	if (opt == 2)
		draw_julia(data);
}

void	push_img(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

int	win_size(char val, int opt)
{
	static int	x_mandel = 810;
	static int	y_mandel = 720;
	static int	x_jul = 600;
	static int	y_jul = 720;

	if (opt == 1)
	{
		if (val == 'x')
			return (x_mandel);
		return (y_mandel);
	}
	if (opt == 2)
	{
		if (val == 'x')
			return (x_jul);
		return (y_jul);
	}
	return (0);
}
