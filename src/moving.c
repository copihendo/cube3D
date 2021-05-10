#include "cube.h"

static void	ft_move_player(t_base *base)
{
	int forward;
	int shift;
	float delta_xx;
	float delta_yy;

	forward = base->key.w - base->key.s;
	shift = base->key.d - base->key.a;
	base->player.move_speed = 0.15;
	delta_xx = (base->player.dir.xx * forward - base->player.dir.yy * shift) * base->player.move_speed;
	delta_yy = (base->player.dir.xx * shift + base->player.dir.yy * forward) * base->player.move_speed;
	if (ft_impact(base, (int)(delta_xx + base->player.xx), (int)base->player.yy) == '0')
		base->player.xx += delta_xx;
	if (ft_impact(base, (int)base->player.xx, (int)(base->player.yy + delta_yy)) == '0')
		base->player.yy += delta_yy;
}

static void	ft_move_camera(t_base *base)
{
	base->player.direct = ft_to_diap(base->player.direct + ROT_SPEED * (base->key.r - base->key.l));
	base->player.dir.xx = cosf(ft_to_diap(-0.25 + base->player.direct) * M_PI * 2);
	base->player.dir.yy = sinf(ft_to_diap(-0.25 + base->player.direct) * M_PI * 2);
}

void		ft_check_keys(t_base *base)
{
	ft_move_player(base);
	ft_move_camera(base);
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
		ft_exit(base, "DO NOT tuch ESQ\nGame over");
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