/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:26:54 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/30 21:55:40 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

int ft_check_config(t_base base) // что мы должны передавать сда
{
	// write(1, "ckeck_config1\n", 14);
	// if (base.width_screen != 0 && base.height_screen != 0)
	if (base.width_screen != 0 && base.height_screen != 0 && base.textures.no.link != 0 \
		&& base.textures.so.link != 0 && base.textures.we.link != 0 && base.textures.ea.link != 0 \
		&& base.textures.s.link != 0 && base.floor.flag != 0 && base.ceil.flag != 0)
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
	// write(1, "handle_line1\n", 13);
	while ((str = base->junk.lines[i]))
	{
		write(1, "handle_line2\n", 13);
		if(ft_check_config(*base))
		{
			write(1, "handle_line3\n", 13);
			ft_read_config(base, str);
			// printf("%s\n", base->)
		}
		else 
		{			write(1, "handle_line4\n", 13);
				ft_read_map(base, str);}
		i++;
	}
}


void	ft_parse(t_base *base, const char *path)
{
	if(!(base->junk.file = ft_read_file(path)))
		ft_exit(base);
	ft_handle_line(base);
	write(1, "parse_finish\n", 13);
	printf("width screen %d\n", base->width_screen);
	printf("height screen %d\n", base->height_screen);
	printf("floor %d %d %d\n", base->floor.R, base->floor.G, base->floor.B);
	printf("ceil %d %d %d\n", base->ceil.R, base->ceil.G, base->ceil.B);
	printf("textures no %s\n", base->textures.no.link);
}
