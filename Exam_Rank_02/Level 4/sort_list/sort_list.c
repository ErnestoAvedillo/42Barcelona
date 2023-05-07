/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:08:26 by eavedill          #+#    #+#             */
/*   Updated: 2023/05/02 11:27:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *aux;
	int tmp;
	aux = lst;
	while(aux->next)
	{
		if (!cmp(aux->data, aux->next->data))
		{
			tmp = aux->next->data;
			aux->next->data = aux->data;
			aux->data = tmp; 
			aux = lst;
		}
		else
			aux = aux->next;
	}
	return (lst);
}

/*
int ascending(int a, int b)
{
	return (a <= b);
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main (int av, char **ac)
{
	int j = 1;
	t_list *lst;
	t_list *aux1;
	t_list *aux2;

	if (av < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	lst = (t_list *) malloc(sizeof(t_list));
	lst->data = atoi(ac[j]);
	lst->next = 0;
	aux2 = lst;
	while(++j < av)
	{
		aux1 = (t_list *) malloc(sizeof(t_list));
		aux1->data = atoi(ac[j]);
		aux1->next = NULL;
		aux2->next = aux1;
		aux2 = aux1;
	}
	aux1 = lst;
	printf("ANTES\n");
	while(aux1)
	{
		printf("%p -- %i -- %p\n",aux1, aux1->data, aux1->next);
		aux1 = aux1->next;
	}
	sort_list(lst,ascending);
	printf("DESPUES\n");
	aux1 = lst;
	while(aux1)
	{
		printf("%p -- %i -- %p\n",aux1, aux1->data, aux1->next);
		aux1 = aux1->next;
	}
	return (0);
}*/
