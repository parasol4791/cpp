#include <iostream>
#include <iomanip>

#include "utils/vector.h"
#include "algo/sort.h"

using namespace std;


int main()
{
	cout << "Hello!" << endl;

	vector<int> vInt = makeVectorInt(8);

	outputVector(cout, vInt);
	cout << "Enter a symbol, then \"Enter\": ";
    char ch;
    cin >> ch;
	return 0;
}
