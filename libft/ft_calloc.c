/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:12:52 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:18:51 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	arr = malloc(count * size);
	if (!(arr))
		return (NULL);
	ft_bzero(arr, count * size);
	return (arr);
}
