/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:08:50 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/01 15:48:53 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# define BUFFER_SIZE 1024
// # define keycode 76


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
		int		bits_pix;
		int		line_len;
		int		endian;
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
	// int width;
	size_t width;
	// int height;
	size_t height;
	char *data;
}				t_map;


////////////			BASE				//////////


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
	// void 		*mlx_ptr;
	void 		*mlx_ptr;
	void 		*mlx_win;
}               t_base;

char	*ft_read_file(const char *path);
void    ft_parse(t_base *base, const char *path);
char	*ft_read_file(const char *path);
int		ft_check_config(t_base *base);
void	ft_handle_line(t_base *base);
void	ft_handle_textures(t_base *base);
int		ft_color_atoi(t_base *base, char *kit);
void	ft_parse_color(t_base *base, t_color *color);
// void	ft_read_config(t_base *base);
void ft_read_config(t_base *base, char *str);
void	ft_find_max_width(t_base *base, char **lines);
void	*ft_transform_map(t_base *base, char **lines);
int		ft_check_map(t_base *base);
// int		ft_read_map(t_base *base, t_list *list, char *line);
int		ft_read_map(t_base *base, char **line);
t_list	*ft_lstadd_back_content(t_list **list, void *content);
int		ft_exit(t_base *base);


#endif
