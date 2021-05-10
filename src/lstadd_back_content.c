/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 05:20:57 by copihendo         #+#    #+#             */
/*   Updated: 2021/05/10 14:07:11 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_list	*ft_lstadd_back_content(t_list **list, void *content)
{
	t_list	*last;
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
	{
		last = ft_lstlast(*list);
		if (!last)
			*list = new;
		else
			last->next = new;
	}
	return (new);
}
