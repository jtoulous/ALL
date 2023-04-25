/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:41:55 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 11:42:06 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	new_values(t_data *data, int x, int y, int opt)
{		
	if (opt == 1)
	{	
		data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.1));
		data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.1));
		data->max_iter += 1;
		data->zoom *= 1.1;
	}
	else
	{	
		data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.1));
		data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.1));
		data->max_iter -= 1;
		data->zoom /= 1.1;
	}
	return (1);
}

void	zoom(t_data *data, int x, int y, int opt)
{
	if (new_values(data, x, y, opt) == 1)
	{
		create_img(data, data->fract_type);
		push_img(data);
	}
}
