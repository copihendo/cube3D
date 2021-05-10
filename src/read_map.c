/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:54:33 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 23:07:16 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_find_max_width(t_base *base, char **lines)
{
	int	width;

	while ((lines[base->map.height]) && base->map.height < 70)
	{
		width = ft_strlen(lines[base->map.height]);
		if (width > base->map.width)
			base->map.width = width;
		base->map.height++;
	}
}

void	ft_fill(t_base *base, char *ptr, char *dir, int x, int y)
{
	if (!(base->player.xx == 0 && base->player.yy == 0))
		ft_exit(base, "Invalid Map: two players");
	base->player.yy = y + 0.5;
	base->player.xx = x + 0.5;
	base->player.direct = (float)(ptr - dir) / 4;
	base->map.data[x + y * base->map.width] = '0';
}

void	*ft_transform_map(t_base *base, char **lines)
{
	int			y;
	int			x;
	char		*ptr;
	char		*dir;

	dir = "NESW";
	base->map.data = ft_calloc(base->map.width * base->map.height + 1, 1);
	if (!(base->map.data))
		ft_exit(base, "ERROR Malloc for Map");
	y = 0;
	while (y++ < base->map.height)
	{
		x = 0;
		while (lines[y][x++])
		{
			ptr = ft_strchr(dir, lines[y][x]);
			if (ptr)
				ft_fill(base, ptr, dir, x, y);
			else if (ft_strchr("012", lines[y][x]))
				base->map.data[x + y * base->map.width] = lines[y][x];
			if (lines[y][x] == '2')
				ft_init_sprite(base, x, y);
		}
	}
	return (0);
}






/*void	*ft_transform_map(t_base *base, char **lines)
{
	int			y;
	int			x;
	char		cell;
	char		*ptr;
	static char	*dir;

	dir = "NESW";
	base->map.data = ft_calloc(base->map.width * base->map.height + 1, 1);
	if (!(base->map.data))
		ft_exit(base, "ERROR Malloc for Map");
	y = 0;
	while (y < base->map.height)
	{
		x = 0;
		while (lines[y][x])
		{
			cell = lines[y][x];
			ptr = ft_strchr(dir, cell);
			if (ptr)
			{
				if (!(base->player.xx == 0 && base->player.yy == 0))
					ft_exit(base, "Invalid Map: two players");
				base->player.yy = y + 0.5;
				base->player.xx = x + 0.5;
				base->player.direct = (float)(ptr - dir) / 4;
				base->map.data[x + y * base->map.width] = '0';
			}
			else if (ft_strchr("012", cell))
				base->map.data[x + y * base->map.width] = cell;
			if (cell == '2')
				ft_init_sprite(base, x, y);
			x++;
		}
		y++;
	}
	if (base->player.xx == 0 || base->player.yy == 0)
		ft_exit(base, "Invalid Map: NO players");
	return (0);
}*/

int	ft_check_map(t_base *base)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < base->map.height)
	{
		x = 0;
		while (x++ < base->map.width)
		{
			i = base->map.width * y + x;
			if (base->map.data[i] == '0' || base->map.data[i] == '2')
			{
				if (x == 0 || y == 0 || x == base->map.width - 1 || \
								 y == base->map.height - 1)
					ft_exit(base, "Invalid structure map, vse ploho");
				if (base->map.data[i + 1] == '\0' || base->map.data[i - 1] == '\0'\
					|| base->map.data[i - base->map.width] == '\0'\
					|| base->map.data[i + base->map.width] == '\0')
					return (-1);
			}
		}
		y++;
	}
	return (0);
}

void	ft_direct(t_base *base)
{
	if (base->player.direct < 0.25)
		base->player.dir.yy = -1;
	else if (base->player.direct < 0.5)
		base->player.dir.xx = -1;
	else if (base->player.direct < 0.75)
		base->player.dir.yy = 1;
	else
		base->player.dir.xx = 1;
}

int	ft_read_map(t_base *base, char **line)
{
	ft_find_max_width(base, line);
	ft_transform_map(base, line);
	if (base->player.xx == 0 || base->player.yy == 0)
		ft_exit(base, "Invalid Map: NO players");
	ft_direct(base);
	if (ft_check_map(base) == -1)
		ft_exit(base, "Invalid structure map");
	return (0);
}
