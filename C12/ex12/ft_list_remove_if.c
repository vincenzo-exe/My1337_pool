#include "ft_list.h"
#include <stdlib.h>

void	remove_node(t_list **begin_list, t_list **prev, t_list **current,
		void (*free_fct)(void *))
{
	t_list	*temp;

	temp = *current;
	if (*prev == NULL)
		*begin_list = (*current)->next;
	else
		(*prev)->next = (*current)->next;
	*current = (*current)->next;
	free_fct(temp->data);
	free(temp);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*current;

	if (begin_list == NULL)
		return ;
	prev = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		if (cmp(current->data, data_ref) == 0)
			remove_node(begin_list, &prev, &current, free_fct);
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
