/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:18:54 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/03 17:19:02 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*fnl;

	fnl = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (fnl == 0)
		return (0);
	ft_strlcpy(fnl, s1, ft_strlen(s1) + 1);
	ft_strlcat(fnl, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (fnl);
}
