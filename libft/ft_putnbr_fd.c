/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:36:45 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:26:02 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	val;

	val = n;
	if (val < 0)
	{
		ft_putchar_fd('-', fd);
		val = -val;
	}
	if (val >= 10)
		ft_putnbr_fd(val / 10, fd);
	ft_putchar_fd((val % 10) + '0', fd);
}
