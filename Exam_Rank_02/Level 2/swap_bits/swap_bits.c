unsigned char swap_bits(unsigned char octet)
{
	unsigned char out;
	out = (octet << 4) + (octet >> 4);
	return (out);
}
