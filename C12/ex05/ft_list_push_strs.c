#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	int		i;

	head = NULL;
	i = 0;
	if (strs == NULL)
		return (NULL);
	while (i < size)
	{
		ft_list_push_front(&head, strs[i]);
		i++;
	}
	return (head);
}
