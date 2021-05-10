#include "cube.h"

int	ft_lst_cmp(t_sprite *sp1, t_sprite *sp2)
{
	return (sp1->dist < sp2->dist);
}

void	ft_lst_add_sort(\
			t_list **begin, t_list *new, int (*ft_cmp)(void *, void *))
{
	t_list	*ptr;
	t_list	*lst_last;

	ptr = *begin;
	lst_last = 0;
	while (ptr && !ft_cmp(ptr->content, new->content))
	{
		lst_last = ptr;
		ptr = ptr->next;
	}
	if (lst_last)
		lst_last->next = new;
	else
		*begin = new;
	new->next = ptr;
}
