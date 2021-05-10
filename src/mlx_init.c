/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:22:51 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 22:31:36 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_render_vertical(t_base *base, t_strip *strip, int xx, float xx_otn)
{
	int		val;
	int		yy;
	t_color	color;
	float	yy_otn;
	float	incr;

	ft_bzero(&color, sizeof(t_color));
	val = base->height_screen / strip->dist;
	yy = (base->height_screen - val) / 2;
	yy_otn = 0;
	if (val)
		incr = 1.0 / (float)val;
	else
		incr = 0.0;
	while (yy < (base->height_screen - val) / 2 + \
					val && yy < base->height_screen)
	{
		if (yy >= 0)
			ft_mlx_pixel_put(&base->textures.screen, xx, yy, \
				ft_get_color_in_tex(base, strip->code, xx_otn, yy_otn));
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
	int		xx;
	float	xx_otn;

	xx = 0;
	while (xx < base->width_screen)
	{
		xx_otn = ft_get_otn_xx(strip + xx);
		ft_render_vertical(base, strip + xx, xx, xx_otn);
		xx++;
	}
}

int	ft_tick(t_base *base)
{
	t_strip	*strip;

	strip = base->strip;
	strip = malloc(sizeof(t_strip) * base->width_screen);
	if (!strip)
		ft_exit(base, "ne molochu!");
	base->textures.screen.width = base->width_screen;
	base->textures.screen.height = base->height_screen;
	ft_check_keys(base);
	ft_fill_sprite(base);
	ft_drw_flr_ceil(base);
	ft_raycast(base, strip);
	ft_render(base, strip);
	ft_render_sprite(base, strip);
	mlx_put_image_to_window(base->mlx_ptr, base->mlx_win, \
			base->textures.screen.link, 0, 0);
	return (0);
}

void	ft_mlx(t_base *base)
{	
	base->mlx_win = mlx_new_window(base->mlx_ptr, base->width_screen, \
				base->height_screen, "CUBE_RUBE!");
	base->textures.screen.link = mlx_new_image(base->mlx_ptr, \
				base->width_screen, base->height_screen);
	base->textures.screen.data = (t_color *)mlx_get_data_addr(base->textures.screen.link, \
	&base->textures.screen.bits_pix, &base->textures.screen.line_len, \
						&base->textures.screen.endian);
	mlx_put_image_to_window(base->mlx_ptr, base->mlx_win, \
			base->textures.screen.link, 0, 0);
	mlx_loop_hook(base->mlx_ptr, ft_tick, base);
	mlx_hook(base->mlx_win, 2, 1L << 0, ft_key_in, base);
	mlx_hook(base->mlx_win, 3, 1L << 0, ft_key_out, base);
	mlx_hook(base->mlx_win, 17, 0, ft_exit, base);
	mlx_do_key_autorepeatoff(base->mlx_ptr);
}
