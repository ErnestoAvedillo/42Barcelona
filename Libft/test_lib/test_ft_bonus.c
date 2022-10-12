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
		printf("entro el f iter content %p--%s-- len %d\n", content, content, len);
		printf("entro el f iter content %p--%c-- len %d\n", &content[len], content[len], len);
		content[len] = 100;
		printf("entro el f iter content %p--%s-- len %d\n", content, content, len);
		len++;
	}

}

void	*ft_modify_list_with_a(void *elem)
{
	int		len;
	char	*content;

	len = 0;
	content = (char *)elem;
	while (content[len])
	{
		printf("entro f map content %p--%s-- len %d\n", content, content, len++);
		content[len++] = 'a';
	}
	return (content);
}

void free_str(void *str)
{
	free(str);
}

void	print_current (t_list *ptr)
{
	printf("puntero %p -->Contenido > %s < puntero %p -- \
		puntero Next %p.\n",ptr, (char *)ptr->content, \
		(char *)ptr->content, ptr->next);
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
 	printf("Comprobacion de contenido de la lista\n");
 	print_all(inicio);
 	ft_lstiter(inicio, ft_modify_list_with_d);
	printf("%scomprobación del ejerccicio de iter.%s\n",KBLU, KNRM);
 	print_all(inicio);
	t_list *copia;
	copia = ft_lstmap(inicio, ft_modify_list_with_a, free_str);
 	printf("Comprobacion de contenido de la copia\n");
 	print_all(copia);
	ft_lstclear(&inicio, free_str);
	ft_lstclear(&copia, free_str);

 	return ;
}