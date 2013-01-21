#include <iostream>
#include <iomanip>

#include "utils/vector.h"
#include "algo/sort.h"
#include "algo/search.h"

using namespace std;


int main()
{
	cout << "Hello!" << endl;

/*	vector<int> vInt = makeVectorInt(8, 20, 3);
	outputVector(cout, vInt);

    int idx = linearSearch(38, vInt);
    cout << "Index for 38 is " << idx << std::endl;
    int idx1 = linearSearch(23, vInt);
    cout << "Index for 23 is " << idx1 << std::endl;

    sortInsertion(vInt, false); // descending order
    outputVector(cout, vInt);    */

	vector<int> vIntUniform = makeVectorIntUniform(11, 5, 25);
    outputVector(cout, vIntUniform);

//    sortInsertion(vIntUniform);
    sortMerge(vIntUniform);
    outputVector(cout, vIntUniform);




	cout << "Enter a symbol, then \"Enter\": ";
    char ch;
    cin >> ch;
	return 0;
}
