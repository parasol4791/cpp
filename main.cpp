#include "utils/vector.h"
#include "utils/NumLimits.h"
#include "utils/codec.h"
#include "algo/sort.h"
#include "algo/search.h"

#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;



int main()
{
	const size_t bSize = numeric_limits<unsigned int>::digits;
	for (size_t i=8; i<16; i++)
	{
		unsigned int iGray = GrayCodes::convertToGray(i);
		unsigned int iInt = GrayCodes::decodeFromGray(iGray);
		

		cout << i << "  " << bitset<bSize>(i) << "  to  "
			 << bitset<bSize>(iGray) << "  " << iGray << "  back to  " << iInt << endl;
	}

	NumLimits::reportLimitsAll(std::cout);

	vector<int> vInt = makeVectorInt(16, 20, 3);
	outputVector(cout, vInt);

    int idx = linearSearch(38, vInt);
    cout << "Index for 38 is " << idx << std::endl;
    int idx1 = linearSearch(23, vInt);
    cout << "Index for 23 is " << idx1 << std::endl;

    sortInsertionRecursive(vInt, false); // descending order
    outputVector(cout, vInt);

    sortInsertionRecursive(vInt, true, 0, 1, 7);
    outputVector(cout, vInt);

	vector<int> vIntUniform = makeVectorIntUniform(11, 5, 25);
    outputVector(cout, vIntUniform);

//    sortInsertion(vIntUniform);
    sortMerge(vIntUniform, 1);
    outputVector(cout, vIntUniform);




	cout << "Enter a symbol, then \"Enter\": ";
    char ch;
    cin >> ch;
	return 0;
}
