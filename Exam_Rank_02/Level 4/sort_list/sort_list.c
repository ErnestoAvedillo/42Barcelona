#include"list.h"
#include<stdlib.h>
/*
int ascending(int a, int b)
{
	return (a <= b);
}
*/
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *element_a;
    t_list *element_b;
    t_list *element_c;

    element_a = lst;
    element_b = element_a->next;
    element_c = element_b->next;

    while(element_c)
    {
        if (!cmp(element_b->data,element_c->data))
        {
            element_a->next = element_c;
            element_b->next = element_c->next;
            element_c->next = element_b;
            element_a = lst;
            element_b = element_a->next;
            element_c = element_b->next;
        }
        else
        {
            element_a = element_b;
            element_b = element_a->next;
            element_c = element_b->next;
        }
    }
    return (lst);
}

/*
#include<stdio.h>
int main (void)
{
    int i[20]={2, 9, 66, 7, 543, 32, 55, 67, 95, 8, 6, 33, 28, 345, 664, 78, 23, 54, 653, 90 };
    int j;
    t_list *lst;
    t_list *element_a;
    t_list *element_b;

    j = 0;
    lst = (t_list *) malloc (sizeof (t_list));
    element_a = (t_list *) malloc (sizeof (t_list));
    lst->next = element_a;
    element_a->data = i[j];
    while (++j < 20)
    {
        element_b = (t_list *)malloc(sizeof(t_list));
        element_a->next = element_b;
        element_b->data = i[j];
        element_b->next = NULL;
        element_a = element_b;
    }
    element_a = lst->next;
    while (element_a)
    {
        printf("dato (%p) %i -->%p \n", element_a,  element_a->data, element_a->next);
        element_a = element_a->next;
    }
    printf("entro\n");
    sort_list(lst,ascending);
    printf("salgo\n");
    element_a = lst->next;
    while (element_a)
    {
        printf("dato (%p) %i -->%p \n", element_a,  element_a->data, element_a->next);
        element_a = element_a->next;
    }
    element_a = lst->next;
    while (element_a)
    {
        element_b = element_a->next;
        free(element_a);
        element_a = element_b;
    }
    free(lst);
}
*/