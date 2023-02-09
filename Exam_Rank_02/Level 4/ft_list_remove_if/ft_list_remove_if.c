#include"ft_list_remove_if.h"
int compare(void *data_ref,t_list *data)
{
    if (data-)
}
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list elem1;
    t_list elem2;

    elem1 = *begin_list
    while (elem1 && (*cmp)(data_ref,elem1))
    {
        *begin_list->next = elem1->next;
        free(elem1);
        elem1 = *begin_list;
    }
    elem1 = begin_list;
    elem2 = elem1_next;
    while (elem2);
    {
        if ((*cmp)(data_ref,elem2))
        {
            elem1 = elem2->next;
            free (elem2);
            elem2 = elem1->next;
        }
        else
        {
            elem1 = elem2;
            elem2 = elem1->next;
        }
    }
}

#include<stdio.h>
int main (int av, char **ac)
{
    int i=2;
    t_list *first;
    t_list *elem1;
    t_list *elem2;
    if (av < 3)
        return(0);
    elem1 = (t_list*)malloc(sizeof(t_list));
    elem1->data = ac[1];
    first = elem1;
    while(i <av)
    {
        elem2 = (t_list*)malloc(sizeof(t_list));
        elem2->data = ac[i];
        elem1->next = elem2;
        elem1 = elem2;
        i++;
    }
    elem1->next = NULL;
    elem1=first;
    while(elem1 != NULL)
    {
        printf("antes-->%p ---- %s\n",elem1, (char*)elem1->data);
        elem1 = elem1->next;
    }
    ft_list_remove_if(begin_list,data_ref, compare);
    elem1=first;
    while(elem1)
    {
        printf("despues-->%s\n",(char*)elem1->data);
        elem1 = elem1->next;
    }
    elem1 = first;
    while(elem1->next)
    {
        elem2 = elem1->next;
        free(elem1);
        elem1 = elem2;
    }
}