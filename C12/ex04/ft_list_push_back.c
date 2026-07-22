#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_e;
	t_list	*current;

	new_e = ft_create_elem(data);
	if (new_e == NULL)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new_e;
		return ;
	}
	current = *begin_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_e;
}
