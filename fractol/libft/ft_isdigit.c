/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:12 by jtoulous          #+#    #+#             */
/*   Updated: 2022/09/28 14:11:25 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int z)
{
	if (z >= '0' && z <= '9')
		return (1);
	return (0);
}
