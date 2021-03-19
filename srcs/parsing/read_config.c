/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:42:08 by copihendo         #+#    #+#             */
/*   Updated: 2021/03/14 04:15:22 by copihendo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		ft_free(char **p)
{
	size_t i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}


ft_parse_texture(t_base *base, t_image *texture)
{
	//texture = base->junk.words[1];
texture->link = mlx_xpm_file_to_image (base->mlx_ptr, base->junk.words[1], &texture->width, &texture->height);
// если линк нуль терминатор вызвать экзит
//проверить и вывести ошибку если есть, или стандратное закытие программы. 
}

int ft_color_atoi(t_base *base, char *kit)
{
	int i;
	int res;
	
	if (kit[0] == '0')
		ft_exit(base);
	i = 0;
	while (kit[i] >= '0' && kit[i] <= '9' )
	{
		res = res * 10 + (kit[i] - '0');
		i++;
	}
	if (kit[i] != '\0')
		ft_exit(base); 
}


ft_parse_color(t_base *base)
{
	if(!(kit = ft_split(base->junk.words[2], ',')))
		ft_exit(base);
	if (kit[0] != 0 && kit[1] != 0 && kit[2] != 0 && kit[3] == 0)
	{
		ft_color_atoi(base, base->junk.kit[1]);
		ft_color_atoi(base, base->junk.kit[1]);
		ft_color_atoi(base, base->junk.kit[2]);
	else ft_exit(base);
}

ft_read_config(t_base *base)
{
	char *tag;

	base->junk.words = ft_split(base->junk.lines, ' ');
	tag = base->junk.words[0];
	if (ft_strcmp(tag, "R"))
		ft_screen_size(base);
	else if (ft_strcmp(tag, "NO"))
		ft_parse_texture(base, &base->textures.no);	
	else if	(ft_strcmp(tag, "SO"))
		ft_parse_texture(base, &base->textures.so);
	else if (ft_strcmp(tag, "WE"))
		ft_parse_texture(base, &base->textures.we);
	else if	(ft_strcmp(tag, "EA"))
		ft_parse_texture(base, &base->textures.ea);
	else if (ft_strcmp(tag, "S"))
		ft_parse_texture(base, &base->textures.s);	
	else if	(ft_strcmp(tag, "F"))
		ft_parse_color(base, base->floor);
	else if	(ft_strcmp(tag, "C"))
		ft_parse_color(base, base->ceil);
	ft_free(base->junk.words);
	base->junk.words = 0;
}

