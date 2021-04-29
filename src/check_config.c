/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:28:11 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/29 21:47:15 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int ft_check_config(t_base base)
{
	write(1, "ckeck_config1\n", 14);
	if (base.width_screen != 0 && base.height_screen != 0)
	{write(1, "ckeck_config2\n", 14);
		return (0);}
	else
	{write(1, "ckeck_config3\n", 14);
		return (1);}
}