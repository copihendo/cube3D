/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:39:56 by mguadalu          #+#    #+#             */
/*   Updated: 2020/11/14 21:07:24 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *cplst;
	t_list *p;

	cplst = NULL;
	while (lst && f)
	{
		if (!(p = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&cplst, p);
		lst = lst->next;
	}
	return (cplst);
}
