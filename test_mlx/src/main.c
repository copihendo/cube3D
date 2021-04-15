#include <cube.h>

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


int main(void)
{
	void *mlx = NULL;
	t_data img;
	void *mlx_win = NULL;
	int x;
	int y;

	x = 100;
	y = 100;
	img.bits_pixel = 32;
	img.line_length = 10;
	img.endian = 5;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 980, 560, "Hell World!");
	img.img = mlx_new_image(mlx, 980, 560);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pixel, &img.line_length, &img.endian);
	while (y < base.map>height)
	{
		x = 1; /// 0 or 1???? 
		while(x < base.map>width)
		{
			if (base.map.data == "1")
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} 