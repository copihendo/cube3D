/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:07:31 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/19 17:31:19 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int cx)
{
	if ((cx >= 'A' && cx <= 'Z') || (cx >= 'a' && cx <= 'z'))
		return (1);
	return (0);
}