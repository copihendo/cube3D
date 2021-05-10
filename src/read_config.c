/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:42:08 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 17:41:44 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_free(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

int	ft_check_link(t_base *base)
{
	int			i;
	static char	*ext;

	ext = ".xpm";
	i = ft_strlen(base->junk.words[1]) - 4;
	while (base->junk.words[1][i] != '\0')
	{
		if (ft_strchr(ext, base->junk.words[1][i]))
			i++;
		else
			return (-1);
	}
	return (0);
}

void	ft_parse_texture(t_base *base, t_image *texture)
{
	int	n;

	if (texture->link != NULL)
		ft_exit(base, "Double texture. Error!");
	texture->link = mlx_xpm_file_to_image(base->mlx_ptr, base->junk.words[1], \
											&texture->width, &texture->height);
	if (!(texture->link))
		ft_exit(base, "parse_texture_error");
	if (ft_check_link(base) == -1)
		ft_exit(base, "invalid extension of texture");
	texture->data = (t_color *)mlx_get_data_addr(texture->link, &n, &n, &n);
	if (!texture->data)
		ft_exit(base, "texture->data");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_read_config(t_base *base, char *str)
{
	char	*tag;
	size_t	i;

	i = 0;
	base->junk.words = ft_split(str, ' ');
	tag = base->junk.words[0];
	if (!ft_strcmp(tag, "R"))
		ft_screen_size(base);
	else if (!ft_strcmp(tag, "NO"))
		ft_parse_texture(base, &base->textures.no);
	else if (!ft_strcmp(tag, "SO"))
		ft_parse_texture(base, &base->textures.so);
	else if (!ft_strcmp(tag, "WE"))
		ft_parse_texture(base, &base->textures.we);
	else if (!ft_strcmp(tag, "EA"))
		ft_parse_texture(base, &base->textures.ea);
	else if (!ft_strcmp(tag, "S"))
		ft_parse_texture(base, &base->textures.s);
	else if (!ft_strcmp(tag, "F"))
		ft_parse_color(base, &base->floor);
	else if (!ft_strcmp(tag, "C"))
		ft_parse_color(base, &base->ceil);
	ft_free(base->junk.words);
	base->junk.words = 0;
}
