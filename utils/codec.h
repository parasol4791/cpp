#ifndef DK_UTILS_CODEC
#define DK_UTILS_CODEC

// Coding/decoding to Gray codes
// Numerical recipies, 3rd ed., p.1166-1168
class GrayCodes
{
public:
	// Convert to Gray code
	static unsigned int convertToGray(const unsigned int n);
	// Decode from Gray code
	static unsigned int decodeFromGray(const unsigned int n);

	// Convert to Gray using a bitset
	static unsigned int convertToGrayUsingBitset(const unsigned int n);
	// Decode from Gray using a bitset
	static unsigned int decodeFromGrayUsingBitset(const unsigned int n);
};


#endif  // DK_UTILS_CODEC