#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strjoin ()
{
	char str[50];
	char str2[50];
	char *ptr;
	/*ft_strjoin
	*/

	printf("test ft_strjoin\n");
	ft_strlcpy(str, "fulanitodetalcualsea",20);
	ft_strlcpy(str2, "comoseasecanso",20);
	ptr = ft_strjoin(str, str2);
	printf("ft_strjoin une dos str -%s-%s- en la direccion -%p- y vemos en ella %s \n", str, str2, ptr, ptr);
	str2[0] = '\0';
	ptr = ft_strjoin(str, str2);
	printf("ft_strjoin une dos str -%s-%s- en la direccion -%p- y vemos en ella %s \n", str, str2, ptr, ptr);
	printf("\n");
	free(ptr);

}