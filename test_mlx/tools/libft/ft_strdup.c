/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:36:41 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/19 14:02:16 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*s2;

	i = 0;
	size = ft_strlen(s1) + 1;
	if (!(s2 = (char*)malloc(size)))
		return (NULL);
	ft_strlcpy(s2, s1, size);
	return (s2);
}
