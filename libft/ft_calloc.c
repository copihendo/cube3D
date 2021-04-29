/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:12:52 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/19 13:48:27 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *arr;

	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	if (!(arr = malloc(count * size)))
		return (NULL);
	ft_bzero(arr, count * size);
	return (arr);
}
