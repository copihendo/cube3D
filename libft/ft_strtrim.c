/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:02:48 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/26 12:18:38 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	char	*start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	start = (char*)s1;
	end = ft_strlen(s1);
	while (end && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	arr = ft_substr((char*)s1, 0, end);
	return (arr);
}
