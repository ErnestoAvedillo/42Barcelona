char *ft_strrev(char *str)
{
	int i;
	int j;
	char c;

	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	while (j < i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i--;
		j++;
	}
	return(str);
}
