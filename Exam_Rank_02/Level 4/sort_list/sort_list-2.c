#include"list.h"
#include <stdlib.h>
#include <stdio.h>

int ascending(int a, int b)
{
	return (a <= b);
}

t_list *get_first(t_list *lst, int (*cmp)(int, int))
{
    t_list *element_a;
    t_list *element_b;
    t_list *element_c;

    element_a = lst;
    element_b = element_a->next;
    element_c = element_b->next;
    if (!cmp(element_a->data, element_b->data))
    {
        lst = element_b;
        lst->next = element_a;
        element_a->next = element_c;
    }
    return (lst);
}
    t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *element_a;
    t_list *element_b;
    t_list *element_c;

    if (!lst || !lst->next)
        return (lst);
    lst = get_first(lst, cmp);
    element_a = lst;
    element_b = element_a->next;
    element_c = element_b->next;
    while (element_c)
    {
        if (!cmp(element_b->data,element_c->data))
        {
            element_a->next = element_c;
            element_b->next = element_c->next;
            element_c->next = element_b;
            lst = get_first(lst, cmp);
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


#include<stdio.h>
int main (int av, char **ac)
{
    int i;
    t_list *lst;
    t_list *element_a;
    t_list *element_b;

    i = 1;
    if (av < 2)
        return (0);
    lst = (t_list *)malloc(sizeof(t_list));
    lst->data = atoi(ac[i]);
    element_a = lst;
    while (++i < av)
    {
        element_b = (t_list *)malloc(sizeof(t_list));
        element_a->next = element_b;
        element_b->data = atoi(ac[i]);
        element_b->next = NULL;
        element_a = element_b;
    }
    element_a = lst;
    while (element_a)
    {
        printf("dato (%p) %i -->%p \n", element_a,  element_a->data, element_a->next);
        element_a = element_a->next;
    }
    printf("entro\n");
    lst = sort_list(lst,ascending);
    printf("salgo\n");
    element_a = lst;
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
