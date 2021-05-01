/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:26:54 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/01 17:12:12 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

int ft_check_config(t_base *base) // что мы должны передавать сда
{
	// write(1, "ckeck_config1\n", 14);
	// if (base.width_screen != 0 && base.height_screen != 0)
	if (base->width_screen != 0 && base->height_screen != 0 && base->textures.no.link != 0 \
		&& base->textures.so.link != 0 && base->textures.we.link != 0 && base->textures.ea.link != 0 \
		&& base->textures.s.link != 0 && base->floor.flag != 0 && base->ceil.flag != 0)
	{
		write(1, "ckeck_config2\n", 14);
		return (0);
	}
	else
	{write(1, "ckeck_config3\n", 14);
		return (1);}
}

void ft_handle_line(t_base *base)
{
	size_t i;
	char *str;
	
	base->junk.lines = ft_split(base->junk.file, '\n');
	i = 0;
	while ((str = base->junk.lines[i]))
	{
		if(ft_check_config(base))
			ft_read_config(base, str);
		else 
			break;
		i++;
	}
	if (ft_check_config(base))
		ft_exit(base);
		write(1, "start_read_map\n", 15);
	ft_read_map(base, base->junk.lines + i);
		write(1, "end_read_map\n", 13);	
}


void	ft_parse(t_base *base, const char *path)
{
	if(!(base->junk.file = ft_read_file(path)))
		ft_exit(base);
	ft_handle_line(base);
	printf("\n\n\tparse_finish\n");
	printf("width screen %d\n", base->width_screen);
	printf("height screen %d\n", base->height_screen);
	printf("floor %d %d %d\n", base->floor.R, base->floor.G, base->floor.B);
	printf("ceil %d %d %d\n", base->ceil.R, base->ceil.G, base->ceil.B);
	printf("textures no %p\n", base->textures.no.link);
	printf("textures so %p\n", base->textures.so.link);
	printf("textures we %p\n", base->textures.we.link);
	printf("textures ea %p\n", base->textures.ea.link);
	printf("textures s %p\n", base->textures.s.link);
	printf("map.height %zu\n", base->map.height);
	// printf("map %s\n", base->map.data);
	// write(1, &base->map.data, 70);
	printf("base->player.x %f\n", base->player.x);
	printf("base->player.y %f\n", base->player.y);
	printf("base->player.direct%f\n", base->player.direct);
}
