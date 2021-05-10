/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_read_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:02:08 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 22:36:39 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h" 

char	*ft_read_file(const char *path)
{
	char	buffer[BUFFER_SIZE];
	char	*res;
	char	*for_free;
	int		fd;
	ssize_t	cnt_byte;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	res = ft_strdup("");
	cnt_byte = read(fd, buffer, BUFFER_SIZE - 1);
	while (res && cnt_byte)
	{
		buffer[cnt_byte] = '\0';
		for_free = res;
		res = ft_strjoin(res, buffer);
		free(for_free);
		cnt_byte = read(fd, buffer, BUFFER_SIZE - 1);
	}
	close(fd);
	return (res);
}
