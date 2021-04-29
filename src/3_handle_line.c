/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handle_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:46:29 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/29 21:36:34 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ft_handle_line(t_base *base)
{
	// size_t num_lines;
	// char *line;
	
	// base->junk.lines = ft_split(base->junk.file, '\n');
	// num_lines = 0;
	// while ((line = base->junk.lines[num_lines]))
	// {
	// 	if(ft_check_config(*base))
	// 		ft_read_config(line);
	// 	else 
	// 		ft_read_map(base, line);
	// 	num_lines++;
	// }

	size_t num_lines;
	char *line;
	
	base->junk.lines = ft_split(base->junk.file, '\n');
	num_lines = 0;
	write(1, "handle_line1\n", 13);
	while ((line = base->junk.lines[num_lines]))
	{
		write(1, "handle_line2\n", 13);
		if(ft_check_config(*base))
		{
			write(1, "handle_line3\n", 13);
			ft_read_config(base);
		}
		else 
			ft_read_map(base, line);
		num_lines++;
	}
}
