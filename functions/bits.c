
// change state of a single bit
int set_bit(int num, int bit)
{
	int mask = 1;
	mask <<= bit;
	num |= mask;
	return num;
}

// get state of a single bit
int check_bits(int num, int bits)
{
	return (num & bits) == bits;
}
