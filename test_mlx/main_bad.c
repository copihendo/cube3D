#include <cube.h>

typedef struct  s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}              t_data;



int main(void)
{
    void *mlx;
    t_data img;
    void *mlx_win;

    img.bits_per_pixel = 4;
    img.line_length = 10;
    img.endian = 5;
    mlx = mlx_init();
    img.img = mlx_new_window(mlx, 54, 25, "Hell World!");
    img.addr = mlx_get_data_arrr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_loop(mlx);
}
