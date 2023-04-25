/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:37:24 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 11:38:50 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_left(t_data *data)
{
	static double	diff = 0;

	if (data->x1 >= 0 && diff == 0)
		diff = (data->x1 * 1.1) - data->x1;
	else if (diff == 0)
		diff = (data->x1 * -1.1) - (data->x1 * -1);
	data->x1 = data->x1 - diff;
	data->x2 = data->x2 - diff;
}

void	move_right(t_data *data)
{
	static double	diff = 0;

	if (data->x2 >= 0 && diff == 0)
		diff = (data->x2 * 1.1) - data->x2;
	else if (diff == 0)
		diff = (data->x2 * -1.1) - (data->x2 * -1);
	data->x1 = data->x1 + diff;
	data->x2 = data->x2 + diff;
}

void	move_up(t_data *data)
{
	static double	diff = 0;

	if (data->y1 >= 0 && diff == 0)
		diff = (data->y1 * 1.1) - data->y1;
	else if (diff == 0)
		diff = (data->y1 * -1.1) - (data->y1 * -1);
	data->y1 = data->y1 - diff;
	data->y2 = data->y2 - diff;
}

void	move_down(t_data *data)
{
	static double	diff = 0;

	if (data->y2 >= 0 && diff == 0)
		diff = (data->y2 * 1.1) - data->y2;
	else if (diff == 0)
		diff = (data->y2 * -1.1) - (data->y2 * -1);
	data->y1 = data->y1 + diff;
	data->y2 = data->y2 + diff;
}

void	move(int keycode, t_data *data)
{
	if (keycode == XK_Left)
		move_left(data);
	else if (keycode == XK_Right)
		move_right(data);
	else if (keycode == XK_Up)
		move_up(data);
	else if (keycode == XK_Down)
		move_down(data);
	create_img(data, data->fract_type);
	push_img(data);
}
