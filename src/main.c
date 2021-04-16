/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:39:19 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/16 15:15:04 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



int main(int cnt_arg, const char **arguments)
{
	t_base base;
	ft_bzero(&base, sizeof(t_base));  
	if (cnt_arg == 1)
		return (1);
	base.mlx_ptr = mlx_init();
	ft_parse(base, arguments[1]);
}