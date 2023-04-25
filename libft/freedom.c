/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:28 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 16:44:34 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_loop(char **str)
{
	int	z;

	z = 0;
	if (str)
	{
		while (str[z])
		{
			free (str[z]);
			z++;
		}
		free (str);
	}
}

void	free_free(void *str1, void *str2)
{
	free (str1);
	free (str2);
}
