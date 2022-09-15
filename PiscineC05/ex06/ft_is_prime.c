int	ft_is_prime(int nb)
{
	int	count;

	count = 2;
	while (count < nb)
	{
		if (nb % count == 0)
			return (0);
		count++;
	}
	return (1);
}