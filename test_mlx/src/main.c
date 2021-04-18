#include <cube.h>
#include <stdio.h> ///dfdfdf

typedef struct  s_data {
	void		*img;
	char		*addr;
	int			bits_pixel;
	int			line_length;
	int			endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
// int main(void)
// {
// 	void *mlx = NULL;
// 	t_data img;
// 	void *mlx_win = NULL;
// 	int x;
// 	int y;

// 	x = 100;
// 	y = 100;
// 	img.bits_pixel = 32;
// 	img.line_length = 10;
// 	img.endian = 5;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 980, 560, "Hell World!");
// 	img.img = mlx_new_image(mlx, 980, 560);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_pixel, &img.line_length, &img.endian);
// 	while (y < 200)
// 	{
// 		x = 100;
// 		while(x < 200)
// 		{
// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// } 
*/

void print_box(t_data img, int x, int y, int zoom, int color)
{
	int i;
	int j;
	int k;

	i = 1;
	k = x;
	while(i <= zoom)
	{
		x = k;
		j = 1;
		while (j <= zoom)
		{
			my_mlx_pixel_put(&img, x, y, color);
			x++;
			j++;
		}
		y++;
		i++;
	}
}

// typedef struct  s_vars {
//         void    *mlx;
//         void    *win;
// }               t_vars;

// int             close(int keycode, t_vars *vars)
// {
//     mlx_destroy_window(vars->mlx, vars->win);
// }

// int	key_hook(int keycode, t_base *base)
// {
//     printf("Hello from key_hook!\n");
// }

int	ft_close(int keycode, t_base *base)
{
	if (keycode == 8)
		mlx_destroy_window(base.mlx, base.mlx_win);
	return(0);
}


int main(void)
{
	// void *mlx = NULL;
	t_data img;
	// void *mlx_win = NULL;
	int x;
	int y;
	////// alya parsing 
	t_base base;
	base.width_screen = 1040;
	base.height_screen = 550;
	base.map.data = "111111111111111111111111111111111111111111000000000110000000000001111111111011000001110000002000001111111111001000000000000000000001111111111011000001110000000000001100000000011000001110111111111111111101111111110111000000100011111111101111111110111010100100011111110000001101010111000000100011111100020000000000011000000100011111100000000000000011010100100011111110000011101010111110111100011111111101111111010111011110100011111111111111111111111111111111111111";
	base.map.height = 14;
	base.map.width = 33;
	base.player.x = 28;
	base.player.y = 4;
	////// alya parsing 


	x = 0;
	y = 0;
	img.bits_pixel = 32;
	img.line_length = 10;
	img.endian = 5;

	base.mlx = mlx_init();
	base.mlx_win = mlx_new_window(base.mlx, base.width_screen, base.height_screen, "Hell World!");
	img.img = mlx_new_image(base.mlx, base.width_screen, base.height_screen);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pixel, &img.line_length, &img.endian);

////////////////////////////////////////////
//////// 							////////	
////////	 Drawing floor & ceil 	////////
////////		 					////////
////////////////////////////////////////////
	int middle;
	middle = base.height_screen / 2 ;
	// printf("%s\n", base.map.data);
				/////////// FIRST VERSION floor and ceil
/*	// while (y < middle)
	// {
	// 	x = 1;
	// 	while(x < base.width_screen)
	// 	{	
	// 		my_mlx_pixel_put(&img, x, y, 0x0000BFFF); // закрашиваем потолок. вставить цвет из структуры
	// 		x++;
	// 	}
	// 	y++;
	// }
	// while (y >= middle && y < base.height_screen)  
	// {
	// 	x = 1;
	// 	while(x < base.width_screen)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF8C00); // закрашиваем под. вставить цвет из структуры
	// 		x++;
	// 	}
	// 	y++;
	// }*/
	
					/////////// SECOND VERSION
	while (y < base.height_screen)
	{
		x = 0;
		while(x < base.width_screen)
		{	
			if (y < middle)
				my_mlx_pixel_put(&img, x, y, 0x0000BFFF); // закрашиваем потолок. вставить цвет из структуры
			if (y >= middle)
				my_mlx_pixel_put(&img, x, y, 0x00FF8C00); // закрашиваем пол. вставить цвет из структуры
			x++;
		}
		y++;
	}
////////////////////////////////////////
//////// 						////////	
////////	 Drawing 2d map; 	////////
////////		 				////////
////////////////////////////////////////
	int i;

	i = 0;
	y = 0;
	// t_vars    vars;

	int zoom = 15;
	/*  отрисовка карты без зумирования. 
	// my_mlx_pixel_put(&img, 1, 1, 0x00FF00FF);
	// while(i < base.map.height * base.map.width)
	// {
	// 	x = 0;
	// 	while (x < base.map.width * zoom)
	// 	{
	// 		if (base.map.data[i] == '1')
	// 			my_mlx_pixel_put(&img, x, y, 0x00FF00FF);
	// 		x++;
	// 		i++;
	// 	}
	// 	my_mlx_pixel_put(&img, x, y, 0x00FFFF00); // оконтовка карты по правкому краю
	// 	y++;
	// }*/

	while(i < base.map.height * base.map.width) 
	{
		x = 0;
		while (x < base.map.width * zoom)
		{
			if (base.map.data[i] == '1')
				print_box(img, x, y, zoom, 0x00FF00FF);
			x += zoom;
			i++;
		}
		print_box(img, base.player.x * zoom, base.player.y * zoom, 5, 0x00FFFF00); // drawing player
		my_mlx_pixel_put(&img, x+1, y, 0x00FFFF00); // оконтовка карты по правкому краю
		y += zoom;
	}
	mlx_put_image_to_window(base.mlx, base.mlx_win, img.img, 0, 0);
    // mlx_key_hook(base.mlx_win, key_hook, &base);
	mlx_hook(base.mlx_win, 17, 0, ft_close, &base);
    // mlx_hook(vars.win, 2, 1L<<0, close, &vars);

	mlx_loop(base.mlx);
}