#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "./Libft/libft.h"

//int main (int av, char **ac)
int main ()
{
	/* ft_isalpha
	*/
	int var1 = 'r';
	int var2 = '2';
	if (ft_isalpha(var1))
		printf("la variable %c es alfabetica\n", var1);
	else
		printf("la variable %c no es alfabetica\n", var1);

	if (ft_isalpha(var2))
		printf("la variable %c es alfabetica\n", var2);
	else
		printf("la variable %c no es alfabetica\n", var2);
	/*ft_isdigit
	 */
	if (ft_isdigit(var1))
		printf("la variable %c es un digito\n", var1);
	else
		printf("la variable %c no es un digito\n", var1);

	if (ft_isdigit(var2))
		printf("la variable %c es un digito\n", var2);
	else
		printf("la variable %c no es un digito\n", var2);

	/* ft_isalnum
	*/
	int var3 = 'r';
	int var4 = '\n';
	if (ft_isalnum(var3))
		printf("la variable %c es alfanumerica\n", var3);
	else
		printf("la variable %c no es alfanumerica\n", var3);

	if (ft_isalnum(var4))
		printf("la variable %c es alfanumerica\n", var4);
	else
		printf("la variable %c no es alfanumerica\n", var4);

	/* ft_isacii
	*/
	var3 = 'r';
	var4 = 178;
	if (ft_isascii(var3))
		printf("la variable %c es ascii\n", var3);
	else
		printf("la variable %c no es ascii\n", var3);

	if (ft_isascii(var4))
		printf("la variable %c es ascii\n", var4);
	else
		printf("la variable %c no es ascii\n", var4);


	/* ft_sprint
	*/
	var3 = 'r';
	var4 = 177;
	if (ft_isprint(var3))
		printf("la variable %c es print\n", var3);
	else
		printf("la variable %c no es print\n", var3);

	if (ft_isprint(var4))
		printf("la variable %c es print\n", var4);
	else
		printf("la variable %c no es print\n", var4);
	
	/*ft_strlen
	 */
	char str[50] = "qwerty";
	printf("La longitud de la cadena deberia ser %lu y me sale %lu\n", strlen(str), ft_strlen(str));


	/*ft_strlcpy
	 */
	printf("La cadena era %s\n",str);
	strlcpy (str, "pepito grillo", 10);	
	printf("La cadena es %s\n",str);
	ft_strlcpy(str, "pepitogrillo", 10);
	printf("La cadena con mi ft_strlcpy es %s\n",str);

	/*ft_memset
	 */
	printf("Antes de memset es : %s\n", str);
	memset(str, '*', 8 * sizeof(char));
	printf("despues de memset es : %s\n", str);
	memset(str, '-', 8 * sizeof(char));
	printf("despues de ft_memset es : %s\n", str);

	/*ftbzero
	 */
	bzero(str, 9);
	printf ("Despues de bzero str es %s.\n " , str);
	ft_strlcpy(str, "esto es un atraco",10);
	printf("Antes de ft_bzero str es %s.\n", str);
	ft_bzero(str,5 );
	printf ("Despues de ft_bzero str es %s.\n " , str);

	/*ft_memcpy
	 */
	char str2[50]= "La prueba de memmove";
	ft_strlcpy(str, "esto es un atraco",10);
	printf("la prueba de memcpy str vale antes: %s\n", str);
	printf("la prueba de memcpy str2 vale antes: %s\n", str2);
	memmove(str,str2,20);
	printf("la prueba de memcpy str vale despues: %s\n", str);
	printf("la prueba de memcpy str2 vale despues: %s\n", str2);
	ft_strlcpy(str, "esto es un atraco",10);
	ft_strlcpy(str2, "La prueba de ft_memmove\n",24);
	
	printf("la prueba de ft_memcpy str antes vale: %s\n", str);
	printf("la prueba de ft_memcpy str2 antes vale: %s\n", str2);
	ft_memmove(str,str2,20);
	printf("la prueba de ft_memcpy str despues vale: %s\n", str);
	printf("la prueba de ft_memcpy str2 despues vale: %s\n", str2);
	
	/*ft_memmove
	 */
	ft_strlcpy(str2, "La prueba de ft_memcpy",25);
	ft_strlcpy(str, "esto es un atraco",10);
	printf("la prueba de memmove str vale antes: %s\n", str);
	printf("la prueba de memmove str2 vale antes: %s\n", str2);
	memmove(str,str2,20);
	printf("la prueba de memmove str vale despues: %s\n", str);
	printf("la prueba de memmove str2 vale despues: %s\n", str2);
	ft_strlcpy(str, "esto es un atraco",10);
	ft_strlcpy(str2, "La prueba de ft_memmove\n",24);
	
	printf("la prueba de ft_memmove str antes vale: %s\n", str);
	printf("la prueba de ft_memmove str2 antes vale: %s\n", str2);
	ft_memmove(str,str2,20);
	printf("la prueba de ft_memmove str despues vale: %s\n", str);
	printf("la prueba de ft_memmove str2 despues vale: %s\n", str2);
	

}
