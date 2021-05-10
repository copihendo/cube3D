/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:23:56 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 21:19:06 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nword(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static size_t	ln(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	ft_clean(char **s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		free(s[i]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	n;
	size_t	count_non_c;

	n = -1;
	i = 0;
	dst = (char **)ft_calloc(ft_nword(s, c) + 1, sizeof(char *));
	if (!s || !dst)
		return (NULL);
	while (++n < ft_nword(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		count_non_c = ln(s + i, c);
		dst[n] = ft_substr(s, i, count_non_c);
		if (!dst[n])
		{
			ft_clean(dst);
			return (NULL);
		}
		i += count_non_c;
	}
	return (dst);
}
