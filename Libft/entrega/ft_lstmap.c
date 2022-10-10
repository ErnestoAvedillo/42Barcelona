/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:10:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/18 17:33:46 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void ( *del)(void *))
{
	t_list	*ptr;
	t_list	*inicio;

	if (!lst)
		return (NULL);
	inicio = NULL;
	while (lst)
	{
		ptr = ft_lstnew (f(lst->content));
		if (!ptr)
		{
			ft_lstclear (&inicio, del);
			return (NULL);
		}
		ft_lstadd_back (&inicio, ptr);
		lst = lst->next;
	}
	return (inicio);
}
