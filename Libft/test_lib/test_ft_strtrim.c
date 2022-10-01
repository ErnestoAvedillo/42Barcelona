#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strtrim ()
{
	char str[50];
	char str2[50];
	char *ptr;
	/*ft_strtrim
	*/

	printf("test ft_strtrim\n");
	ft_strlcpy(str, "fulanitodetalcualsea",20);
	ft_strlcpy(str2, "as",20);
	ptr = ft_strtrim(str, str2);
	printf("ft_strtrim recorta el str -%s- entre los 2 primeros carac. en -%s- y queda: -%s- en el puntero %p\n", str, str2, ptr, ptr);
    char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	ft_strlcpy(str, "lorem \n ipsum \t dolor \n sit \t amet",40);
    ptr = ft_strtrim(s1, " ");
	printf("ft_strtrim recorta el str -%s- entre los 2 primeros carac. en -%s- y queda: -%s- en el puntero %p\n", str, "", ptr, ptr);
	printf("\n");
	free(ptr);
}