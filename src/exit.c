/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:09:11 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 22:30:47 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_delete_lines(char **lines)
{
	size_t	counter;

	if (lines)
	{
		counter = 0;
		while (lines[counter])
		{
			free(lines[counter++]);
		}
		free(lines);
	}
}

void	ft_free_junk(t_base *base)
{
	free(base->junk.file);
	free(base->junk.max_width);
	ft_delete_lines(base->junk.lines);
	ft_delete_lines(base->junk.words);
	ft_delete_lines(base->junk.kit);
}

static void	ft_free_image(t_base *base, t_image image)
{
	if (image.link)
		mlx_destroy_image(base->mlx_ptr, image.link);
}

static void	ft_base_clear(t_base *base)
{
	ft_free_junk(base);
	free(base->map.data);
	free(base->strip);
	ft_lstclear(&base->sprite, free);
	ft_free_image(base, base->textures.screen);
	ft_free_image(base, base->textures.ea);
	ft_free_image(base, base->textures.no);
	ft_free_image(base, base->textures.so);
	ft_free_image(base, base->textures.we);
	if (base->mlx_win)
		mlx_destroy_window(base->mlx_ptr, base->mlx_win);
}

int	ft_exit(void *param, char *message)
{
	if (message)
	{
		ft_putendl_fd("Error!", 2);
		ft_putendl_fd(message, 2);
	}
	ft_base_clear(param);
	ft_putendl_fd("Exit!", 1);
	ft_bzero(param, sizeof(t_base));
	// sleep(12);
	exit(0);
	return (0);
}
