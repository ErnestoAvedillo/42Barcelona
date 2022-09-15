int ft_sqrt(int nb)
{
	int	count;

	count = 1;
	while(count * count <= nb)
	{
		if (count * count == nb) 
			return (count);
		count++;
	}
	return (0);
}