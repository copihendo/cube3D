/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:26:54 by copihendo         #+#    #+#             */
/*   Updated: 2021/03/14 05:01:20 by copihendo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

void    ft_parse(t_base *base, const char *path)
{
	if(!(base->junk.file = ft_read_file(path)))
		ft_exit(base);
	ft_handle_line(base); 
}
