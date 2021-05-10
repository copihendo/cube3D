/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:08:50 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 22:29:10 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# define BUFFER_SIZE 1024
// # define keycode 76
# define W 13
# define S 1
# define D 2
# define A 0
# define LF 123
# define RF 124
# define esc 53

#define ROT_SPEED 0.01



typedef struct		s_key
{
	char			w;
	char			s;
	char			a;
	char			d;
	char			l;
	char			r;
}					t_key;
typedef struct s_strip
{
	int code;
	float xx;
	float yy;
	float dist;
	float dir;
}				t_strip;

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
	unsigned char 		B;
	unsigned char 		G;
	unsigned char 		R;
	char 				flag;
}				t_color;

typedef struct s_image
{
		void 	*link;
		t_color *data;
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

typedef struct s_sprite
{
	t_fpos pos;
	float dir;
	float dist;
}				t_sprite;

typedef struct s_section
{
	t_fpos pos[2];
}				t_section;

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
	int		width;
	int		height;
	char	*data;
}				t_map;

typedef	struct	s_wall
{
	float		dist;
	float		*array_dist;
}				t_wall;

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
	void 		*mlx_win;
	t_wall			wall;
	t_raycast	rcst;
	t_key		key;
	int 		flag_bmp;
	t_list		*sprite;
	t_strip		*strip;
}               t_base;

char	*ft_read_file(const char *path);
void    ft_parse(t_base *base, const char *path);
char	*ft_read_file(const char *path);
int		ft_check_config(t_base *base);
void	ft_handle_line(t_base *base);
void	ft_handle_textures(t_base *base);
int		ft_color_atoi(t_base *base, char *kit);
void	ft_parse_color(t_base *base, t_color *color);
void 	ft_read_config(t_base *base, char *str);
void	ft_find_max_width(t_base *base, char **lines);
void	*ft_transform_map(t_base *base, char **lines);
int		ft_check_map(t_base *base);
int		ft_read_map(t_base *base, char **line);
t_list	*ft_lstadd_back_content(t_list **list, void *content);
char		ft_impact(t_base *base, int xx, int yy);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_mlx(t_base *base);
int		ft_key_in(int keycode, t_base *base);
int		ft_key_out(int keycode, t_base *base);
void	ft_check_keys(t_base *base);
void	ft_raycast(t_base *base, t_strip *strip);
float	ft_to_diap(float val);
void	ft_mlx_pixel_put(t_image *image, int x, int y, t_color color);
t_color	ft_get_color_in_tex(t_base *base, char code, float xx_otn, float yy_otn);

void	ft_fill_sprite(t_base *base);
void	ft_render_sprite(t_base *base, t_strip *strip);
void	ft_init_sprite(t_base *base, int x, int y);
int		ft_tick(t_base *base);
void	ft_screenshot(t_base *base);
void	ft_screen_size(t_base *base);
void	ft_free(char **p);
int		ft_exit(void *param, char *message);
int	ft_lst_cmp(t_sprite *sp1, t_sprite *sp2);
void	ft_lst_add_sort(t_list **begin, t_list *new, int (*ft_cmp)(void *, void *));
void	ft_drw_flr_ceil(t_base *base);
void	ft_choice_wall(t_strip *strip, t_section *sec);
void	ft_cross(t_section *sec_wall, t_section *sec_ray, t_strip *strip);
void	ft_tamer(t_strip *strip);

#endif
