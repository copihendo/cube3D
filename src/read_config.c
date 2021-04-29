/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:42:08 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/29 20:19:12 by mguadalu         ###   ########.fr       */
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

// void	ft_parse_texture(t_base *base, char *path, t_image *texture)
// {
// 	//texture = base->junk.words[1];
// 	int n;
// if(!(texture->link = mlx_xpm_file_to_image (base->mlx_ptr, base->junk.words[1], &texture->width, &texture->height));
// 	ft_exit(base);
// if(!(texture->color = (t_color *)mlx_get_data_addr(texture->link, &n, &n ,&n))
// 	ft_exit(base);
// // если линк нуль терминатор вызвать экзит
// //проверить и вывести ошибку если есть, или стандратное закытие программы. 
// }

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
	
	if (kit[0] == '0')
		ft_exit(base);
	i = 0;
	while (kit[i] >= '0' && kit[i] <= '9' )
	{
		res = res * 10 + (kit[i] - '0');
		i++;
	}
	if (kit[i] != '\0')
		ft_exit(base); 
	if (res >= 0 && res < 256)
		return (res);
	else
		ft_exit(base);
		return(0); // ????
}


void ft_parse_color(t_base *base, t_color *color)
{
	char **kit;  // ???
	if(!(kit = ft_split(base->junk.words[2], ',')))
		ft_exit(base);
	if (kit[0] != 0 && kit[1] != 0 && kit[2] != 0 && kit[3] == 0)
	{
		color->R = ft_color_atoi(base, base->junk.kit[0]);
		color->G = ft_color_atoi(base, base->junk.kit[1]);
		color->B = ft_color_atoi(base, base->junk.kit[2]);
		color->flag = 1;
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
			if (base->junk.words[i][j] <= 0 || base->junk.words[i][j] >= 9)
				return(-1);
			else
				j++;
		}
		i++;
	}
	return(0);		
}

void ft_check_screen_size(t_base *base)
{
	if (base->width_screen < 100)
		base->width_screen = 100;
	else if(base->width_screen > 1920)
		base->width_screen = 1920;
	else if (base->height_screen < 100)
		base->height_screen = 100;
	else if (base->height_screen > 1920)
		base->height_screen = 1920;
}

void ft_screen_size(t_base *base)
{
	int i;
	
	i = 0;
	while (base->junk.words[i])	// проверить что число слов 3
		i++;
	if(i != 2)
		printf("invalid number of arguments in resolution");
	i = 1;
	while (base->junk.words[i])
	{
		// if (ft_check_number(base->junk.words[i]) == 0) // проверить что 2 и 3 слово числа
		if (ft_check_number(base) == 0) // проверить что 2 и 3 слово числа
			while(base->junk.words[i])
			{
				if (i == 1)
					base->width_screen = ft_atoi(base->junk.words[i]); // фт_атои чар-инт
				if (i == 2)	
					base->height_screen = ft_atoi(base->junk.words[i]); // фт_атои чар-инт
				i++;
			}
		else 
			printf("size is_not valid\n");	
	} 
	ft_check_screen_size(base);	//сделать проверку на мининум, если меньше ставим 100 и максимум, и поставить ширину экрана 
	printf("function fr_screen size vrode works\n");
}

void ft_read_config(t_base *base)
{
	char *tag;

	base->junk.words = ft_split(*base->junk.lines, ' ');
	tag = base->junk.words[0];
	if (ft_strcmp(tag, "R"))
		ft_screen_size(base);
	// else if (ft_strcmp(tag, "NO"))
	// 	ft_parse_texture(base, &base->textures.no);	
	// else if	(ft_strcmp(tag, "SO"))
	// 	ft_parse_texture(base, &base->textures.so);
	// else if (ft_strcmp(tag, "WE"))
	// 	ft_parse_texture(base, &base->textures.we);
	// else if	(ft_strcmp(tag, "EA"))
	// 	ft_parse_texture(base, &base->textures.ea);
	// else if (ft_strcmp(tag, "S"))
	// 	ft_parse_texture(base, &base->textures.s);	
	else if	(ft_strcmp(tag, "F"))
		ft_parse_color(base, &base->floor);
	else if	(ft_strcmp(tag, "C"))
		ft_parse_color(base, &base->ceil);
	ft_free(base->junk.words);
	base->junk.words = 0;
}
