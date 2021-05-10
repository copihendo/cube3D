/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:23:56 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/09 22:26:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	ft_strcount(char const *s, char c)
// {
// 	size_t i;

// 	i = 0;
// 	while (*s++)
// 		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
// 			i++;
// 	return (i);
// }

// static size_t	ft_strlen_c(char const *s, char c)
// {
// 	size_t i;

// 	i = 0;
// 	while (s[i] && s[i] != c)
// 		i++;
// 	return (i);
// }

// static void		ft_free(char **p)
// {
// 	size_t i;

// 	i = 0;
// 	while (p[i])
// 		free(p[i++]);
// 	free(p);
// }

// char			**ft_split(char const *s, char c)
// {
// 	size_t	wc;
// 	size_t	i;
// 	char	**arr;

// 	if (!s)
// 		return (NULL);
// 	wc = ft_strcount(s, c);
// 	if (!(arr = (char **)ft_calloc(wc + 1, sizeof(char *))))
// 		return (NULL);
// 	i = 0;
// 	while (*s && i < wc)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s == '\0')
// 			break ;
// 		arr[i] = ft_substr(s, 0, ft_strlen_c(s, c));
// 		if (arr[i++] == NULL)
// 		{
// 			ft_free(arr);
// 			return (NULL);
// 		}
// 		s += ft_strlen_c(s, c);
// 	}
// 	return (arr);
// }


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

static void		ft_clean(char **s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		free(s[i]);
	free(s);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	n;
	size_t	j;
	size_t	count_non_c;

	n = -1;
	i = 0;
	if (!s || !(dst = (char **)ft_calloc(ft_nword(s, c) + 1, sizeof(char *))))
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
		j = 0;
	}
	return (dst);
}
