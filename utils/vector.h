#ifndef DK_UTILS_VECTOR
#define DK_UTILS_VECTOR

#include <iostream>
#include <vector>

std::vector<int> makeVectorInt(size_t n);

template<typename T>
void outputVector(
    std::ostream & ostr,
    const std::vector<T>& vec
    )
{
    typename std::vector<T>::const_iterator iter = vec.begin();
    for (iter; iter<vec.end(); iter++)
        std::cout << *iter << " ";
    ostr << std::endl;
}

# endif  // DK_UTILS_VECTOR
