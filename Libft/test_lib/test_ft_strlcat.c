#include "../Libft/libft.h"
#include "test_lib.h"

void test_ft_strlcat()
{
	/*ft_strlcat
	 */
	char str[50] = "La prueba de ft_strlcat";
	char str2[50] = "esto es un atraco";

	size_t retval;
	printf("test ft_strlcat\n");
	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de strlcat dst vale : %s\n", str);
	printf("antes de strlcat src vale : %s\n", str2);
//	retval = strlcat(str,str2,16);
//	printf("despues de strlcat dst  vale: %s -- return value %u\n", str, retval);
//	printf("despues de strlcat src vale : %s\n", str2);

	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de ft_strlcat dst  vale: %s\n", str);
	printf("antes de ft_strlcat src  vale: %s\n", str2);
	retval = ft_strlcat(str,str2,16);
	printf("despues de ft_strlcat dst  vale: %s -- return value %u\n", str, retval);
	printf("despues de ft_strlcat src  vale: %s\n\n", str2);
	
	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de strlcat dst vale : %s\n", str);
	printf("antes de strlcat src vale : %s\n", str2);
//	retval = strlcat(str,str2,35);
//	printf("despues de strlcat dst  vale: %s -- return value %u\n", str, retval);
//	printf("despues de strlcat src vale : %s\n", str2);

	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de ft_strlcat dst  vale: %s\n", str);
	printf("antes de ft_strlcat src  vale: %s\n", str2);
	retval = ft_strlcat(str,str2,35);
	printf("despues de ft_strlcat dst  vale: %s -- return value %u\n", str, retval);
	printf("despues de ft_strlcat src  vale: %s\n\n", str2);

}
