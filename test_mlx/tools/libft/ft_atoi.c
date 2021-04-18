/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:09:09 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/21 17:14:40 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int strs)
{
	return ((9 <= strs && strs <= 13) || strs == ' ');
}

int			ft_atoi(const char *str)
{
	long long int	res;
	int				har;

	har = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			har *= -1;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	return (har * res);
}
