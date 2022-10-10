#include "../entrega/libft.h"
#include "test_lib.h"

void	ft_modify_list_with_d(void *elem)
{
	int		len;
	char	*content;

	len = 0;
	content = (char *)elem;
	while (content[len])
	{
		content[len++] = 'd';
	}

}


void	print_current (t_list *ptr)
{
	printf("La estructura tiene el contenido > %s < en el puntero %p .\n", (char *)ptr->content, ptr);
	printf("Esta estructura está linkada al puntero de la siguiente que es el %p\n", ptr->next );
	return ;
}

void	print_all(t_list *ptr)
{
	while (ptr->next )
	{
		print_current(ptr);
		ptr = ptr->next;
	}
	print_current(ptr);
}

void borra_content(void *s)
{
	char *ptr;

	ptr = s;
	ptr = NULL;
	ptr++;
	return ;
}

void test_ft_bonus()
{
	/*ft_lstnew
	 */
 	t_list 	*inicio;
 	t_list	*ptr1;
 	t_list	*ptr2;
 	t_list	*ptr3;
 	t_list	*ptr4;
 	t_list	*aux;
 	int		milong = 0;

	printf("%stest test_ft_lstadd_front%s\n",KGRN, KNRM);
	printf("%sTest1 creo un t_list%s\n",KYEL, KNRM);
// 	inicio = (t_list *)malloc (sizeof(t_list));
 	ptr1 = ft_lstnew("42");
 	print_current(ptr1);

	printf("%sTest2 creo un segundo t_list%s\n",KYEL, KNRM);
 	ptr2 = ft_lstnew("es");
 	print_current(ptr2);

	printf("\n");
	inicio= NULL;
	printf("Creado el puntero doble: %p\n",inicio );

	printf("%sTest3 añado al frente%s\n",KYEL, KNRM);
 	ft_lstadd_front (&inicio, ptr2); 
 	ft_lstadd_front (&inicio, ptr1); 

	printf("%scomprobación %s\n",KBLU, KNRM);
 	print_all(inicio);
	printf("Reviso el puntero doble: %p\n",inicio );
	printf("Reviso el puntero que señala al primer elemento: %p\n",inicio->next );

	printf("%sTest4 busco el último%s\n",KYEL, KNRM);
 	aux = ft_lstlast(inicio);
	print_current(aux );

	printf("%sTest5 añado en la parte final%s\n",KYEL, KNRM);
 	ptr3 = ft_lstnew("Barcelona");
 	printf("El elemento añadido es:\n");
 	print_current(ptr3);
 	ft_lstadd_back (&inicio, ptr3);
	printf("%scomprobación %s\n",KBLU, KNRM);
 	print_all(inicio);

 	printf("%sTest6 añado en la parte final%s\n",KYEL, KNRM);
 	ptr4 = ft_lstnew("Born2code");
 	printf("El elemento añadido es:\n");
 	print_current(ptr4);
 	ft_lstadd_back (&inicio, ptr4);
	printf("%scomprobación %s\n",KBLU, KNRM);
 	print_all(inicio);


	printf("%sTest6 cuento la longitud%s\n",KYEL, KNRM);
 	milong = ft_lstsize(inicio);
 	printf("El numero de elementos es: %d \n", milong);

	printf("%sTest7 elimino La lista lstclear usando lstdelone %s\n",KYEL, KNRM);
	printf("Reviso el puntero doble antes de eliminar: %p\n",inicio );
	printf("Puntero del puntero que señala al primer elemento: %p\n",inicio );
 	milong = ft_lstsize(inicio);
 	printf("El numero de elementos es: %d \n", milong);
 	print_all(inicio);
 	ft_lstclear(&inicio, borra_content);
	printf("%scomprobación %s\n",KBLU, KNRM);
 	printf("inicio queda asi %p\n", inicio );
 	milong = ft_lstsize(inicio);
	printf("%sTest8 test lstiter%s\n",KYEL, KNRM);
 	inicio = NULL;
 	ptr1 = ft_lstnew("Esto");
 	ptr2 = ft_lstnew("es");
 	ptr3 = ft_lstnew("Barcelna");
 	ptr4 = ft_lstnew("42");
 	ft_lstadd_front(&inicio,ptr4);
 	ft_lstadd_front(&inicio,ptr3);
 	ft_lstadd_front(&inicio,ptr2);
 	ft_lstadd_front(&inicio,ptr1);
 	print_all(inicio);
 	ft_lstiter(ptr1, ft_modify_list_with_d);
	printf("%scomprobación %s\n",KBLU, KNRM);
 	print_all(inicio);

	printf("%sTest8 test soares ltclear %s\n",KYEL, KNRM);
	ft_lstclear(NULL, free);


 	return ;
}