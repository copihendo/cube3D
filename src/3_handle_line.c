/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handle_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:46:29 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/30 14:37:36 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// int ft_check_config(t_base base)
// {
// 	write(1, "ckeck_config1\n", 14);
// 	if (base.width_screen != 0 && base.height_screen != 0)
// 	{write(1, "ckeck_config2\n", 14);
// 		return (0);}
// 	else
// 	{write(1, "ckeck_config3\n", 14);
// 		return (1);}
// }

// void ft_handle_line(t_base *base)
// {
// 	size_t num_lines;
// 	char *line;
	
// 	base->junk.lines = ft_split(base->junk.file, '\n');
// 	num_lines = 0;
// 	// write(1, "handle_line1\n", 13);
// 	while ((line = base->junk.lines[num_lines]))
// 	{
// 		write(1, "handle_line2\n", 13);
// 		if(ft_check_config(*base))
// 		{
// 			write(1, "handle_line3\n", 13);
// 			ft_read_config(base);
// 			// printf("%s\n", base->)
// 		}
// 		else 
// 		{			write(1, "handle_line4\n", 13);
// 				ft_read_map(base, line);}
// 		num_lines++;
// 	}
// }
