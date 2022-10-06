#include "../entrega/libft.h"
#include "test_lib.h"


void test_ft_strtrim ()
{
	char str[50];
	char str2[50];
	char *ptr;
	/*ft_strtrim
	*/

	printf("%sTest ft_strtrim%s\n",KGRN, KNRM);

	printf("%stest 1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "fulanito de tal cualsea",26);
	ft_strlcpy(str2, "as",20);
	ptr = ft_strtrim(str, str2);
	printf("ft_strtrim recorta el str \n%s\n entre los 2 primeros caracenconteados en \n%s\n y queda: -%s- en el puntero %p\n", str, str2, ptr, ptr);
	free(ptr);
	printf("\n");

	printf("%stest 2%s\n",KYEL, KNRM);
	ft_strlcpy(str, "lorem ipsum dolor sit amet", 26);
	ft_strlcpy(str2, "l ",2);
	ptr = ft_strtrim(str, str2);
	printf("ft_strtrim recorta el str \n%s\n entre los 2 primeros caracteres en \
		 \n%s\n y queda: \n%s\n.\
		 Puntero original %p puntero devuelto %p\n", str, str2, ptr, str, ptr);
	free(ptr);

	printf("%stest 3%s\n",KYEL, KNRM);
	ft_strlcpy(str, "lorem \n ipsum \t dolor \n sit \t amet",40);
	ptr = ft_strtrim(str, " ");
	printf("ft_strtrim recorta el str \n%s\n entre los 2 primeros carac. en \n%s\n y queda: -%s- en el puntero %p\n", str, "", ptr, ptr);
//	ptr = strtrim(s1, " ");
//	printf("   trtrim recorta el str -%s- entre los 2 primeros carac. en -%s- y queda: -%s- en el puntero %p\n", str, "", ptr, ptr);
	free(ptr);

	printf("%stest 4%s\n",KYEL, KNRM);
	ft_strlcpy(str, "lorem ipsum dolor sit amet", 26);
	ptr = ft_strtrim(str, "tel");
	printf("ft_strtrim recorta el str \n%s\n entre los 2 primeros carac. en \n%s\n y queda: -%s- en el puntero %p\n", str, "", ptr, ptr);
//	ptr = strtrim(s1, " ");
//	printf("   trtrim recorta el str -%s- entre los 2 primeros carac. en -%s- y queda: -%s- en el puntero %p\n", str, "", ptr, ptr);
	free(ptr);

	printf("%stest 5%s\n",KYEL, KNRM);
	ft_strlcpy(str, "rrrrrrrrrrrrrrrrrrr", 20);
	ptr = ft_strtrim(str, "r");
	printf("ft_strtrim recorta el str \n%s\n entre los 2 primeros carac. en \n%s\n y queda: -%s- en el puntero %p\n", str, "r", ptr, ptr);
//	ptr = strtrim(s1, " ");
//	printf("   trtrim recorta el str -%s- entre los 2 primeros carac. en -%s- y queda: -%s- en el puntero %p\n", str, "", ptr, ptr);
	free(ptr);
	printf("\n");
}