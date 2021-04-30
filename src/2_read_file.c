/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_read_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:02:08 by copihendo         #+#    #+#             */
/*   Updated: 2021/04/30 14:39:22 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h" 

char *ft_read_file(const char *path)
{
	char    buffer[BUFFER_SIZE];
	char    *res;
	char    *for_free;
	int     fd;
	ssize_t cnt_byte;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	res = ft_strdup("");
	write(1, "read_fil1\n", 10);
	while (res && (cnt_byte = read(fd, buffer, BUFFER_SIZE - 1)))
	{
		buffer[cnt_byte] = '\0';
		for_free = res;
		res = ft_strjoin(res, buffer);
		free(for_free);
		write(1, "read_fil2\n", 10);
	}
	write(1, "read_fil3\n", 10);
	close(fd);
	return (res);
	// if(!(arr=malloc(sizeof(char)*ft_strlen(path) + 1)))
		// return (NULL);
	
}
