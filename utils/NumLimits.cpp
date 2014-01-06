#include "NumLimits.h"
#include <string>

using namespace std;

#define REPORT_LIMITS_FOR_TYPE(type, outStream) outStream << "\n" << #type << ":"; NumLimits::reportLimits<type>(outStream);

#define REPORT_NUM_LIMITS(type, out) \
	if (numeric_limits<type>::is_specialized) { \
		out << "\nisSigned(" << #type << ") = " << numeric_limits<type>::is_signed; \
		out << "\nisBounded(" << #type << ") = " << numeric_limits<type>::is_bounded; \
		out << "\nmax(" << #type << ") = " << numeric_limits<type>::max(); \
		out << "\nmin(" << #type << ") = " << numeric_limits<type>::min(); \
		out << "\ndigits(" << #type << ") = " << numeric_limits<type>::digits; \
		out << "\ndigits10(" << #type << ") = " << numeric_limits<type>::digits10; \
	} else { out << endl << #type << " is not specified.\n"; }


void NumLimits::reportLimitsAll(ostream& ostr)
{

	REPORT_LIMITS_FOR_TYPE(bool, ostr);
	REPORT_LIMITS_FOR_TYPE(char, ostr);
	REPORT_LIMITS_FOR_TYPE(short, ostr);
	REPORT_LIMITS_FOR_TYPE(__int16, ostr);
	REPORT_LIMITS_FOR_TYPE(int, ostr);
	REPORT_LIMITS_FOR_TYPE(unsigned int, ostr);
	REPORT_LIMITS_FOR_TYPE(__int64, ostr);
	REPORT_LIMITS_FOR_TYPE(float, ostr);
	REPORT_LIMITS_FOR_TYPE(double, ostr);
	REPORT_LIMITS_FOR_TYPE(long double, ostr);
}
