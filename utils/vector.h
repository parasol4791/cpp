#ifndef DK_UTILS_VECTOR
#define DK_UTILS_VECTOR

#include <iostream>
#include <vector>

std::vector<int> makeVectorInt(
    size_t  n,                  // number of generated results
    int     startFrom = 0,      // start from this number
    int     step = 1            // interval between consequtive numbers
    );

// Random Uniform generation in the range [min, max]
std::vector<int> makeVectorIntUniform(
    size_t  n,      // number of generated results
    int     min,    // start from this number
    int     max     // interval between consequtive numbers
    );

template<typename T>
void outputVector(
    std::ostream&           ostr,
    const std::vector<T>&   vec
    )
{
    typename std::vector<T>::const_iterator iter = vec.begin();
    for (iter; iter<vec.end(); iter++)
        std::cout << *iter << " ";
    ostr << std::endl;
}

# endif  // DK_UTILS_VECTOR
