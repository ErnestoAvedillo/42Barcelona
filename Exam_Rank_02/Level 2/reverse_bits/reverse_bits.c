unsigned char reverse_bits(unsigned char octet)
{
	unsigned char n;
	int i;

	n = 0;
	i = 0;
	while (i <= 7)
	{
		n = n * 2 + (octet >> i & 1);
		i++;
	}
	return (n);
}
