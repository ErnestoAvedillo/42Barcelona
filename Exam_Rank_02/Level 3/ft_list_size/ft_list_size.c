#include"./ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main (int av, char **ac)
{
	int i;
	t_list *frst;
	t_list *ptr1;
	t_list *ptr2;
	
	if (av > 1)
	{
		frst = (t_list *)malloc(sizeof(t_list));
		ptr1 = frst;
		ptr1->data = ac[1];
		i = 2;
		while (i < av )
		{
			ptr2 = (t_list *)malloc(sizeof(t_list));
			ptr2->data = ac[i];
			ptr1 -> next = ptr2;
			ptr1 = ptr2;
			i++;
		}
		i = 1;
		ptr1 = frst;
		while (ptr1)
		{
			printf("valor %p ---- %s\n",ptr1, (char *)ptr1->data);
			ptr1 = ptr1->next;
			i++;
		}
		printf("elementos : %i\n", ft_list_size(frst));
		ptr1 = frst;
		while (ptr1)
		{
				ptr1 = frst->next;
				free(frst);
				frst = ptr1;
		}
	}
}
*/