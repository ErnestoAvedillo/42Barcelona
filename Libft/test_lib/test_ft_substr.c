#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_substr ()
{
	char str[50];
	char *ptr;
	/*ft_substr
	*/
	printf("%sTest de ft_substr%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "fulanitodetalcualsea",20);
	ptr = ft_substr(str, 4, 8);
	printf("ft_substr extrae del str -%s- en la direccion -%p- y vemos en ella %s \n", str, ptr, ptr);
	printf("\n");
	free(ptr);
	printf("%sTest2%s\n",KYEL, KNRM);
	ptr = ft_substr(str, 0, -1);
	printf("ft_substr extrae del str -%s- en la direccion -%p- y vemos en ella %s \n", str, ptr, ptr);
	printf("\n");
	free(ptr);

}