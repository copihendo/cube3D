/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:18:07 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:23:36 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*uparr;

	uparr = (unsigned char *)arr;
	while (n--)
	{
		if (*uparr == (unsigned char)c)
			return (uparr);
		uparr++;
	}
	return (NULL);
}
