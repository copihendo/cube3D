/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:39:19 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/02 16:13:42 by mguadalu         ###   ########.fr       */
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

/*// void			ft_mlx_pixel_put(t_base *base, int x, int y, t_color color)
// {
// 	t_color	*dst;

// 	// dst = base->textures.screen.link + (y * base->width_screen + x * (base->textures.screen.bits_pix / 8));
// 	dst = base->textures.screen.link + (y * base->width_screen + x);
// 	*dst = color;
// 	// void		ft_my_pixel_put(t_all *all, int x, int y, t_color color)
// 	// {
// 	// 	t_color *dst;

// 	// 	dst = all->img.screen.addr + (y * all->conf.res_x + x);
// 	// 	*dst = color;
// 	// }
// }*/

typedef struct  s_data {
	void		*img;
	char		*addr;
	int			bits_pix;
	int			line_len;
	int			endian;
}				t_data;

// void			ft_mlx_pixel_put(t_image *image, int x, int y, int color)
void			ft_mlx_pixel_put(t_data *image, int x, int y, int color)
{
	char	*dst;

	// dst = image->link + (y * image->line_len + x * (image->bits_pix / 8));
	dst = image->addr + (y * image->line_len + x * (image->bits_pix / 8));
	// dst = base->textures.screen.link + (y * base->width_screen + x);
		*(unsigned int*)dst = color;
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_pix / 8));
	*(unsigned int*)dst = color;
}

////////////////////////////////////////////
//////// 							////////	
////////	 Drawing floor & ceil 	////////
////////		 					////////
////////////////////////////////////////////
// void ft_drw_flr_ceil(t_base *base)
// {
// 	int middle;
// 	int x = 0;
// 	int y = 0;
// 	middle = base->height_screen / 2 ;
// 	printf("drow floor cail height %d middle %d", base->height_screen, middle);
// 				/////////// FIRST VERSION floor and ceil
// /*	// while (y < middle)
// 	// {
// 	// 	x = 1;
// 	// 	while(x < base.width_screen)
// 	// 	{	
// 	// 		my_mlx_pixel_put(&img, x, y, 0x0000BFFF); // закрашиваем потолок. вставить цвет из структуры
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	// while (y >= middle && y < base.height_screen)  
// 	// {
// 	// 	x = 1;
// 	// 	while(x < base.width_screen)
// 	// 	{
// 	// 		my_mlx_pixel_put(&img, x, y, 0x00FF8C00); // закрашиваем под. вставить цвет из структуры
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }*/
	
// 					/////////// SECOND VERSION
// 	while (y < base->height_screen)
// 	{
// 		x = 0;
// 		while(x < base->width_screen)
// 		{	
// 			if (y < middle)
// 				ft_mlx_pixel_put(base, x, y, 0x0000BFFF); // закрашиваем потолок. вставить цвет из структуры
// 				// ft_mlx_pixel_put(base, x, y, base->floor); // закрашиваем потолок. вставить цвет из структуры
// 			if (y >= middle)
// 				// ft_mlx_pixel_put(base, x, y, base->ceil); // закрашиваем пол. вставить цвет из структуры
// 				ft_mlx_pixel_put(base, x, y, 0x00FF8C00); // закрашиваем пол. вставить цвет из структуры
// 			x++;
// 		}
// 		y++;
// 	}
// }


void	ft_mlx(t_base *base)
{
	t_data img;
	img.bits_pix = 32;
	img.line_len = 10;
	img.endian = 5;
	
	// int i = base->height_screen;
	// printf("height screen %d", i);
	// write(1, &i, 4);

							//????? kuda eto devat'
	base->textures.screen.bits_pix = 32;
	base->textures.screen.line_len = 10;
	base->textures.screen.endian = 5;
							//????? kuda eto devat'
		
	base->mlx_win = mlx_new_window(base->mlx_ptr, base->width_screen, base->height_screen, "CUBE_RUBE!");
	base->textures.screen.link = mlx_new_image(base->mlx_ptr, base->width_screen, base->height_screen);
/*base->textures.screen.color = (t_color *)mlx_get_data_addr(base->textures.screen.link, &base->textures.screen.bits_pix, \*/
	base->textures.screen.addr = mlx_get_data_addr(base->textures.screen.link, &base->textures.screen.bits_pix, \
						&base->textures.screen.line_len, &base->textures.screen.endian);
	// ft_mlx_pixel_put(&base->textures.screen, 50, 50, 0x00FFFF00);
	// mlx_put_image_to_window(base->mlx_ptr, base->mlx_win, base->textures.screen.link, 0, 0);
	// ft_mlx_pixel_put(base, 50, 50, &base->textures.s.color);
	
	// ft_drw_flr_ceil(base);
	// ft_mlx_2d

	img.img = mlx_new_image(base->mlx_ptr, base->width_screen, base->height_screen);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pix, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, 51, 51, 0x0000BFFF);
	ft_mlx_pixel_put(&img, 50, 50, 0x00FFFF00);
	// ft_mlx_pixel_put(&base->textures.screen, 50, 50, 0x00FFFF00);
	mlx_put_image_to_window(base->mlx_ptr, base->mlx_win, img.img, 0, 0);
	mlx_loop(base->mlx_ptr);
}




int main(int cnt_arg, const char **arguments)
{
	t_base base;
	
	
	ft_bzero(&base, sizeof(t_base)); 
	if (cnt_arg == 1)
		return (1);
	base.mlx_ptr = mlx_init();
	ft_parse(&base, arguments[1]);
	ft_mlx(&base);
}