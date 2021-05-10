/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:42:08 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/09 22:55:32 by telron           ###   ########.fr       */
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

int ft_check_link(t_base *base)
{
	int i; 
	static char *ext = ".xpm";

	i = ft_strlen(base->junk.words[1]) - 4;
	while(base->junk.words[1][i] != '\0')
	{
		if (ft_strchr(ext, base->junk.words[1][i])) // проверить что все файлф заканчиваются на .xpm
			i++;
		else
			return (-1);
	}
	return (0);
}

void	ft_parse_texture(t_base *base, t_image *texture)
{
	//texture = base->junk.words[1];
	int n;

	if(!(texture->link = mlx_xpm_file_to_image(base->mlx_ptr, base->junk.words[1], &texture->width, &texture->height )))
	{	
		// write(1, "parse_texture_error\n", 20);
		ft_exit(base, "parse_texture_error"); 
	}
	if(ft_check_link(base) == -1)
	{
		// write(1, "invalid extension of texture\n", 29); // оу щит, эта проверка не нужна была..... mlx_xpm и так ее проверяет
		ft_exit(base, "invalid extension of texture");
	} 
	// texture->color = (t_color *)mlx_get_data_addr(texture->link, &texture->bits_pix, &texture->line_len, &texture->endian);
	texture->data = (t_color *)mlx_get_data_addr(texture->link, &n, &n, &n);
	if(!texture->data)
		ft_exit(base, "texture->data");
// если линк нуль терминатор вызвать экзит
//проверить и вывести ошибку если есть, или стандратное закытие программы. 
}

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
	i = 0;
	while (kit[i] >= '0' && kit[i] <= '9' )
	{
		res = res * 10 + (kit[i] - '0');
		i++;
	}
	if (kit[i] != '\0')
		ft_exit(base, "Color out of range");
	if (res < 0 || res > 255)
		ft_exit(base, "Color out of range");
	return (res);
}

void ft_parse_color(t_base *base, t_color *color)
{
	// printf("junk words %s\n", base->junk.words[1]);
	if(!(base->junk.kit = ft_split(base->junk.words[1], ',')))
	{	//write(1, "parse_color1\n", 12);
		ft_exit(base, "Invalid colors");
	}
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
		ft_exit(base, "Invalid colors");
	ft_free(base->junk.kit);
	base->junk.kit = 0;
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
		ft_exit(base, "invalid number of arguments in resolution"); // если не совпалдает вызвать ft_exit
	if (!ft_check_number(base)) // проверить что 2 и 3 слово числа
		{	
			base->width_screen = ft_atoi(base->junk.words[1]); // фт_атои чар-инт
			base->height_screen = ft_atoi(base->junk.words[2]); // фт_атои чар-инт
		}
	else
		ft_exit(base, "size is_not valid");
	// printf("%d %d\n",	base->width_screen, ft_atoi(base->junk.words[1]));
	ft_check_screen_size(base);	//сделать проверку на мининум, если меньше ставим 100 и максимум, и поставить ширину экрана 
	// printf("%d\n",	ft_atoi(base->junk.words[2]));
	// printf("function fr_screen size vrode works\n");

// 	base->width_screen = base->junk.lines[1]; 
// 	base->height_screen = base->junk.lines[2]; 
}

void ft_read_config(t_base *base, char *str)
{
	char *tag;
	size_t i;

	i = 0;
	base->junk.words = ft_split(str, ' ');
	tag = base->junk.words[0];
	if (!ft_strcmp(tag, "R"))
		ft_screen_size(base);
	else if (!ft_strcmp(tag, "NO"))
		ft_parse_texture(base, &base->textures.no);
	else if	(!ft_strcmp(tag, "SO"))
		ft_parse_texture(base, &base->textures.so);
	else if (!ft_strcmp(tag, "WE"))
		ft_parse_texture(base, &base->textures.we);
	else if	(!ft_strcmp(tag, "EA"))
		ft_parse_texture(base, &base->textures.ea);
	else if (!ft_strcmp(tag, "S"))
		ft_parse_texture(base, &base->textures.s);
	else if	(!ft_strcmp(tag, "F"))
		ft_parse_color(base, &base->floor);
	else if	(!ft_strcmp(tag, "C"))
		ft_parse_color(base, &base->ceil);
	ft_free(base->junk.words);
	base->junk.words = 0;
}
