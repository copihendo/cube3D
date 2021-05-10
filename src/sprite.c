#include "cube.h"


int	ft_lst_cmp(t_sprite *sp1, t_sprite *sp2)
{
	return(sp1->dist < sp2->dist);
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
	t_list	*next;

	ptr = base->sprite;
	begin = 0;
	while(ptr)
	{
		sprite = (t_sprite *)ptr->content;
		sprite->dist = sqrt(pow((base->player.xx - sprite->pos.xx),2) + \
					pow((base->player.yy - sprite->pos.yy), 2));
		sprite->dir = ft_to_diap(1 - atan2(base->player.xx - sprite->pos.xx, base->player.yy - sprite->pos.yy) / (2 * M_PI));
		next = ptr->next;
		ft_lst_add_sort(&begin, ptr, (int(*)(void *, void *))ft_lst_cmp);
		ptr = next;
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
	ft_lstadd_back_content(&base->sprite, sprite);
}

void	ft_vertical_sptrite(t_base *base, t_sprite *sprite, int xx, float xx_otn)
{
	int val;
	int yy;
	int y_init;
	float yy_otn;
	float incr;
	t_color color;
	
	val = (int)((float)base->height_screen / sprite->dist);
	y_init = (base->height_screen - val) / 2;
	yy = y_init;
	yy_otn = 0;
	if (val)
		incr = 1.0 / (float)val;
	else
		incr = 0.0;
	while(yy < y_init + val && yy < base->height_screen)
	{
		// printf("%f %f ft_vertical_sptrite\n", xx_otn, yy_otn);
		if(yy >= 0)
		{
			color = ft_get_color_in_tex(base, 5, xx_otn, yy_otn);
			if (color.R || color.B || color.G)
				ft_mlx_pixel_put(&base->textures.screen, xx, yy, ft_get_color_in_tex(base, 5, xx_otn, yy_otn));
		}
		yy++;
		yy_otn += incr;
	}
}

void	ft_render_std_sprite(t_base *base, t_strip __attribute__((unused)) *strip, t_sprite *sprite)
{
	int xx;
	float xx_otn;
	int width_sprite;
	int pos_sprite;
	int x_init;
	float incr;

	xx_otn = 0;
	// printf("%f %f ft_render_std_sprite\n", sprite->dist, atan(0.5 / sprite->dist) / M_PI);
	width_sprite = (int)(((atan(0.5 / sprite->dist) / M_PI) / 0.25) * base->width_screen);
	pos_sprite = (int)(ft_to_diap(sprite->dir - (base->player.direct - 0.125)) / 0.25 * base->width_screen);
	// printf("%f grad %d pos\n", sprite->dir, pos_sprite);
	x_init = pos_sprite - width_sprite / 2;
	xx = x_init;
	if (width_sprite)
		incr = 1.0 / (float)width_sprite;
	else
		incr = 0.0;
	// printf("%d pos_sprite %f incr\n", pos_sprite, incr);
	while(xx < x_init + width_sprite)
	{
		if(xx >= 0 && xx < base->width_screen && strip[xx].dist > sprite->dist)
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
		ft_render_std_sprite(base, strip, (t_sprite *)ptr->content);
		ptr = ptr->next;
	}
}