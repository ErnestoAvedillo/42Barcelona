#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include "./Libft/libft.h"

char	ft_test_mapi(unsigned int i, char c)
{
	i = 0;
	return (c - 32);
}

void	ft_test_iteri(unsigned int i, char *c)
{
	i = 0;
	*c += 32;
	return;
}

//int main (int av, char **ac)
int main ()
{
	/* ft_isalpha
	*/
	int var1 = 'r';
	int var2 = 'R';
	int var3 = '2';
	printf("test ft_isalpha\n");
	printf("ft_isalpha para %c retorna %d\n", var1, ft_isalpha(var1));
	printf("isalpha para %c retorna %d\n", var1, isalpha(var1));
	printf("ft_isalpha para %c retorna %d\n", var2, ft_isalpha(var2));
	printf("isalpha para %c retorna %d\n", var2, isalpha(var2));
	printf("ft_isalpha para %c retorna %d\n", var3, ft_isalpha(var3));
	printf("isalpha para %c retorna %d\n", var3, isalpha(var3));
	printf("\n");
	/*ft_isdigit
	 */
	printf("test ft_isdigit\n");
	printf("ft_isdigit para %c retorna %d\n", var1, ft_isdigit(var1));
	printf("isdigit para %c retorna %d\n", var1, isdigit(var1));
	printf("ft_isdigit para %c retorna %d\n", var2, ft_isdigit(var2));
	printf("isdigit para %c retorna %d\n", var2, isdigit(var2));
	printf("ft_isdigit para %c retorna %d\n", var3, ft_isdigit(var3));
	printf("isdigit para %c retorna %d\n", var3, isdigit(var3));
	printf("\n");

	/* ft_isalnum
	*/
	int var4 = '\n';
	printf("test ft_isalnum\n");
	printf("ft_isalnum para %c retorna %d\n", var1, ft_isalnum(var1));
	printf("isalnum para %c retorna %d\n", var1, isalnum(var1));
	printf("ft_isalnum para %c retorna %d\n", var2, ft_isalnum(var2));
	printf("isalnum para %c retorna %d\n", var2, isalnum(var2));
	printf("ft_isalnum para %c retorna %d\n", var3, ft_isalnum(var3));
	printf("isalnum para %c retorna %d\n", var3, isalnum(var3));
	printf("ft_isalnum para %c retorna %d\n", var4, ft_isalnum(var4));
	printf("isalnum para %c retorna %d\n", var4, isalnum(var4));
	printf("\n");

	/* ft_isacii
	*/
	var3 = 'r';
	var4 = 178;
	printf("test ft_isacii\n");
	printf("ft_isacii para %c retorna %d\n", var3, ft_isascii(var3));
	printf("isacii para %c retorna %d\n", var3, isascii(var3));
	printf("ft_isacii para %d retorna %d\n", var4, ft_isascii(var4));
	printf("isacii para %d retorna %d\n", var4, isascii(var4));
	printf("\n");


	/* ft_isprint
	*/
	var3 = 'r';
	var4 = 177;
	printf("test ft_sprint\n");
	printf("ft_sprint para %c retorna %d\n", var3, ft_isprint(var3));
	printf("sprint para %c retorna %d\n", var3, isprint(var3));
	printf("ft_sprint para %d retorna %d\n", var4, ft_isprint(var4));
	printf("sprint para %d retorna %d\n", var4, isprint(var4));
	printf("\n");
	
	/*ft_strlen
	 */
	char str[50] = "qwerty";
	printf("test ft_strlen\n");
	printf("La longitud de la cadena deberia ser %lu y me sale %zu\n\n", strlen(str), ft_strlen(str));

	/*ft_memset
	 */
	printf("test ft_memset\n");
	printf("Antes de memset es : %s\n", str);
	memset(str, '*', 8 * sizeof(char));
	printf("despues de memset es : %s\n", str);
	memset(str, '-', 8 * sizeof(char));
	printf("despues de ft_memset es : %s\n\n", str);

	/*ft_bzero
	 */
	ft_strlcpy(str, "esto es un atraco",17);
	printf("test ft_bzero\n");
	printf ("Antes de bzero el texto es: %s.\n " , str);
	bzero(str, 9);
	printf ("Despues de bzero el texto es %s.\n " , str);
	ft_strlcpy(str, "esto es un atraco",17);
	printf("Antes de ft_bzero el texto es: %s.\n", str);
	ft_bzero(str,5 );
	printf ("Despues de ft_bzero el texto es: %s.\n\n" , str);

	/*ft_memcpy
	 */
	printf("test ft_memcpy\n");
	char str2[50]= "La prueba de memcpy";
	ft_strlcpy(str, "esto es un atraco",17);
	printf("antes de memcpy dst vale : %s\n", str);
	printf("antes de memcpy src vale : %s\n", str2);
	memcpy(str,str2,20);
	printf("despues de memcpy dst vale : %s\n", str);
	printf("despues de memcpy src vale : %s\n", str2);
	ft_strlcpy(str, "esto es un atraco",17);
	ft_strlcpy(str2, "La prueba de memcpy",24);
	
	printf("antes de ft_memcpy dst  vale: %s\n", str);
	printf("antes de ft_memcpy src  vale: %s\n", str2);
	ft_memcpy(str,str2,20);
	printf("despues de ft_memcpy dst  vale: %s\n", str);
	printf("despues de ft_memcpy src  vale: %s\n\n", str2);
	
	/*ft_memmove
	 */
	printf("test ft_memmove\n");
	ft_strlcpy(str2, "La prueba de ft_memmove",25);
	ft_strlcpy(str, "esto es un atraco",17);
	printf("antes de memmove dst vale : %s\n", str);
	printf("antes de memmove src vale : %s\n", str2);
	memmove(str,str2,20);
	printf("despues de memmove dst vale : %s\n", str);
	printf("despues de memmove src vale : %s\n", str2);

	ft_strlcpy(str2, "La prueba de ft_memmove",25);
	ft_strlcpy(str, "esto es un atraco",17);
	
	printf("antes de ft_memmove dst  vale: %s\n", str);
	printf("antes de ft_memmove src  vale: %s\n", str2);
	ft_memmove(str,str2,20);
	printf("despues de ft_memmove dst  vale: %s\n", str);
	printf("despues de ft_memmove src  vale: %s\n\n", str2);

	/*ft_strlcpy
	 */
	printf("test ft_strlcpy\n");
	printf("La cadena era %s\n",str);
	strlcpy (str, "pepito grillo", 10);	
	printf("La cadena con strlcpy es %s\n",str);
	ft_strlcpy(str, "pepito grillo", 10);
	printf("La cadena con mi ft_strlcpy es %s\n\n",str);

	/*ft_strlcat
	 */
	size_t retval;
	printf("test ft_strlcat\n");
	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de strlcat dst vale : %s\n", str);
	printf("antes de strlcat src vale : %s\n", str2);
	retval = strlcat(str,str2,16);
	printf("despues de strlcat dst  vale: %s -- return value %lu\n", str, retval);
	printf("despues de strlcat src vale : %s\n", str2);

	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de ft_strlcat dst  vale: %s\n", str);
	printf("antes de ft_strlcat src  vale: %s\n", str2);
	retval = ft_strlcat(str,str2,16);
	printf("despues de ft_strlcat dst  vale: %s -- return value %lu\n", str, retval);
	printf("despues de ft_strlcat src  vale: %s\n\n", str2);
	
	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de strlcat dst vale : %s\n", str);
	printf("antes de strlcat src vale : %s\n", str2);
	retval = strlcat(str,str2,35);
	printf("despues de strlcat dst  vale: %s -- return value %lu\n", str, retval);
	printf("despues de strlcat src vale : %s\n", str2);

	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de ft_strlcat dst  vale: %s\n", str);
	printf("antes de ft_strlcat src  vale: %s\n", str2);
	retval = ft_strlcat(str,str2,35);
	printf("despues de ft_strlcat dst  vale: %s -- return value %lu\n", str, retval);
	printf("despues de ft_strlcat src  vale: %s\n\n", str2);

	/*ft_toupper
	 */
	var1 = 'r';
	var2 = 'R';
	var3 = '2';
	printf("test ft_toupper\n");
	printf("var1 %d var2 %d var3 %d \n", var1, var2, var3);
	printf("ft_toupper para %c retorna %d\n", var1, ft_toupper(var1));
	printf("toupper para %c retorna %d\n", var1, toupper(var1));
	printf("ft_toupper para %c retorna %d\n", var2, ft_toupper(var2));
	printf("toupper para %c retorna %d\n", var2, toupper(var2));
	printf("ft_toupper para %c retorna %d\n", var3, ft_toupper(var3));
	printf("toupper para %c retorna %d\n", var3, toupper(var3));
	printf("\n");

	/*ft_tolower
	 */
	var1 = 'r';
	var2 = 'R';
	var3 = '2';
	printf("test ft_tolower\n");
	printf("var1 %d var2 %d var3 %d \n", var1, var2, var3);
	printf("ft_tolower para %c retorna %d\n", var1, ft_tolower(var1));
	printf("tolower para %c retorna %d\n", var1, tolower(var1));
	printf("ft_tolower para %c retorna %d\n", var2, ft_tolower(var2));
	printf("tolower para %c retorna %d\n", var2, tolower(var2));
	printf("ft_tolower para %c retorna %d\n", var3, ft_tolower(var3));
	printf("tolower para %c retorna %d\n", var3, tolower(var3));
	printf("\n");

	/*ft_strchr
	 */
	var1 = 'r';
	var2 = 'R';
	var3 = '2';
	printf("test ft_strchr\n");
	ft_strlcpy(str, "esto es un atraco",17);
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var1, ft_strchr(str, var1));
	printf("strchr en -%s- al buscar -%c- retorna %p\n", str, var1, strchr(str, var1));
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var2, ft_strchr(str, var2));
	printf("strchr en -%s- al buscar -%c- retorna %p\n", str, var2, strchr(str, var2));
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var3, ft_strchr(str, var3));
	printf("strchr en -%s- al buscar -%c- retorna %p\n", str, var3, strchr(str, var3));
	printf("\n");

	/*ft_strrchr
	 */
	var1 = 'a';
	var2 = 'R';
	var3 = '2';
	printf("test ft_strrchr\n");
	ft_strlcpy(str, "esto es un atraco",17);
	printf("ft_strrchr en -%s- al buscar -%c- retorna %p\n", str, var1, ft_strrchr(str, var1));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var1, strrchr(str, var1));
	printf("ft_strrchr en -%s- al buscar -%c- retorna %p\n", str, var2, ft_strrchr(str, var2));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var2, strrchr(str, var2));
	printf("ft_strrchr en -%s- al buscar -%c- retorna %p\n", str, var3, ft_strrchr(str, var3));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var3, strrchr(str, var3));
	printf("\n");

	/*ft_strncmp
	 */
	var1 = 'r';
	var2 = 'R';
	var3 = '2';
	ft_strlcpy(str, "test esto@thyuun atraco",22);
	ft_strlcpy(str2, "test esto es un atrco",22);
	printf("test ft_strncmp\n");
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 9));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 9));
	ft_strlcpy(str2, "test estothyuun atraco",22);
	ft_strlcpy(str, "test esto es un atraco",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str2, "test esto ES n atraco",22);
	ft_strlcpy(str, "test esto es un atraco",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str2, "test esto ES n atraco",22);
	ft_strlcpy(str, "test esto",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str, "test esto ES n atraco",22);
	ft_strlcpy(str2, "test esto",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	printf("\n");

	/*ft_memchr
	 */
	var1 = 'r';
	ft_strlcpy(str, "test esto@thyuun atraco",22);
	ft_strlcpy(str2, "test esto es un atrco",22);

	printf("test ft_memchr\n");
	printf("ft_memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2, ft_memchr(str2, var1, 20));
	printf("   memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2,  memchr(str2, var1, 20));
	var1 = 'w';
	printf("ft_memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2, ft_memchr(str2, var1, 20));
	printf("   memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2,  memchr(str2, var1, 20));
	var1 = 'w';
	printf("ft_memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2, ft_memchr(str2, var1, 50));
	printf("   memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2,  memchr(str2, var1, 50));

	/*ft_memcmp
	 */
	ft_strlcpy(str, "test esto @thyuun atraco",20);
	ft_strlcpy(str2, "test esto es un atrco",20);

	printf("test ft_memcmp\n");
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, ft_memcmp(str, str2, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, memcmp(str, str2, 20));
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, ft_memcmp(str2, str, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, memcmp(str2, str, 20));
	ft_strlcpy(str, "test esto@thyuun atraco",22);
	ft_strlcpy(str2, "test esto es un atrco",22);
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, ft_memcmp(str, str2, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, memcmp(str, str2, 20));
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, ft_memcmp(str2, str, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, memcmp(str2, str, 20));

	/*ft_strnstr
	 */
	ft_strlcpy(str, "es un",20);
	ft_strlcpy(str2, "test esto es un atrco",20);

	printf("test ft_strstr\n");
	printf("ft_strnstr busca el str -%s- dentro de -%s- retorna %p\n", str, str2, ft_strnstr(str2, str, 20));
	printf("   strnstr busca el str -%s- dentro de -%s- retorna %p\n", str, str2, strnstr(str2, str, 20));

	/*ft_atoi
	 */
 
	char	valor1[10];
	char	valor2[10];
	char	valor3[10];
	char	valor4[10];
	printf("test ft_atoi\n");
	ft_strlcpy(valor1, "fdr1234666",10);
	ft_strlcpy(valor2, "-4345A55",10);
//	printf("ft_atoi convierte el str -%s- en un entero y retorna \n", valor1 );
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor2, ft_atoi(valor2));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor2, atoi(valor2));
	ft_strlcpy(valor3, " 1234 666",10);
	ft_strlcpy(valor4, "- -4333555",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor3, ft_atoi(valor3));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor3, atoi(valor3));
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor4, ft_atoi(valor4));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor4, atoi(valor4));
	printf("\n");

	/*ft_strdup
	 */
	char *ptr;
	char *ptr1;
	printf("test ft_strdup\n");
	ft_strlcpy(str, "fulanito de tal cual",20);
	ptr = ft_strdup(str);
	ptr1 = strdup(str);
	printf("ft_strdup diplica el str -%s- en la direccion -%p- y vemos en ella %s \n", str, ptr, ptr);
	printf("   strdup diplica el str -%s- en la direccion -%p- y vemos en ella %s \n", str, ptr1, ptr1);
	printf("\n");
	free(ptr);
	free(ptr1);

	/*ft_substr
	*/
	printf("test ft_substr\n");
	ft_strlcpy(str, "fulanitodetalcualsea",20);
	ptr = ft_substr(str, 4, 8);
	printf("ft_substr extrae del str -%s- en la direccion -%p- y vemos en ella %s \n", str, ptr, ptr);
	printf("\n");
	free(ptr);

	/*ft_strjoin
	*/

	printf("test ft_strjoin\n");
	ft_strlcpy(str, "fulanitodetalcualsea",20);
	ft_strlcpy(str2, "comoseasecanso",20);
	ptr = ft_strjoin(str, str2);
	printf("ft_strjoin une dos str -%s-%s- en la direccion -%p- y vemos en ella %s \n", str, str2, ptr, ptr);
	printf("\n");
	free(ptr);

	/*ft_strtrim
	*/

	printf("test ft_strtrim\n");
	ft_strlcpy(str, "fulanitodetalcualsea",20);
	ft_strlcpy(str2, "as",20);
	ptr = ft_strtrim(str, str2);
	printf("ft_strtrim recorta el str -%s- entre los 2 primeros carac. en -%s- y queda: -%s- en el puntero %p\n", str, str2, ptr, ptr);
	printf("\n");
	free(ptr);

	/*ft_split
	*/
	int	i = 0;
	char **str3;
	char div = 'c';
	printf("test ft_split\n");
	ft_strlcpy(str, "wwwcrrrctttyycoooppy",20);

	str3 = ft_split(str, 'c');
	while(str3[i])
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str3[i], str3[i], i);
		i++;
	}
	printf("\n");
	free(str3);


	/*ft_itoa
	*/

	printf("test ft_itoa\n");
	var1 = 14567;
	ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str -%s- en el puntero %p\n", var1, ptr, ptr);
	free(ptr);
	var1 = -4567;
	ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str -%s- en el puntero %p\n", var1, ptr, ptr);
	printf("\n");
	free(ptr);

	/*ft_strmapi
	 */
	printf("Test de ft_strmapi :\n");
	printf("ABC : %s\n", ft_strmapi("abc", ft_test_mapi));
	printf("ABC : %s\n", ft_strmapi("idf", ft_test_mapi));
	printf("\n");


	/*ft_striteri
	 */
	printf("Test de ft_strmapi :\n");
	ft_strlcpy(str, "ABC",4);
	printf("La funcion ft_striteri modifica cada caracter del str: %s \n",str );
	ft_striteri(str,ft_test_iteri);
	printf("quedando: %s \n",str );
	printf("\n");

	/*ft_putchar_fd
	*/
	printf("Test de ft_putchar_fd :\n");
	ft_putchar_fd(var1,1);
	printf("\n");

	/*ft_putstr_fd
	 */
	printf("Test de ft_putstr_fd :\n");
	ft_putstr_fd(str,1);
	printf("\n");

	/*ft_putendl_fd
	 */
	printf("Test de ft_putendl_fd :\n");
	ft_putendl_fd(str,1);
	printf("\n");

	/*ft_putnbr_fd
	 */
	printf("Test de ft_putnbr_fd :\n");
	ft_putnbr_fd(34,1);
	printf("\n");
}
