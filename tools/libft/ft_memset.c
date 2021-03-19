/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:47:35 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/19 14:00:32 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*br;
	size_t			i;

	br = dst;
	i = 0;
	while (i < len)
	{
		br[i] = (unsigned char)c;
		i++;
	}
	return (br);
}
