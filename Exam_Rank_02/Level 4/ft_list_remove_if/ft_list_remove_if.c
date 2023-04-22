#include"ft_list_remove_if.h"
#include <stdio.h>

/*int compare(void *data_ref,void *data)
{
    if (data-)
}
*/
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if(begin_list == NULL || *begin_list == NULL) 
        return;

    t_list *elem1;
    t_list *elem2;
    elem1 = *begin_list;

    while (cmp(data_ref, elem1->data) == 0)
    {
        *begin_list = elem1->next;
        free(elem1);
        elem1 = *begin_list;
   }
    elem1 = *begin_list;
    while(elem2)
    {
        elem2 = elem1->next;
        if(cmp(data_ref,elem2->data) == 0)
        {
            elem1->next = elem2->next;
            free(elem2);
        }
        else 
        {
            elem1 = elem2;
            elem2 = elem1->next;
        }
    }
}
//---------------------------------------------------------------------
 #include <string.h>
 void	print_list(t_list **begin_list)
 {
 	t_list *cur = *begin_list;
 	while (cur != 0)
 	{
 		printf("%s\n", (char*)cur->data);
 		cur = cur->next;
 	}
 }
/*
 int		main(void)
 {
 	char straa[] = "String aa";
 	t_list *aa = malloc(sizeof(t_list));
 	aa->next = 0;
 	aa->data = straa;
 	char strbb[] = "String bb";
 	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
 	bb->data = strbb;

 	char strcc[] = "String cc";
 	t_list *cc = malloc(sizeof(t_list));
 	cc->next = 0;
 	cc->data = strcc;

 	char strdd[] = "String dd";
 	t_list *dd = malloc(sizeof(t_list));
 	dd->next = 0;
 	dd->data = strdd;

 	aa->next = bb;
 	bb->next = cc;
 	cc->next = dd;

 	t_list **begin_list = &aa;

	print_list(begin_list);
 	printf("----------\n");
 	ft_list_remove_if(begin_list, straa, strcmp);
 	print_list(begin_list);
 }
*/

#include<stdio.h>
int main (int av, char **ac)
{
    int i=2;
    t_list **first;
    t_list *elem1;
    t_list *elem2;
    if (av < 3)
        return(0);
    elem1 = (t_list*)malloc(sizeof(t_list));
    elem1->data = ac[1];
    first = &elem1;
    while(i < av -2)
    {
        elem2 = (t_list*)malloc(sizeof(t_list));
        elem2->data = ac[i];
        elem1->next = elem2;
        elem1 = elem2;
        printf("antes-->%p ---- %p\n", elem1, elem1->next);
        i++;
    }
    elem1->next = NULL;
    elem1=*first;
    while(elem1 != NULL)
    {
        printf("antes-->%p ---- %s\n",elem1, (char*)elem1->data);
        elem1 = elem1->next;
    }
    ft_list_remove_if(first,(void *)ac[av -1],strcmp);
    elem1=*first;
    while(elem1)
    {
        printf("despues-->%s\n",(char*)elem1->data);
        elem1 = elem1->next;
    }
    elem1 = *first;
    while(elem1->next)
    {
        elem2 = elem1->next;
        free(elem1);
        elem1 = elem2;
    }
}
