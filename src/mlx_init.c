/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:22:51 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/09 20:26:34 by telron           ###   ########.fr       */
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

void			ft_mlx_pixel_put(t_image *image, int x, int y, t_color color)
{
	t_color	*dst;

	dst = image->data + (y * image->width + x);
	*dst = color;
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

	t_color color;

	middle = base->height_screen / 2 ;
	// printf("drow floor cail height %d middle %d", base->height_screen, middle);
	
	while (y < base->height_screen)
	{
		x = 0;
		while(x < base->width_screen)
		{	
			if (y <= middle)
				color = base->floor;
				// ft_mlx_pixel_put(&base->textures.screen, x, y, 0x0000BFFF); // закрашиваем потолок. вставить цвет из структуры
				// ft_mlx_pixel_put(base, x, y, base->floor); // закрашиваем потолок. вставить цвет из структуры
			else
				color = base->ceil;
				// ft_mlx_pixel_put(base, x, y, base->ceil); // закрашиваем пол. вставить цвет из структуры
			ft_mlx_pixel_put(&base->textures.screen, x, y, color); // закрашиваем пол. вставить цвет из структуры
			// base->textures.screen.data[x + y * base->width_screen] = color;
			x++;
		}
		y++;
	}
}

t_color	ft_get_color_in_tex(t_base *base, char code, float xx_otn, float yy_otn)
{
	t_image	*texture;

	if (code == 0)
		texture = &base->textures.no;
	else if (code == 1)
		texture = &base->textures.we;
	else if (code == 2)
		texture = &base->textures.so;
	else if (code == 3)
		texture = &base->textures.ea;
	else
		texture = &base->textures.s;
	// printf("%d %d %f %f %d %d %d ft_get_color_in_tex\n", texture->width, texture->height, xx_otn, yy_otn, (int)(xx_otn * texture->width), (int)(yy_otn * texture->height), (int)(yy_otn * texture->height) * texture->width +
			// (int)(xx_otn * texture->width));
	if (xx_otn < 0 || yy_otn < 0 || yy_otn >= 1 || xx_otn >= 1)
		return (texture->data[0]);
	return (texture->data[(int)(yy_otn * texture->height) * texture->width +\
			(int)(xx_otn * texture->width)]);
}

void ft_render_vertical(t_base *base, t_strip *strip, int xx, float xx_otn)
{
	int val;
	int yy;
	int y_init;
	t_color color;
	float yy_otn;
	float incr;
	
	ft_bzero(&color, sizeof(t_color));
	val = base->height_screen / strip->dist;
	y_init = (base->height_screen - val) / 2;
	yy = y_init;
	yy_otn = 0;
	if (val)
		incr = 1.0 / (float)val;
	else
		incr = 0.0;
	while(yy < y_init + val && yy < base->height_screen)
	{
		if(yy >= 0)
			ft_mlx_pixel_put(&base->textures.screen, xx, yy, ft_get_color_in_tex(base, strip->code, xx_otn, yy_otn));
		yy++;
		yy_otn += incr;
	}
}

float	ft_get_otn_xx(t_strip *strip)
{
	if (strip->code == 0 || strip->code == 2)
		return (strip->xx - floor(strip->xx));
	return (strip->yy - floor(strip->yy));
}

void	ft_render(t_base *base, t_strip *strip)
{
	int xx;
	float xx_otn;

	xx = 0;
	while( xx < base->width_screen)
	{
		xx_otn = ft_get_otn_xx(strip + xx);
		// printf("%f %f %f ft_render\n", xx_otn, strip->xx, strip->yy);
		ft_render_vertical(base, strip + xx, xx, xx_otn);
		xx++;
		// break;
	}
}


int ft_tick(t_base *base)
{
	base->textures.screen.width = base->width_screen;
	base->textures.screen.height = base->height_screen;
	
	t_strip strip[base->textures.screen.width];

	// printf("tick\n");
	ft_check_keys(base);
	ft_fill_sprite(base);
	ft_drw_flr_ceil(base);
	ft_raycast(base, strip);
	ft_render(base, strip);
	ft_render_sprite(base, strip);
	mlx_put_image_to_window(base->mlx_ptr, base->mlx_win, base->textures.screen.link, 0, 0);
	return (0);
}



void	ft_mlx(t_base *base)
{	
	base->mlx_win = mlx_new_window(base->mlx_ptr, base->width_screen, base->height_screen, "CUBE_RUBE!");
	base->textures.screen.link = mlx_new_image(base->mlx_ptr, base->width_screen, base->height_screen);
	base->textures.screen.data = (t_color *)mlx_get_data_addr(base->textures.screen.link, &base->textures.screen.bits_pix, \
						&base->textures.screen.line_len, &base->textures.screen.endian);
	// ft_mlx_2d

	// ft_drw_flr_ceil(base);
		// ft_mlx_pixel_put(&base->textures.screen, 50, 50, 0x00FFFF00);
		// ft_mlx_pixel_put(&base->textures.screen, 51, 51, 0x0000BFFF);
	
	mlx_put_image_to_window(base->mlx_ptr, base->mlx_win, base->textures.screen.link, 0, 0);
	// mlx_loop(base->mlx_ptr); 


	// ft_init_textur(base); // ??
	// ft_init_sprites(base); // ??
	mlx_loop_hook(base->mlx_ptr, ft_tick, base);
	mlx_hook(base->mlx_win, 2, 1L << 0, ft_key_in, base);
	mlx_hook(base->mlx_win, 3, 1L << 0, ft_key_out, base);
	mlx_hook(base->mlx_win, 17, 0, ft_exit, base); 
	mlx_do_key_autorepeatoff(base->mlx_ptr);
}