#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strdup ()
{
	char str[50];
	char *ptr;
	char *ptr1;
	/*ft_strdup
	 */
	printf("%sTest de ft_strdup%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "fulanito de tal cual",20);
	ptr = ft_strdup(str);
	ptr1 = strdup(str);
	printf("ft_strdup diplica el str -%s- en la direccion -%p- y vemos en ella %s \n", str, ptr, ptr);
	printf("   strdup diplica el str -%s- en la direccion -%p- y vemos en ella %s \n", str, ptr1, ptr1);
	printf("\n");
	free(ptr);
	free(ptr1);
}