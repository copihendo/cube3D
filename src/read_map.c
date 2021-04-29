/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:54:33 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/29 20:25:18 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_find_max_width(t_base *base, char **lines)
{
	size_t width;
	char *line;

	while ((line = lines[base->map.height]))
	{
		if ((width = ft_strlen(line)) > base->map.width)
			base->map.width = width;
		base->map.height++;
	}
}

void	*ft_transform_map(t_base *base, char **lines)  // функция преобразует карту, 
{
	int y;
	int x;
	char cell;
	char *ptr;
	static char *dir = "NWSE"; // указатель на direction для упрощения обработки карты

	if (!(base->map.data = ft_calloc(base->map.width * base->map.height, 1)))
		ft_exit(base);
	y = 0;
	while(lines[y])
	{
		x = 0;
		while((cell = lines[y][x])) // в конце запишется \0 в х и вайл оборвется
		{
			if ((ptr = ft_strchr(dir, cell))) 	// аналогия lines[i] == 'N' || lines[i] == 'W' || lines[i] == 'S' || lines[i] == 'E')
			{
				if (!(base->player.x == 0 && base->player.y == 0)) //  проверка, что конфиг для игрока чистый, т.е. игрок проверяется первый раз, иначе не валидная карта
					ft_exit(base);
				base->player.y = y + 0.5;									// записываем начальное положение игрока
				base->player.x = x + 0.5;
				base->player.direct = (float)(ptr - dir) / 4; 				// запись направления в структуру
				base->map.data[x + y * base->map.width] = '0';  			// заменяем начальное положение игрока на ноль.  
			}	//проверка что вообще есть игрок надо делать?
			else if (ft_strchr("012", cell))
				base->map.data[x + y * base->map.width] = cell;
			x++; 
		}
		y++;
	}
	return(0);
}

int	ft_check_map(t_base *base)							// проверка карты
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

// int (base, y ,x )
// {	
// 	return(cell = line y x)
// 	return(-1);
// }

int ft_read_map(t_base *base, char *line)
{
	ft_find_max_width(base, &line);
	ft_transform_map(base, &line);
	
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
	return(0);
}