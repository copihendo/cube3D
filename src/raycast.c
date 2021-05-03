#include "cube.h"

int			ft_impact(t_base *base, float xx, float yy)
{
	if (base->map.data[(int)yy * base->map.width + (int)xx] == '1' || \
	base->map.data[(int)yy * base->map.width + (int)xx] == '2')
		return (0);
	return (1);
}


static void	ft_init_step(t_base *base)
{
	if (base->rcst.ray_dir.xx < 0)
	{
		base->rcst.step.xx = -1;
		base->rcst.side_dist.xx = (base->player.xx - base->rcst.map_x) \
		* base->rcst.delta_dist.xx;
	}
	else
	{
		base->rcst.step.xx = 1;
		base->rcst.side_dist.xx = (base->rcst.map_x + 1.0 - base->player.xx) \
		* base->rcst.delta_dist.xx;
	}
	if (base->rcst.ray_dir.yy < 0)
	{
		base->rcst.step.yy = -1;
		base->rcst.side_dist.yy = (base->player.yy - base->rcst.map_y) \
		* base->rcst.delta_dist.yy;
	}
	else
	{
		base->rcst.step.yy = 1;
		base->rcst.side_dist.yy = (base->rcst.map_y + 1.0 - base->player.yy) \
		* base->rcst.delta_dist.yy;
	}
}

static void	ft_calc_dist(t_base *base)
{
	if (base->rcst.side == 0)
	{
		base->wall.dist = (base->rcst.map_x - base->player.xx \
		+ (1 - base->rcst.step.xx) / 2) / base->rcst.ray_dir.xx;
	}
	else
	{
		base->wall.dist = ((base->rcst.map_y - base->player.yy \
		+ (1 - base->rcst.step.yy) / 2) / base->rcst.ray_dir.yy);
	}
}

static void	ft_dda(t_base *base)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (base->rcst.side_dist.xx < base->rcst.side_dist.yy)
		{
			base->rcst.side_dist.xx += base->rcst.delta_dist.xx;
			base->rcst.map_x += base->rcst.step.xx;
			base->rcst.side = 0;
		}
		else
		{
			base->rcst.side_dist.yy += base->rcst.delta_dist.yy;
			base->rcst.map_y += base->rcst.step.yy;
			base->rcst.side = 1;
		}
		if (base->map.data[base->rcst.map_y * base->map.width \
		+ base->rcst.map_x] == '1')
			hit = 1;
	}
}


void		ft_raycasting(int x, t_base *base)
{
	base->rcst.cam_x = 2 * x / (float)base->width_screen - 1;
	base->rcst.ray_dir.xx = base->player.dir.xx + base->player.plane.xx \
	* base->rcst.cam_x;
	base->rcst.ray_dir.yy = base->player.dir.yy + base->player.plane.yy \
	* base->rcst.cam_x;
	base->rcst.map_x = (int)base->player.xx;
	base->rcst.map_y = (int)base->player.yy;
	base->rcst.delta_dist.xx = fabs(1 / base->rcst.ray_dir.xx);
	base->rcst.delta_dist.yy = fabs(1 / base->rcst.ray_dir.yy);
	ft_init_step(base);
	ft_dda(base);
	ft_calc_dist(base);
}