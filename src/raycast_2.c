#include "../includes/cube.h"

char	ft_impact(t_base *base, int xx, int yy)
{
	return (base->map.data[yy * base->map.width + xx]);
}

int	ft_is_floor(float val)
{
	return (floor(val) == val);
}

void	ft_tamer(t_strip *strip)
{
	float	delta;

	delta = 0.00001;
	if (strip->code == 0)
		strip->yy -= delta;
	else if (strip->code == 1)
		strip->xx += delta;
	else if (strip->code == 2)
		strip->yy += delta;
	else if (strip->code == 3)
		strip->xx -= delta;
}

void	ft_choice_wall(t_strip *strip, t_section *sec)
{
	t_fpos	pos[4];
	int		p2;

	pos[0].xx = floor(strip->xx);
	pos[0].yy = floor(strip->yy);
	pos[1].xx = ceil(strip->xx);
	pos[1].yy = floor(strip->yy);
	pos[2].xx = ceil(strip->xx);
	pos[2].yy = ceil(strip->yy);
	pos[3].xx = floor(strip->xx);
	pos[3].yy = ceil(strip->yy);
	strip->code = (int)(strip->dir * 4);
	p2 = (strip->code + 1) % 4;
	if (strip->dir < ft_to_diap(1 - atan2(strip->xx - pos[p2].xx, \
							strip->yy - pos[p2].yy) / (2 * M_PI)))
	{
		ft_memmove(sec->pos, pos + strip->code, sizeof(t_fpos));
		ft_memmove(sec->pos + 1, pos + p2, sizeof(t_fpos));
	}
	else
	{
		ft_memmove(sec->pos, pos + p2, sizeof(t_fpos));
		ft_memmove(sec->pos + 1, pos + (p2 + 1) % 4, sizeof(t_fpos));
		strip->code = p2;
	}
}

void	ft_cross(t_section *sec_wall, t_section *sec_ray, t_strip *strip)
{
	float	n;
	float	q;
	float	sn;
	float	fn;

	if (sec_wall->pos[1].yy - sec_wall->pos[0].yy != 0)
	{
		q = (sec_wall->pos[1].xx - sec_wall->pos[0].xx) \
			/ (sec_wall->pos[0].yy - sec_wall->pos[1].yy);
		sn = (sec_ray->pos[0].xx - sec_ray->pos[1].xx) \
			+ (sec_ray->pos[0].yy - sec_ray->pos[1].yy) * q;
		if (!sn)
			return ;
		fn = (sec_ray->pos[0].xx - sec_wall->pos[0].xx) \
			+ (sec_ray->pos[0].yy - sec_wall->pos[0].yy) * q;
		n = fn / sn;
	}
	else
		n = (sec_ray->pos[0].yy - sec_wall->pos[0].yy) \
			/ (sec_ray->pos[0].yy - sec_ray->pos[1].yy);
	strip->xx = sec_ray->pos[0].xx +\
		(sec_ray->pos[1].xx - sec_ray->pos[0].xx) * n;
	strip->yy = sec_ray->pos[0].yy +\
		(sec_ray->pos[1].yy - sec_ray->pos[0].yy) * n;
}
