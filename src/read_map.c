/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:54:33 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/11 19:59:10 by copihendo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_find_max_width(t_base *base, char **lines)
{
	int width;
	char *line;

	// line = lines[base->map.height];
	while ((line = lines[base->map.height]) && base->map.height < 70)
	{
		// line = lines[base->map.height];
		// printf("width %zu\n", base->map.width);
		// printf("height %zu\n", base->map.height);
		// printf("line %s\n", line);
		width = ft_strlen(line);
		// printf("width_ftstrlen %zu\n", width);
		// printf("LEN %s\n", line);
		if (width > base->map.width)
			base->map.width = width;
		base->map.height++;
	}
	printf("FINAL width %d\n", base->map.width);
	printf("FINAL height %d\n", base->map.height);
}

void ft_init_sprite(t_base *base, int x, int y)
{

	t_sprite *sprite; 

	// замолочить область памяти под структуру спрайт
	sprite = malloc(sizeoff(t_sprite));
	// заполнить ху(+0.5)
	sprite.pos.xx = x + 0.5;
	sprite.pos.yy = y + 0.5;
	// добавить через add_back_kontent

}

void	*ft_transform_map(t_base *base, char **lines)  // функция преобразует карту, 
{
	int y;
	int x;
	char cell;
	char *ptr;
	static char *dir = "NWSE"; // указатель на direction для упрощения обработки карты

	// printf("transform map start\n");
	if (!(base->map.data = ft_calloc(base->map.width * base->map.height + 1, 1)))
		ft_exit(base);
	// printf("size calloc %lu\n", base->map.width * base->map.height + 1);
	// printf("transform map make calloc\n");
	// printf("map.data %s\n", base->map.data);
	// write(1, &base->map.data, 70);
	y = 0;
	while(y < base->map.height)
	// while(y < 10)
	// while(lines[y])
	{
		// printf("lines %s\n", lines[y]);
		x = 0;
		while(lines[y][x]) // в конце запишется \0 в х и вайл оборвется
		// while(x < base->map.width) // в конце запишется \0 в х и вайл оборвется
		{
			cell = lines[y][x];
			if ((ptr = ft_strchr(dir, cell))) 	// аналогия lines[i] == 'N' || lines[i] == 'W' || lines[i] == 'S' || lines[i] == 'E')
			{
				if (!(base->player.xx == 0 && base->player.yy == 0)) //  проверка, что конфиг для игрока чистый, т.е. игрок проверяется первый раз, иначе не валидная карта
					ft_exit(base);
				base->player.yy = y + 0.5;									// записываем начальное положение игрока
				base->player.xx = x + 0.5;
				base->player.direct = (float)(ptr - dir) / 4; 				// запись направления в структуру
				base->map.data[x + y * base->map.width] = '0';  			// заменяем начальное положение игрока на ноль.  
			}	//проверка что вообще есть игрок надо делать?
			else if (ft_strchr("012", cell))
				base->map.data[x + y * base->map.width] = cell;
			if(cell == '2')
				ft_init_sprite();
				// else if (ft_strchr(" ", cell))
				// 	base->map.data[x + y * base->map.width] = 0;
			x++;
		}
		y++;
	}
	printf("transform map end\n");
	return(0);
}

int		ft_check_map(t_base *base)							// проверка карты
{
	size_t i;
	size_t length;

	i = 0;
	length = base->map.height * base->map.width;		// длина одномерного массива 
	while(i < length)
	{
		if (base->map.data[i] == '0')					//  проверка правильности пустого пространства
		{
			if (base->map.data[i + 1] == '\0' || base->map.data[i - 1] == '\0' ||
				base->map.data[i - base->map.width] == '\0' || base->map.data[i + base->map.width] == '\0')
				return (-1); // the map is not valid
		}
		i++;
	}
	return(0);
}

void	ft_direct(t_base *base)
{
	if(base->player.direct < 0.25)
		base->player.dir.yy = -1;
	else if(base->player.direct < 0.5)
		base->player.dir.xx = -1;
	else if(base->player.direct < 0.75)
		base->player.dir.yy = 1;
	else
		base->player.dir.xx = 1;
}

int		ft_read_map(t_base *base, char **line)
{
	// printf("%zu\n", base->map.height);
	ft_find_max_width(base, line);
	printf("enter to transform map start\n");
	ft_transform_map(base, line);
	ft_direct(base);
	if(ft_check_map(base) == -1)
		printf("invalid structure map do not change");
	return(0);
}




	// while (line = base->junk.lines[num_lines])
	// {
	// 	if ((width = ft_strlen(line)) > base->junk.max_width) // в теории можно обойтись без цшвек в junk
	// 		base->junk.max_width = width;
	// 	ft_lstadd_back(begin_list, ft_lstnew(line));
	// }
	// while (ptr != NULL)
	// {
	// 	//if (ft_strlen(list->content) < base->junk.max_width)
	// ft_max_widh(base->junk.lines[num_lines])	
	// 	if ((add_wdth = base->junk.max_width - ft_strlen(list->content) > 0)
	// 	{
	// 		content = 
	// 		ft_lstadd_back_content(begin_list, )
	// 	}
	// }
	// ft_extans_map();