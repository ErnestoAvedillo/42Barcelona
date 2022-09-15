int	get_prime(int nb)
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

int	ft_find_next_prime(int nb)
{
	int	count;

	if (nb < 0)
		return (1);
	count = nb + 1;
	while (!get_prime (count) && count < 2147483647)
		count++;
	return (count);

}