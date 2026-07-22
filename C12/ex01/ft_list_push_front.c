#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_e;

	if (begin_list == NULL)
		return ;
	new_e = ft_create_elem(data);
	if (new_e == NULL)
		return ;
	new_e->next = *begin_list;
	*begin_list = new_e;
}
