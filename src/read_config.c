/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:42:08 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/01 16:33:48 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		ft_free(char **p)
{
	size_t i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

void	ft_parse_texture(t_base *base, t_image *texture)
{
	//texture = base->junk.words[1];
	int n;
	if(!(texture->link = mlx_xpm_file_to_image(base->mlx_ptr, base->junk.words[1], &texture->width, &texture->height)))
	{	
		write(1, "parse_texture_error\n", 20);
		ft_exit(base); 
	}
	// texture->color = (t_color *)mlx_get_data_addr(texture->link, &texture->bits_pix, &texture->line_len, &texture->endian);
	texture->color = (t_color *)mlx_get_data_addr(texture->link, &n, &n, &n);
	if(!texture->color)
		ft_exit(base);

// если линк нуль терминатор вызвать экзит
//проверить и вывести ошибку если есть, или стандратное закытие программы. 
}

// void ft_handle_textures(t_base *base)
// {
	
// }


int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int ft_color_atoi(t_base *base, char *kit)
{
	int i;
	int res;
	
	res = 0;
	// if (kit[0] == '0') ?????????? эти условия нужны ли?
	// { write(1, "color_atoi1\n", 12);
	// 	ft_exit(base);}
	i = 0;
	while (kit[i] >= '0' && kit[i] <= '9' )
	{
		// write(1, "color_atoi2\n", 12);
		res = res * 10 + (kit[i] - '0');
		i++;
	}
	printf("%d\n", res);
	if (kit[i] != '\0')
		ft_exit(base); 
	if (res >= 0 && res < 256)
	{	//write(1, "color_atoi3\n", 12);
	return (res);}
	else
		ft_exit(base);
		return(0); // ????
}

void ft_parse_color(t_base *base, t_color *color)
{
	printf("junk words %s\n", base->junk.words[1]);
	if(!(base->junk.kit = ft_split(base->junk.words[1], ',')))
	{	//write(1, "parse_color1\n", 12);
		ft_exit(base);}
	if (base->junk.kit[0] != 0 && base->junk.kit[1] != 0 && base->junk.kit[2] != 0 && base->junk.kit[3] == 0)
	{
		// write(1, "parse_color2\n", 13);
		color->R = ft_color_atoi(base, base->junk.kit[0]);
		color->G = ft_color_atoi(base, base->junk.kit[1]);
		color->B = ft_color_atoi(base, base->junk.kit[2]);
		color->flag = 1;
		// write(1, "parse_color3\n", 13);
	}
	else
		ft_exit(base);
}

int ft_check_number(t_base *base)
{
	int i;
	int j;

	i = 1;
	while(i < 3)
	{
		j = 0;
		while (base->junk.words[i][j])
		{
			if (base->junk.words[i][j] <= '0' && base->junk.words[i][j] >= '9')
				return(1);
			else
				j++;
		}
		i++;
	}
	return(0);		
}

void ft_check_screen_size(t_base *base)
{
	if (base->width_screen < 0 || base->height_screen < 0)
		printf("size of screen is nagetive\n");
	if (base->width_screen < 100)
		base->width_screen = 100;
	else if(base->width_screen >= 1920)
		base->width_screen = 1920;
	else if (base->height_screen < 100)
		base->height_screen = 100;
	else if (base->height_screen >= 1080)
		base->height_screen = 1080;
}

void ft_screen_size(t_base *base)
{
	int i;
	// write(1, "ft_screen_size1\n", 16);
	i = 0;
	while (base->junk.words[i])	// проверить что число слов 3
		i++;
	if(i != 3)
		printf("invalid number of arguments in resolution"); // если не совпалдает вызвать ft_exit
	if (!ft_check_number(base)) // проверить что 2 и 3 слово числа
		{	
			base->width_screen = ft_atoi(base->junk.words[1]); // фт_атои чар-инт
			base->height_screen = ft_atoi(base->junk.words[2]); // фт_атои чар-инт
		}
	else 
		printf("size is_not valid\n");	
	printf("%d %d\n",	base->width_screen, ft_atoi(base->junk.words[1]));
	ft_check_screen_size(base);	//сделать проверку на мининум, если меньше ставим 100 и максимум, и поставить ширину экрана 
	printf("%d\n",	ft_atoi(base->junk.words[2]));
	printf("function fr_screen size vrode works\n");

// 	base->width_screen = base->junk.lines[1]; 
// 	base->height_screen = base->junk.lines[2]; 
}


// void ft_read_config(t_base *base)
void ft_read_config(t_base *base, char *str)
{
	char *tag;
	size_t i;

	i = 0;
	// write(1, "read_config1\n", 13);
	// base->junk.words = ft_split(*base->junk.lines, ' ');
	base->junk.words = ft_split(str, ' ');
	// write(1, "read_config2\n", 13);
	tag = base->junk.words[0];
	printf("%s\n", tag);
	printf("junk.words[0] %s\n", base->junk.words[0]);
	printf("junk.words[1] %s\n", base->junk.words[1]);
	if (!ft_strcmp(tag, "R"))
	{	//write(1, "read_config3\n", 13);
		// printf("%s\n", tag);
		ft_screen_size(base);}
	else if (!ft_strcmp(tag, "NO"))
	{		//printf("%s\n", tag);
			// write(1, "read_config4\n", 13);
		ft_parse_texture(base, &base->textures.no);	}
	else if	(!ft_strcmp(tag, "SO"))
		{//write(1, "read_config5\n", 13);
		ft_parse_texture(base, &base->textures.so);}
	else if (!ft_strcmp(tag, "WE"))
{		//write(1, "read_config7\n", 13);
		ft_parse_texture(base, &base->textures.we);}
	else if	(!ft_strcmp(tag, "EA"))
	{	//write(1, "read_config8\n", 13);
		ft_parse_texture(base, &base->textures.ea);}
	else if (!ft_strcmp(tag, "S"))
	{	//write(1, "read_config9\n", 13);
		ft_parse_texture(base, &base->textures.s);	}
	else if	(!ft_strcmp(tag, "F"))
	// {	//write(1, "read_confi10\n", 13);
		ft_parse_color(base, &base->floor);
		// write(1, "read_confi11\n", 13);}
	else if	(!ft_strcmp(tag, "C"))
		ft_parse_color(base, &base->ceil);
	ft_free(base->junk.words);
	base->junk.words = 0;
}
