/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:23:56 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/21 17:49:59 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcount(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s++)
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
	return (i);
}

static size_t	ft_strlen_c(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void		ft_free(char **p)
{
	size_t i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

char			**ft_split(char const *s, char c)
{
	size_t	wc;
	size_t	i;
	char	**arr;

	if (!s)
		return (NULL);
	wc = ft_strcount(s, c);
	if (!(arr = (char **)ft_calloc(wc + 1, sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s && i < wc)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		arr[i] = ft_substr(s, 0, ft_strlen_c(s, c));
		if (arr[i++] == NULL)
		{
			ft_free(arr);
			return (NULL);
		}
		s += ft_strlen_c(s, c);
	}
	return (arr);
}
