/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:38:56 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:33:01 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	smb;
	char	*p;

	p = 0;
	smb = (char)c;
	while (*s)
	{
		if (*s == smb)
			p = s;
		s++;
	}
	if (smb == '\0')
		return (s);
	return (p);
}
