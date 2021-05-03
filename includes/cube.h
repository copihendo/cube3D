/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:08:50 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/03 21:23:41 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define BUFFER_SIZE 1024
// # define keycode 76
# define W 13
# define S 1
# define D 2
# define A 0
# define LF 123
# define RF 124
# define esc 53

typedef struct		s_key
{
	char			w;
	char			s;
	char			a;
	char			d;
	char			l;
	char			r;
}					t_key;

typedef struct  s_junk
{
	char		*file;
	char		**lines;
	char		**words;
	char		**kit;
	size_t		*max_width;
}               t_junk;

typedef struct	s_color
{
	char 				flag;
	unsigned char 		R;
	unsigned char 		G;
	unsigned char 		B;
}				t_color;

typedef struct s_image
{
		void 	*link;
		t_color *color;
		char 	*addr;
		int 	width;
		int 	height;
		int		bits_pix;
		int		line_len;
		int		endian;
}				t_image;

typedef struct s_textures
{
	t_image			no;
	t_image			so;			
	t_image 		we;			
	t_image 		ea;			
	t_image 		s;
	t_image			screen;	
}					t_textures;

typedef	struct		s_ipos
{
	int				xx;
	int				yy;
}					t_ipos;

typedef	struct		s_fpos
{
	float			xx;
	float			yy;
}					t_fpos;

typedef	struct		s_raycast
{
	float			cam_x;
	t_fpos			ray_dir;
	int				map_x;
	int				map_y;
	t_fpos			delta_dist;
	t_fpos			side_dist;
	t_ipos			step;
	int				side;
	float			relat_coord;
}					t_raycast;


typedef struct s_player
{
	float		xx;
	float		yy;
	float		direct;
	t_fpos 		dir;
	t_fpos 		plane;
	float		move_speed;
	float		rot_speed;
	// float start;
	// float end
}				t_player;

typedef struct s_map
{
	size_t		width;
	size_t		height;
	char		*data;
	// int width;
	// int height;
}				t_map;

typedef	struct	s_wall
{
	float		dist;
	float		*array_dist;
}				t_wall;

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
	t_wall			wall;
	t_raycast	rcst;
	t_key		key;
	int 		flag_bmp;
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
void 	ft_read_config(t_base *base, char *str);
void	ft_find_max_width(t_base *base, char **lines);
void	*ft_transform_map(t_base *base, char **lines);
int		ft_check_map(t_base *base);
// int		ft_read_map(t_base *base, t_list *list, char *line);
int		ft_read_map(t_base *base, char **line);
t_list	*ft_lstadd_back_content(t_list **list, void *content);
int		ft_exit(t_base *base);
int		ft_impact(t_base *base, float xx, float yy);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_mlx(t_base *base);
int		ft_key_in(int keycode, t_base *base);
int		ft_key_out(int keycode, t_base *base);


#endif
