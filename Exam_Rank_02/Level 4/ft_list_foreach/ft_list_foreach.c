#include"ft_list_foreach.h"
/*
void cap(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
}
*/
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *element;
    element = begin_list;
    while (element)
    {
        (*f)(element->data);
        element = element->next;
    }
}
/*
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
    ft_list_foreach(first,(void*)cap);
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
*/