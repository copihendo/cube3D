/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:26:54 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 17:26:54 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_check_config(t_base *base)
{	
	if (base->width_screen != 0 && base->height_screen != 0 && base->textures.no.link != 0 \
		&& base->textures.so.link != 0 && base->textures.we.link != 0 \
		&& base->textures.ea.link != 0 \
		&& base->textures.s.link != 0 && base->floor.flag != 0 \
		&& base->ceil.flag != 0)
		return (0);
	else
		return (1);
}

// void	ft_handle_line(t_base *base)
// {
// 	size_t	i;
// 	char	*str;

// 	base->junk.lines = ft_split(base->junk.file, '\n');
// 	if (!base->junk.lines)
// 		ft_exit(base, "ft_handle_line split error");
// 	i = 0;
// 	while ((str = base->junk.lines[i]))
// 	{
// 		if (ft_check_config(base))
// 			ft_read_config(base, str);
// 		else
// 			break ;
// 		i++;
// 	}
// 	if (ft_check_config(base))
// 		ft_exit(base, "Invalid Map !!");
// 	ft_read_map(base, base->junk.lines + i);
// }

void	ft_handle_line(t_base *base)
{
	size_t	i;

	base->junk.lines = ft_split(base->junk.file, '\n');
	if (!base->junk.lines)
		ft_exit(base, "ft_handle_line split error");
	i = 0;
	while (base->junk.lines[i])
	{
		if (ft_check_config(base))
			ft_read_config(base, base->junk.lines[i]);
		else
			break ;
		i++;
	}
	if (ft_check_config(base))
		ft_exit(base, "Invalid Map !!");
	ft_read_map(base, base->junk.lines + i);
}

void	ft_parse(t_base *base, const char *path)
{
	base->junk.file = ft_read_file(path);
	if (!(base->junk.file))
		ft_exit(base, "Can't read Map file");
	ft_handle_line(base);
}
