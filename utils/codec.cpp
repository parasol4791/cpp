#include "codec.h"
#include <bitset>
#include <limits>

using namespace std;

// Convert to Gray code
unsigned int GrayCodes::convertToGray(const unsigned int n)
{ return n ^ (n >> 1); }

// Decode from Gray code
unsigned int GrayCodes::decodeFromGray(const unsigned int n)
{
	int ish = 1;
	unsigned int ans=n, idiv;

	while (true)
	{
		idiv = ans >> ish;
		ans ^= idiv;
		if (idiv <= 1 || ish == 16)
			return ans;

		ish <<= 1;
	}
}

// Convert to Gray using a bitset
unsigned int GrayCodes::convertToGrayUsingBitset(const unsigned int n)
{
	bitset<numeric_limits<unsigned int>::digits> bGray(n);
	for (size_t b = 0; b < bGray.size()-1; b++)
		bGray[b] = bGray[b]^bGray[b+1];

	return bGray.to_ulong();
}

// Decode from Gray using a bitset
unsigned int GrayCodes::decodeFromGrayUsingBitset(const unsigned int n)
{
	bitset<numeric_limits<unsigned int>::digits> bInt(n);
	for (int b = bInt.size()-2; b>=0; b--)
		bInt[b] = bInt[b]^bInt[b+1];

	return bInt.to_ulong();
}

