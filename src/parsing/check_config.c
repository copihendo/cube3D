/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:28:11 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/16 19:27:36 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int ft_check_config(t_base *base)
{
	if (base->width_screen != 0 && base->height_screen != 0)
		return (1);
	else
		return (0);
}