/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:10:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/18 17:33:46 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*ptr;
	t_list	*ptr2;

	if (!del || !lst || !*lst)
		return ;
	ptr = (*lst);
	while (ptr->next != NULL)
	{
		ptr2 = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = ptr2;
	}
	ft_lstdelone(ptr, del);
	*lst = NULL;
	return ;
}
