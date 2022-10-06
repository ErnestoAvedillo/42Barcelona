#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_lstnew (char *valor)
{
	/*ft_lstnew
	 */
 	t_list 	*ptr;

	printf("%stest test_ft_lstnew%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ptr = ft_lstnew (valor); 
	printf("la estructura tiene el contenido %s en el puntero %p . \
		Esta estructura está linkada al puntero de la siguiente que es el %p\n", (char *)ptr->content, ptr, ptr->next );
}