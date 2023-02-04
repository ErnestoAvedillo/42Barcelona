int ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	int i;

	i = ft_max(a, b);
	while (i % a != 0 || i % b != 0)
		i++;
	return (i);
}
