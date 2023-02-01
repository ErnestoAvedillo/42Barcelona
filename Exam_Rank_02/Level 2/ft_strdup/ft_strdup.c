#include<stdlib.h>

int ft_strlen(char *str)
{
	int i;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int i;
	char *dst;

	i = ft_strlen(src);
	dst = (char *)malloc((i + 1) * sizeof(char));
	i++;
	while ( i >= 0)
	{
		dst[i] = src[i];
		i--;
	}
	return(dst);
}
