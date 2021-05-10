/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:50:05 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:32:20 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*arr;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	arr = (char *)malloc(i + 1);
	if (!arr)
		return (NULL);
	arr[i] = '\0';
	while (i--)
		arr[i] = f(i, s[i]);
	return (arr);
}
