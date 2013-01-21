#ifndef DK_ALGO_SEARCH
#define DK_ALGO_SEARCH

#include <vector>


// A linear search for an item in a vector.
// If found, returns a vector index, otherwise returns -1.
template<typename T>
int linearSearch(
    const T&            item,
    std::vector<T>&     vec
    )
{
    for (size_t i=0; i<vec.size(); i++)
        if (vec[i] == item)
            return i;

    return -1;
}




#endif  // DK_ALGO_SEARCH