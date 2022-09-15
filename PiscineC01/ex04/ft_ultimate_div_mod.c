void	ft_ultimate_div_mod(int *a, int *b)
{
	int val_a;
	int val_b;

	val_a = *a;
	val_b = *b;
	*a = val_a / val_b;
	*b = val_a % val_b;
	return;
}