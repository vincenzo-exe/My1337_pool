#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*ft_list_last(t_list *begin_list);
#endif