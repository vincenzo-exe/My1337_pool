#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	void	*temp;
	int		swapped;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *begin_list;
		while (current->next != NULL)
		{
			if (cmp(current->data, current->next->data) > 0)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
}
