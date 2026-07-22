#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, int index)
{
	while (index > 0)
	{
		begin_list = begin_list->next;
		index--;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*node_i;
	t_list	*node_j;
	void	*tmp;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		node_i = ft_list_at(begin_list, i);
		node_j = ft_list_at(begin_list, size - i - 1);
		tmp = node_i->data;
		node_i->data = node_j->data;
		node_j->data = tmp;
		i++;
	}
}
