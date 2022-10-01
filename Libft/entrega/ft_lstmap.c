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
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	void *ptr;

	if (lst && f && del)
	{
		ptr = lst
		while (ptr != NULL)
			{
				(f)(ptr);
				del(ptr);
				ptr = lst->next;
			}
	}
}