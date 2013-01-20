#include <iostream>
#include <iomanip>

#include "utils/vector.h"
#include "algo/sort.h"

using namespace std;


int main()
{
	cout << "Hello!" << endl;

	vector<int> vInt = makeVectorInt(8, 20, -3);
	vector<int> vIntUniform = makeVectorIntUniform(80, 5, 25);

	outputVector(cout, vInt);
    outputVector(cout, vIntUniform);
	cout << "Enter a symbol, then \"Enter\": ";
    char ch;
    cin >> ch;
	return 0;
}
