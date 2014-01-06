#ifndef DK_UTILS_NUMLIMITS
#define DK_UTILS_NUMLIMITS

#include <iostream>
#include <iomanip>
#include <math.h>

class NumLimits
{
public:

	// Report p;atform-dependent limits for a a numerical type.
	// Josuttis, The C++ standard library, 1999, p.59-65
	// Numerical recipies, 3rd ed, p.1163-1165
	template<class T>
	static void reportLimits(std::ostream& ostr)
	{
		if (numeric_limits<T>::is_specialized)
		{
			size_t w = 18;
			size_t wv = 21;
			ostr.setf(ios::left);
			ostr << boolalpha;  // string representation of booleans

			int radix = numeric_limits<T>::radix;
			int digits = numeric_limits<T>::digits;
			int max_exponent = numeric_limits<T>::max_exponent;
			double epsilon_neg = max_exponent ? pow(radix, -digits) : 0.0;

			int roundStyle = numeric_limits<T>::round_style;
			string rStyle;
			if      (roundStyle=0) rStyle = "Rounds towards zero";
			else if (roundStyle=1) rStyle = "Rounds to the nearest value";
			else if (roundStyle=2) rStyle = "Rounds towards positive infinity";
			else if (roundStyle=3) rStyle = "Rounds towards negative infinity";
			else if (roundStyle=4) rStyle = "Indererminable";

			ostr << std::setw(w) << "\nisSigned " << std::setw(wv) << numeric_limits<T>::is_signed
				<< std::setw(w) << "\nisBounded " << std::setw(wv) << numeric_limits<T>::is_bounded
				<< std::setw(w) << "\nisModulo " << std::setw(wv) << numeric_limits<T>::is_modulo << "Add 2 positives may give a lesser result"
				<< std::setw(w) << "\nradix " << std::setw(wv) << radix << "Base"
				<< std::setw(w) << "\ndigits " << std::setw(wv) << digits << "Non-signed binary bits in mantissa"
				<< std::setw(w) << "\ndigits10 " << std::setw(wv) << numeric_limits<T>::digits10 << "Meaningful decimal digits in mantissa"
				<< std::setw(w) << "\nmin exponent " << std::setw(wv) << numeric_limits<T>::min_exponent << "Binary"
				<< std::setw(w) << "\nmax exponent " << std::setw(wv) << max_exponent << "Binary"
				<< std::setw(w) << "\nmin exponent10 " << std::setw(wv) << numeric_limits<T>::min_exponent10 << "Decimal"
				<< std::setw(w) << "\nmax exponent10 " << std::setw(wv) << numeric_limits<T>::max_exponent10 << "Decimal"
				<< std::setw(w) << "\nepsilon" << std::setw(wv) << numeric_limits<T>::epsilon() << "radix^(-(digits-1))"
				<< std::setw(w) << "\nepsilon negative" << std::setw(wv) << epsilon_neg << "radix^(-digits)"
				<< std::setw(w) << "\nmin " << std::setw(wv) << numeric_limits<T>::min() << "radix^(min_exponent-1)"
				<< std::setw(w) << "\nmax " << std::setw(wv) << numeric_limits<T>::max() << "(1-epsilon_neg)*radix^max_exponent"
			//	<< "\nepsilon (computed)" << pow(2,-numeric_limits<T>::digits+1)
			//	<< "\nmin (computed)" << pow(2,numeric_limits<T>::min_exponent-1)
			//	<< "\nmax (computed)" << radix*(1-epsilon_neg)*pow(radix,max_exponent-1) // outright power to max_exponent causes 1.#INF result
				<< std::setw(w) << "\nround style " << std::setw(wv) << roundStyle << rStyle
				<< std::setw(w) << "\nround error " << std::setw(wv) << numeric_limits<T>::round_error()
				<< std::setw(w) << "\nhas denorm " << std::setw(wv) << numeric_limits<T>::has_denorm << "Fills underflow gap, #DEN numbers"
				<< std::setw(w) << "\nhas denorm loss" << std::setw(wv) << numeric_limits<T>::has_denorm_loss
				<< std::setw(w) << "\ndenorm min " << std::setw(wv) << numeric_limits<T>::denorm_min() << "Jumps to exact zero below this number"
				<< std::setw(w) << "\nis iec559 " << std::setw(wv) << numeric_limits<T>::is_iec559 << "Compliant with IEEE 754-1985"
				<< endl;
		}
		else
		{
			ostr << "\nType is not specified.\n";
		}
	}

	// Generates a report for many major build-in types. 
	static void reportLimitsAll(std::ostream& ostr);

};

#endif  // DK_UTILS_NUMLIMITS

