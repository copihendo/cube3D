/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:26:54 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/16 18:36:07 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

void	ft_parse(t_base *base, const char *path)
{
	if(!(base->junk.file = ft_read_file(path)))
		ft_exit(base);
	ft_handle_line(base); 
}
