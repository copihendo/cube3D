#include "../includes/cube.h"

void	ft_screen_header(t_base *base, int fd)
{
	char head[14];
	int size;

	ft_bzero(head, 14);
	head[0] = 'B';
	head[1] = 'M';
	size = 14 + 40 + base->width_screen * base->height_screen * 4;
	ft_memmove(head + 2, &size, 4);
	head[10] = 54;
	write(fd, head, 14);
}

void	ft_screen_info(t_base *base, int fd)
{
	char info[40];
	ft_bzero(info, 40);
	info[0] = 40;
	ft_memmove(info + 4, &base->width_screen, 4);
	ft_memmove(info + 8, &base->height_screen, 4);
	info[12] = 1;
	info[14] = 32;
	write(fd, info, 40);
}

void	ft_screen_img(t_base *base, int fd)
{
	int i;
	i = base->height_screen;
	while (i > 0)
	{
		i--;
		write(fd, base->textures.screen.data + base->width_screen * i, base->width_screen * 4);
	}
}
void	ft_screenshot(t_base *base)
{
	int fd;

	fd = open("Screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		ft_exit(base, "Can't open Screenshot.bmp");
	ft_screen_header(base, fd);
	ft_screen_info(base, fd);
	ft_screen_img(base, fd);
	close(fd);
}