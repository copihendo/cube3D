/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:45:14 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/19 17:34:07 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*updst;
	unsigned char	*upsrc;
	size_t			i;

	updst = (unsigned char*)dst;
	upsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		updst[i] = upsrc[i];
		if (upsrc[i] == (unsigned char)c)
			return (&dst[++i]);
		i++;
	}
	return (NULL);
}
