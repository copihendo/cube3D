/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:09:16 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:24:25 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t n)
{
	unsigned char	*updst;
	unsigned char	*upsrc;

	updst = (unsigned char *)dst;
	upsrc = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (upsrc < updst)
		while (n--)
			updst[n] = upsrc[n];
	else
	{
		while (n--)
			*updst++ = *upsrc++;
	}
	return (dst);
}
