#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*new_e;

	new_e = malloc(sizeof(t_list));
	if (new_e == NULL)
		return (NULL);
	new_e->data = data;
	new_e->next = NULL;
	return (new_e);
}
