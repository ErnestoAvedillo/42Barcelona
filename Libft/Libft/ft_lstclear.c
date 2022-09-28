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
void	ft_lstclear(t_list **lst, void (*del)(void *));
{
	void temp *ptr;

	if (lst && del && *lst)
	{
		while (*lst)
		{	
			ptr = *lst -> next
			ft_lstdelone(*lst, (del)(void *));
			*lst = ptr;
		}
	}
}