/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:35:35 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:24:09 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*upsrc;
	unsigned char	*updst;

	upsrc = (unsigned char *)src;
	updst = (unsigned char *)dst;
	if (dst == src || n == 0)
		return (dst);
	while (n--)
		*updst++ = *upsrc++;
	return (dst);
}
