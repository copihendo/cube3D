#include "cube.h"

static void	ft_move_player(t_base *base, char key)
{
	// printf("1 ft_move_player %f %f\n", base->player.xx, base->player.yy);
	base->player.move_speed = 0.15;
	if (key == 'W')
	{
		base->player.xx += base->player.dir.xx * base->player.move_speed;
		base->player.yy += base->player.dir.yy * base->player.move_speed;
	}
	if (key == 'S')
	{
		base->player.xx -= base->player.dir.xx * base->player.move_speed;
		base->player.yy -= base->player.dir.yy * base->player.move_speed;
	}
	if (key == 'A')
	{
		base->player.xx += base->player.dir.yy * base->player.move_speed;
		base->player.yy -= base->player.dir.xx * base->player.move_speed;
	}
	if (key == 'D')
	{
		base->player.xx -= base->player.dir.yy * base->player.move_speed;
		base->player.yy += base->player.dir.xx * base->player.move_speed;
	}
	// printf("2 ft_move_player %f %f\n", base->player.xx, base->player.yy);
}

static void	ft_move_camera(t_base *base, char key)
{
	// float old_plane_x;
	// float old_dir_x;
	// float rot;

	// old_plane_x = base->player.plane.xx;
	// old_dir_x = base->player.dir.xx;
	base->player.direct = ft_to_diap(base->player.direct + ROT_SPEED * ((key == RF) * 2 - 1));
	base->player.dir.xx = cosf(ft_to_diap(-0.25 + base->player.direct) * M_PI * 2);
	base->player.dir.yy = sinf(ft_to_diap(-0.25 + base->player.direct) * M_PI * 2);
	// base->player.dir.xx = base->player.dir.xx * cos(rot) - base->player.dir.yy * sin(rot);
	// base->player.dir.yy = old_dir_x * sin(rot) + base->player.dir.yy * cos(rot);
	// base->player.plane.xx = base->player.plane.xx * cos(rot) \
	// - base->player.plane.yy * sin(rot);
	// base->player.plane.yy = old_plane_x * sin(rot) + base->player.plane.yy * cos(rot);
}

void		ft_check_keys(t_base *base)
{
	if (base->key.w == 1 && '0' == ft_impact(base, base->player.xx + \
	 base->player.dir.xx * base->player.move_speed, base->player.yy + \
	 base->player.dir.yy * base->player.move_speed))
		ft_move_player(base, 'W');
	if (base->key.s == 1 && '0' == ft_impact(base, base->player.xx - \
	 base->player.dir.xx * base->player.move_speed, base->player.yy - \
	 base->player.dir.yy * base->player.move_speed))
		ft_move_player(base, 'S');
	if (base->key.a == 1 && '0' == ft_impact(base, base->player.xx - \
	 base->player.plane.xx * base->player.move_speed, base->player.yy - \
	 base->player.plane.yy * base->player.move_speed))
		ft_move_player(base, 'A');
	if (base->key.d == 1 && '0' == ft_impact(base, base->player.xx + \
	 base->player.plane.xx * base->player.move_speed, base->player.yy + \
	 base->player.plane.yy * base->player.move_speed))
		ft_move_player(base, 'D');
	if (base->key.l == 1)
		ft_move_camera(base, LF);
	if (base->key.r == 1)
		ft_move_camera(base, RF);
}

int			ft_key_in(int keycode, t_base *base)
{
	if (keycode == W)
		base->key.w = 1;
	if (keycode == S)
		base->key.s = 1;
	if (keycode == A)
		base->key.a = 1;
	if (keycode == D)
		base->key.d = 1;
	if (keycode == LF)
		base->key.l = 1;
	if (keycode == RF)
		base->key.r = 1;
	if (keycode == esc)
		ft_exit(base);
	return (0);
}

int			ft_key_out(int keycode, t_base *base)
{
	if (keycode == W)
		base->key.w = 0;
	if (keycode == S)
		base->key.s = 0;
	if (keycode == A)
		base->key.a = 0;
	if (keycode == D)
		base->key.d = 0;
	if (keycode == LF)
		base->key.l = 0;
	if (keycode == RF)
		base->key.r = 0;
	return (0);
}