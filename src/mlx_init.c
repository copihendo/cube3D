/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:22:51 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/03 21:29:03 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*// void print_box(t_data img, int x, int y, int zoom, int color) // ф-ия отрисовывает зуммированный box для 2d карты
// {
// 	int i;
// 	int j;
// 	int k;

// 	i = 1;
// 	k = x;
// 	while(i <= zoom)
// 	{
// 		x = k;
// 		j = 1;
// 		while (j <= zoom)
// 		{
// 			my_mlx_pixel_put(&img, x, y, color);
// 			x++;
// 			j++;
// 		}
// 		y++;
// 		i++;
// 	}
// }*/

void			ft_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bits_pix / 8));
		*(unsigned int*)dst = color;
}


////////////////////////////////////////////
//////// 							////////	
////////	 Drawing floor & ceil 	////////
////////		 					////////
////////////////////////////////////////////
void ft_drw_flr_ceil(t_base *base)
{
	int middle;
	int x = 0;
	int y = 0;
	middle = base->height_screen / 2 ;
	printf("drow floor cail height %d middle %d", base->height_screen, middle);
				/////////// FIRST VERSION floor and ceil
/*	// while (y < middle)
	// {
	// 	x = 1;
	// 	while(x < base.width_screen)
	// 	{	
	// 		my_mlx_pixel_put(&img, x, y, 0x0000BFFF); // закрашиваем потолок. вставить цвет из структуры
	// 		x++;
	// 	}
	// 	y++;
	// }
	// while (y >= middle && y < base.height_screen)  
	// {
	// 	x = 1;
	// 	while(x < base.width_screen)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF8C00); // закрашиваем под. вставить цвет из структуры
	// 		x++;
	// 	}
	// 	y++;
	// }*/
	
					/////////// SECOND VERSION
	while (y < base->height_screen)
	{
		x = 0;
		while(x < base->width_screen)
		{	
			if (y < middle)
				ft_mlx_pixel_put(&base->textures.screen, x, y, 0x0000BFFF); // закрашиваем потолок. вставить цвет из структуры
				// ft_mlx_pixel_put(base, x, y, base->floor); // закрашиваем потолок. вставить цвет из структуры
			if (y >= middle)
				// ft_mlx_pixel_put(base, x, y, base->ceil); // закрашиваем пол. вставить цвет из структуры
				ft_mlx_pixel_put(&base->textures.screen, x, y, 0x00FF8C00); // закрашиваем пол. вставить цвет из структуры
			x++;
		}
		y++;
	}
}

// _____________________ MOio





void	ft_mlx(t_base *base)
{	
	base->mlx_win = mlx_new_window(base->mlx_ptr, base->width_screen, base->height_screen, "CUBE_RUBE!");
	base->textures.screen.link = mlx_new_image(base->mlx_ptr, base->width_screen, base->height_screen);
	base->textures.screen.addr = mlx_get_data_addr(base->textures.screen.link, &base->textures.screen.bits_pix, \
						&base->textures.screen.line_len, &base->textures.screen.endian);
	// ft_mlx_2d

	ft_drw_flr_ceil(base);
		ft_mlx_pixel_put(&base->textures.screen, 50, 50, 0x00FFFF00);
		ft_mlx_pixel_put(&base->textures.screen, 51, 51, 0x0000BFFF);
	
	mlx_put_image_to_window(base->mlx_ptr, base->mlx_win, base->textures.screen.link, 0, 0);
	mlx_loop(base->mlx_ptr);


	ft_init_textur(base); // ??
	ft_init_sprites(base); // ??
	mlx_loop_hook(base->mlx_ptr, ft_swap_frame, base);
	mlx_hook(base->mlx_win, 2, 1L << 0, ft_key_in, base);
	mlx_hook(base->mlx_win, 3, 1L << 0, ft_key_out, base);
	mlx_hook(base->mlx_win, 17, 0, ft_close, base); 
	mlx_do_key_autorepeatoff(base->mlx_ptr);
	mlx_loop(base->mlx_ptr);
}