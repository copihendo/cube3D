/*#include "cube.h"


int	ft_lst_cmp(t_sprite *sp1, t_sprite *sp2)
{
	return(sp1->dist > sp2->dist);
}

void ft_lst_add_sort(t_list **begin, t_list *new, int (*ft_cmp)(void *, void *))
{
	t_list *ptr;

	t_list	*lst_last;
	ptr = *begin;
	lst_last = 0;
	while (ptr && !ft_cmp(ptr->content, new->content))
	{
		lst_last = ptr;
		ptr = ptr->next;
	}
	if(lst_last)
		lst_last->next = new;
	else
		*begin = new;
	new->next = ptr;
} 

// функция для либы ft_lst_add_sort(t_list **begin, t_list *new, void (*ftcmp)(void *контент, void *))
// добавить бегин в определенное место в зависимости от того, что покажет смп
// 0 3 4 6 10 12  

void ft_fill_sprite(t_base *base)
{
	t_list *ptr;
	t_sprite *sprite;
	t_list *begin;

	ptr = base->sprite;
	while(ptr)
	{
		sprite = (t_sprite *)ptr->content;
		sprite->dist = sqrt(pow((base->player.xx - sprite->pos.xx),2) + \
					pow((base->player.yy - sprite->pos.xx), 2));
		sprite->dir = atan((sprite->pos.xx - base->player.xx) / (sprite->pos.yy - base->player.yy)) / (2 * M_PI);
		ptr = ptr->next;
		ft_lst_add_sort(&begin, ptr, (int(*)(void *, void *))ft_lst_cmp);
	}
	base->sprite = begin;
}

void ft_init_sprite(t_base *base, int x, int y)
{

	t_sprite *sprite; 

	// замолочить область памяти под структуру спрайт
	sprite = malloc(sizeof(t_sprite));
	// заполнить ху(+0.5)
	sprite->pos.xx = (float)x + 0.5;
	sprite->pos.yy = (float)y + 0.5;
	// добавить через add_back_kontent
	ft_lstadd_back_content(base->sprite, sprite);
}

void	ft_vertical_sptrite(t_base *base, t_sprite *sprite, int xx, int xx_otn)
{
	int val;
	int yy;
	int y_init;
	float yy_otn;
	float incr;
	
	val = base->height_screen / sprite->dist;
	y_init = (base->height_screen - val) / 2;
	yy = y_init;
	yy_otn = 0;
	if (val)
		incr = 1.0 / (float)val;
	else
		incr = 0.0;
	while(yy < y_init + val && yy < base->height_screen)
	{
		if(yy >= 0)
			ft_mlx_pixel_put(&base->textures.screen, xx, yy, ft_get_color_in_tex(base, 5, xx_otn, yy_otn));
		yy++;
		yy_otn += incr;
	}
}

void	ft_render_std_sprite(t_base *base, t_strip *strip, t_sprite *sprite)
{
	int xx;
	float xx_otn;
	int width_sprite;
	float pos_sprite;
	int x_init;
	int incr;

	xx_otn = 0;
	width_sprite = ((atan(0.5 / sprite->dist) / (2 * M_2_PI)) / 0.25) * base->width_screen;
	pos_sprite = (int)((sprite->dir - base->player.dir - 0.125) / 0.25 * base->width_screen);
	x_init = pos_sprite - width_sprite / 2;
	xx = x_init;
	if (width_sprite)
		incr = 1.0 / (float)width_sprite;
	else
		incr = 0.0;
	while(xx < x_init + width_sprite)
	{
		if(xx >= 0 && xx < base->width_screen)
			ft_vertical_sptrite(base, sprite, xx, xx_otn);
		xx++;
		xx_otn += incr;
	}
}

void	ft_render_sprite(t_base *base, t_strip *strip)
{
	t_list *ptr;

	ptr = base->sprite; 
	while(ptr)
	{
		ft_render_std_sprite(base, strip, ptr->content);
		ptr = ptr->next;
	}
}*/