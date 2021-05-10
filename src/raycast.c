#include "cube.h"

float	ft_to_diap(float val)
{
	while (val < 0)
		val += 1.0;
	while (val > 1)
		val -= 1.0;
	return (val);
}

void	ft_get_pos(t_strip *strip)
{
	t_section	sec_wall;
	t_section	sec_ray;

	sec_ray.pos[0].xx = strip->xx;
	sec_ray.pos[0].yy = strip->yy;
	sec_ray.pos[1].xx = strip->xx + 2 *\
		cosf(ft_to_diap(-0.25 + strip->dir) * M_PI * 2);
	sec_ray.pos[1].yy = strip->yy + 2 *\
		sinf(ft_to_diap(-0.25 + strip->dir) * M_PI * 2);
	ft_choice_wall(strip, &sec_wall);
	ft_cross(&sec_wall, &sec_ray, strip);
}

void	ft_ray(t_base *base, t_strip *strip)
{
	while (1)
	{
		ft_get_pos(strip);
		ft_tamer(strip);
		if (strip->xx < 0 || (int)strip->xx >= base->map.width || strip->yy < 0 \
					|| (int)strip->yy >= base->map.height)
			break ;
		if (ft_impact(base, (int)strip->xx, (int)strip->yy) == '1')
			break ;
	}
	strip->dist = sqrt(pow(strip->xx - base->player.xx, 2) \
				+ pow(strip->yy - base->player.yy, 2));
}

void	ft_raycast(t_base *base, t_strip *strip)
{
	int		i;
	float	incr;
	float	angle;

	i = 0;
	incr = 0.25 / base->width_screen;
	angle = base->player.direct - 0.25 / 2;
	while (i < base->width_screen)
	{
		strip[i].dir = ft_to_diap(angle);
		strip[i].xx = base->player.xx;
		strip[i].yy = base->player.yy;
		ft_ray(base, strip + i);
		i++;
		angle += incr;
	}
}
