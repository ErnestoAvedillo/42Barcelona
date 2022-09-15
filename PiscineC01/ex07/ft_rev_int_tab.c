
void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int aux;

	count = 0;
	while(count <= size-1)
	{
		aux = tab[count];
		tab[count] = tab[size-1];
		tab[size-1] = aux;
		count++;
		size--;
	}
	return;
}