#include "../includes/cube.h"

char			ft_impact(t_base *base, int xx, int yy)
{
	// printf("%f %f ft_impact\n", yy, xx);
	return (base->map.data[yy * base->map.width + xx]);
}

int ft_is_floor(float val)
{
	return(floor(val) == val);
}

void ft_tamer(t_strip *strip)
{
	float delta;

	delta = 0.00001;
	// if(ft_is_floor(strip->xx))
	// 	strip->xx += delta * (1 - (strip->dir >= 0.5) * 2);
	// else
	// 	strip->yy -= delta * (1 - (strip->dir >= 0.25 && strip->dir < 0.75) * 2);
	if (strip->code == 0)
		strip->yy -= delta;
	else if (strip->code == 1)
		strip->xx += delta;
	else if (strip->code == 2)
		strip->yy += delta;
	else if (strip->code == 3)
		strip->xx -= delta;
}

void ft_choice_wall(t_strip *strip, t_section *sec)
{
	t_fpos pos[4];
	int p2;

	pos[0].xx =  floor(strip->xx);
	pos[0].yy =  floor(strip->yy);
	pos[1].xx =  ceil(strip->xx);
	pos[1].yy =  floor(strip->yy);
	pos[2].xx =  ceil(strip->xx);
	pos[2].yy =  ceil(strip->yy);
	pos[3].xx =  floor(strip->xx);
	pos[3].yy =  ceil(strip->yy);

	strip->code = (int)(strip->dir * 4);
	p2 = (strip->code + 1) % 4;
	if(strip->dir <	ft_to_diap(1 - atan2(strip->xx - pos[p2].xx, strip->yy - pos[p2].yy) / (2 * M_PI)))
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






	// if(strip->dir < 0.25)
	// {
	// 	if(strip->dir < 0.25 - atan((strip->yy - pos[1].yy) / (pos[1].xx - strip->xx)) / (2 * M_PI))
	// 	{
	// 		ft_memmove(sec->pos, pos, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos + 1, sizeof(t_fpos));
	// 		strip->code = 0;
	// 	}
	// 	else
	// 	{
	// 		ft_memmove(sec->pos, pos + 1, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos + 2, sizeof(t_fpos));
	// 		strip->code = 1;
	// 	}
	// }
	// else if(strip->dir < 0.5)
	// {
	// 	if(strip->dir < 0.5 - atan((pos[2].xx - strip->xx) / (pos[2].yy - strip->yy)) / (2 * M_PI))
	// 	{
	// 		ft_memmove(sec->pos, pos + 1, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos + 2, sizeof(t_fpos));
	// 		strip->code = 1;
	// 	}
	// 	else
	// 	{
	// 		ft_memmove(sec->pos, pos + 2, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos + 3, sizeof(t_fpos));
	// 		strip->code = 2;
	// 	}
	// }
	// else if(strip->dir < 0.75)
	// {	
	// 	if(strip->dir < 0.75 - atan((pos[3].yy - strip->yy) / (strip->xx - pos[3].xx)) / (2 * M_PI))
	// 	{
	// 		ft_memmove(sec->pos, pos + 2, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos + 3, sizeof(t_fpos));
	// 		strip->code = 2;
	// 	}
	// 	else
	// 	{
	// 		ft_memmove(sec->pos, pos + 3, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos, sizeof(t_fpos));
	// 		strip->code = 3;
	// 	}
	// }
	// else 
	// {
	// 	if(strip->dir < 1 - atan((strip->xx - pos[0].xx) / (strip->yy - pos[0].yy)) / (2 * M_PI))
	// 	{
	// 		ft_memmove(sec->pos, pos + 3, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos, sizeof(t_fpos));
	// 		strip->code = 3;
	// 	}
	// 	else
	// 	{
	// 		ft_memmove(sec->pos, pos, sizeof(t_fpos));
	// 		ft_memmove(sec->pos + 1, pos + 1, sizeof(t_fpos));
	// 		strip->code = 0;
	// 	}
	// }
}

