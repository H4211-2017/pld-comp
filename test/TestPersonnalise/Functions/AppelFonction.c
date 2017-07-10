#include <stdint.h>

int32_t fonctionAvant(int32_t z)
{
	return z;
}

int32_t main()
{
	int32_t a;
	a = 3;
	return fonctionAvant(a); // expected 3;
}


