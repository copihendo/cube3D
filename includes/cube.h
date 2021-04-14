/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:08:50 by copihendo         #+#    #+#             */
/*   Updated: 2021/03/23 16:39:15 by copihendo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define BUFFER_SIZE 1024

typedef struct  s_junk
{
	char *file;
	char **lines;
	char **words;
	char **kit;
	size_t *max_width;
}               t_junk;



typedef struct	s_color
{
	char 		flag;
	unsigned char 		R;
	unsigned char 		G;
	unsigned char 		B;
}				t_color;

typedef struct s_image
{
		t_color *color;
		void 	*link;
		int 	width;
		int 	height;	
}				t_image;

typedef struct s_textures
{
	t_image		no;
	t_image		so;			
	t_image 	we;			
	t_image 	ea;			
	t_image 	s;	
}		t_textures;



typedef struct s_player
{
	float x;
	float y;
	float direct;
}				t_player;

typedef struct s_map
{
	int width;
	int height;
	char *data;
}				t_map;









typedef struct  s_base
{
	t_junk 		junk;
	int 		width_screen;
	int 		height_screen;
	t_textures	textures;		
	t_color 	floor;
	t_color 	ceil;
	t_map		map;
	t_player	player;
	void 		*mlx_ptr;
}               t_base;

char *ft_read_file(const char *path);

#endif
