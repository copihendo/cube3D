/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:39:56 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:21:08 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cplst;
	t_list	*p;

	cplst = NULL;
	while (lst && f)
	{
		p = ft_lstnew(f(lst->content));
		if (!(p))
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&cplst, p);
		lst = lst->next;
	}
	return (cplst);
}
