/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:46:29 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 22:02:40 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mlx_pixel_put(t_image *image, int x, int y, t_color color)
{
	t_color	*dst;

	dst = image->data + (y * image->width + x);
	*dst = color;
}

void	ft_drw_flr_ceil(t_base *base)
{
	int		middle;
	int		x;
	int		y;
	t_color	color;

	x = 0;
	y = 0;
	middle = base->height_screen / 2 ;
	while (y < base->height_screen)
	{
		x = 0;
		while (x < base->width_screen)
		{	
			if (y <= middle)
				color = base->ceil;
			else
				color = base->floor;
			ft_mlx_pixel_put(&base->textures.screen, x, y, color);
			x++;
		}
		y++;
	}
}

t_color	ft_get_color_in_tex(t_base *base, char code, float xx_otn, float yy_otn)
{
	t_image	*texture;
	int		index;

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
	if (xx_otn < 0 || yy_otn < 0 || yy_otn >= 1 || xx_otn >= 1)
		return (texture->data[0]);
	index = texture->width * (int)(yy_otn * texture->height) + \
		(int)(xx_otn * texture->width);
	return (texture->data[index]);
}
