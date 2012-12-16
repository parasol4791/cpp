#include "vector.h"

using namespace std;


vector<int> makeVectorInt(size_t n)
{
    vector < int >vec;
    for (size_t i = 0; i < n; i++)
        vec.push_back(i);

    return vec;
}

