void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (begin_list1 == NULL)
		return ;
	current = *begin_list1;
	if (current == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = begin_list2;
}