void ft_cross(t_section *sec_wall, t_section *sec_ray, t_strip *strip)
{
	float n;
	float q;
	float sn;
	float fn;

    if (sec_wall->pos[1].yy - sec_wall->pos[0].yy != 0)
	{
        q = (sec_wall->pos[1].xx - sec_wall->pos[0].xx) / (sec_wall->pos[0].yy - sec_wall->pos[1].yy);   
        sn = (sec_ray->pos[0].xx - sec_ray->pos[1].xx) + (sec_ray->pos[0].yy - sec_ray->pos[1].yy) * q; 
		if (!sn)
			return ;
        fn = (sec_ray->pos[0].xx - sec_wall->pos[0].xx) + (sec_ray->pos[0].yy - sec_wall->pos[0].yy) * q;   // b(x) + b(y)*q
        n = fn / sn;
    }
    else
	{
        if (!(sec_ray->pos[0].yy - sec_ray->pos[1].yy)) 
			return ;
        n = (sec_ray->pos[0].yy - sec_wall->pos[0].yy) / (sec_ray->pos[0].yy - sec_ray->pos[1].yy);   // c(y)/b(y)
    }
    strip->xx = sec_ray->pos[0].xx + (sec_ray->pos[1].xx - sec_ray->pos[0].xx) * n;  // sec_ray[0].xx + (-b(x))*n
    strip->yy = sec_ray->pos[0].yy + (sec_ray->pos[1].yy - sec_ray->pos[0].yy) * n;  // y3 +(-b(y))*n
}

float ft_to_diap(float val)
{
	while (val < 0)
		val += 1.0;
	while (val > 1)
		val -= 1.0;
	return (val);
}

void ft_get_pos(t_strip *strip)
{
	t_section	sec_wall;
	t_section	sec_ray;

	sec_ray.pos[0].xx = strip->xx;
	// printf("%f %f\n", sec_ray.pos[0].xx, strip->xx);
	sec_ray.pos[0].yy = strip->yy;
	sec_ray.pos[1].xx = strip->xx + 2 *\
		cosf(ft_to_diap(-0.25 + strip->dir) * M_PI * 2);
	sec_ray.pos[1].yy = strip->yy + 2 *\
		sinf(ft_to_diap(-0.25 + strip->dir) * M_PI * 2);
	ft_choice_wall(strip, &sec_wall);
	ft_cross(&sec_wall, &sec_ray, strip);
}

void ft_ray(t_base *base, t_strip *strip)
{
	while(1)
	{
		// ft_tamer(strip);
		ft_get_pos(strip);
		ft_tamer(strip);
		// printf("step %f %f %f\n", strip->xx, strip->yy, strip->dir);
		if (strip->xx < 0 || (int)strip->xx >= base->map.width || strip->yy < 0 || (int)strip->yy >= base->map.width)
			break;
		// printf("%f %f %d %d\n", strip->xx, strip->yy, base->map.h, base->height_screen);
		if (ft_impact(base, (int)strip->xx, (int)strip->yy) == '1')
			break;
	}
	strip->dist = sqrt(pow(strip->xx - base->player.xx, 2) + pow(strip->yy - base->player.yy, 2));
	// printf(" %f", strip->dist);
}

void ft_raycast(t_base *base, t_strip *strip)
{
	int i;
	float incr;
	float angle;

	i = 0;
	// strip[i]->dir += base->player.direct / base->width_screen;
	incr = 0.25 / base->width_screen;
	angle = base->player.direct - 0.25/2;
	while(i < base->width_screen)
	{
		// printf("ray\n");
		strip[i].dir = ft_to_diap(angle);
		strip[i].xx = base->player.xx;
		strip[i].yy = base->player.yy;
		ft_ray(base, strip + i);
		i++;
		angle += incr;
		// break;
	}
	// printf("\n");
}
