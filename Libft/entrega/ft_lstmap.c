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

	inicio = NULL;
	while (lst->next != NULL)
	{
		ptr = ft_lstnew (f(lst->content));
		if (!ptr)
		{
			ft_lstdelone (ptr, del);
			return (inicio);
		}
		ft_lstadd_back (&inicio, ptr);
		lst = lst->next;
	}
	ptr = ft_lstnew (f(lst->content));
	if (!ptr)
	{
		ft_lstdelone (ptr, del);
		return (inicio);
	}
	ft_lstadd_back (&inicio, ptr);
	return (inicio);
}
