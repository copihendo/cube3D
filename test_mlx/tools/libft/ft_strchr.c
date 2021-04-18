/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:10:08 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/21 17:05:29 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char smb;

	smb = (char)c;
	while (*s)
	{
		if (*s == smb)
			return ((char*)s);
		s++;
	}
	if (smb == '\0')
		return ((char*)s);
	return (0);
}
