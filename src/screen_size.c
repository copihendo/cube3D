/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:40:26 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 17:37:24 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_color_atoi(t_base *base, char *kit)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (kit[i] >= '0' && kit[i] <= '9' )
	{
		res = res * 10 + (kit[i] - '0');
		i++;
	}
	if (kit[i] != '\0')
		ft_exit(base, "Color out of range");
	if (res < 0 || res > 255)
		ft_exit(base, "Color out of range");
	return (res);
}

void	ft_parse_color(t_base *base, t_color *color)
{
	base->junk.kit = ft_split(base->junk.words[1], ',');
	if (!(base->junk.kit))
		ft_exit(base, "Invalid colors");
	if (base->junk.kit[0] != 0 && base->junk.kit[1] != 0 && base->junk.kit[2] != 0 \
	&& base->junk.kit[3] == 0 && color->flag == 0)
	{
		color->R = ft_color_atoi(base, base->junk.kit[0]);
		color->G = ft_color_atoi(base, base->junk.kit[1]);
		color->B = ft_color_atoi(base, base->junk.kit[2]);
		color->flag = 1;
	}
	else
		ft_exit(base, "Invalid colors");
	ft_free(base->junk.kit);
	base->junk.kit = 0;
}

int	ft_check_number(t_base *base)
{
	int	i;
	int	j;

	i = 1;
	while (i < 3)
	{
		j = 0;
		while (base->junk.words[i][j])
		{
			if (base->junk.words[i][j] <= '0' && base->junk.words[i][j] >= '9')
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_screen_size(t_base *base)
{
	if (base->width_screen < 0 || base->height_screen < 0)
		ft_exit(base, "size of screen is nagetive");
	if (base->width_screen < 100)
		base->width_screen = 100;
	else if (base->width_screen >= 1000)
		base->width_screen = 1000;
	else if (base->height_screen < 100)
		base->height_screen = 100;
	else if (base->height_screen >= 1080)
		base->height_screen = 1080;
}

void	ft_screen_size(t_base *base)
{
	int	i;

	i = 0;
	while (base->junk.words[i])
		i++;
	if (i != 3)
		ft_exit(base, "invalid number of arguments in resolution");
	if (!ft_check_number(base))
	{
		if (base->width_screen != 0 || base->height_screen != 0)
			ft_exit(base, "Double Resolution. ERROR!");
		base->width_screen = ft_atoi(base->junk.words[1]);
		base->height_screen = ft_atoi(base->junk.words[2]);
		ft_check_screen_size(base);
	}
	else
		ft_exit(base, "size is_not valid");
}
