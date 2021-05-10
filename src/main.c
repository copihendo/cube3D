/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:39:19 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/09 21:28:35 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int ft_check_arg(int ac, char **av, t_base *base)
{
	// static char *ext = ".cub";
	int i;
	
	if (ac < 2 || ac > 3)
		write(1, "invalid number of input arguments\n", 34);
	if (ac == 2)
	{
		i = ft_strlen(av[1]) - 4;
		if (ft_strcmp(".cub", &av[1][i]))
		{
			write(1, "invalid input arguments\n", 24);
			return (1);
		}
	}	
	if(ac == 3)
	{
		if (ft_strncmp("--save", av[2], 7))
		{
			write(1, "invalid save attempt\n", 24);
			return (1);
		}
		base->flag_bmp = 1;
	}
	return (0);
}

int main(int cnt_arg, char **arguments)
{
	t_base base;
	
	ft_bzero(&base, sizeof(t_base)); 
	// if (cnt_arg == 1)
	// 	return (1);
	if(ft_check_arg(cnt_arg, arguments, &base))
		return (1);
	base.mlx_ptr = mlx_init();
	ft_parse(&base, arguments[1]);
	ft_mlx(&base);
	if(base.flag_bmp == 0)
		mlx_loop(base.mlx_ptr);
	else
	{
		ft_tick(&base);
		ft_screenshot(&base);
	}
	ft_exit(&base, "Game over");
	return(0);
}