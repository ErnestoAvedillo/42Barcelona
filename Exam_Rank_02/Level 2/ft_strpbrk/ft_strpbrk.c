#include<stdlib.h>
char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int j;

	j = -1;
	while (s2[++j])
	{
		i = 0;
		while (s1[i])
		{
			if (s1[i] == s2[j])
				return ((char*)s1 + i);
			i++;
		}
	}
	return (NULL);
}
