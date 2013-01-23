#ifndef DK_ALGO_SORT
#define DK_ALGO_SORT

#include <vector>

// A convenience method hiding initial indices.
template<typename T>
void sortMerge(
    std::vector<T>& vec,
    size_t          threshold = 4
    )
{
    sortMerge(vec, threshold, 0, vec.size()-1);
}

// Sorting using a recursive merge algorithm.
// Internally uses a sortInsertion algorithm for small (sub)arrays
// below a threshold size.
template<typename T>
void sortMerge(
    std::vector<T>& vec,
    size_t          threshold,
    size_t          idx1,
    size_t          idx3
    )
{
    size_t size = idx3 - idx1 + 1;
    // Return the unchanged vector is its size is 1.
    if (size == 1)
        return;
    // Use insertion sort for small arrays
    else if (size < threshold)
        return sortInsertion(vec, true, idx1, idx3);
    // Otherwise, use a merge sort algorithm.
    else
    {
        size_t idx2 = idx1 + (size_t)std::floor((size-1)/2.0);

        sortMerge(vec, threshold, idx1, idx2);
        sortMerge(vec, threshold, idx2+1, idx3);
        merge(vec, idx1, idx2, idx3);
    }
}

template<typename T>
void merge(
    std::vector<T>& vec,
    size_t          idx1,
    size_t          idx2,
    size_t          idx3
    )
{
    size_t lSize = idx2-idx1+1;
    size_t rSize = idx3-idx2;
    std::vector<T> L, R;
    size_t i;

    for (i=idx1; i<=idx2; i++)
        L.push_back(vec[i]);
    for (i=idx2+1; i<=idx3; i++)
        R.push_back(vec[i]);

    size_t l(0), r(0), v(idx1);
    do
    {
        if (L[l] < R[r])
        {
            vec[v] = L[l];
            l++;
        }
        else
        {
            vec[v] = R[r];
            r++;
        }
        v++;
    }
    while (l < lSize && r < rSize);

    // L array was over
    if (l == lSize)
    {
        for (i=r; i<rSize; i++)
        {
            vec[v] = R[i];
            v++;
        }
    }
    else
    // R array was over 
    {
        for (i=l; i<lSize; i++)
        {
            vec[v] = L[i];
            v++;
        }
    }
}

// A convenience method hiding vector indices.
template<typename T>
void sortInsertion(
    std::vector<T>&     vec,
    bool                ascending = true
    )
{
    sortInsertion(vec, ascending, 0, vec.size()-1);
}

// Sorting an array with an insertion sort:
// each element "bubbles down" (or "bubbled up" in the case
// of a descending sorting) until it gets to its place.
// Can sort only a part of an array in the range [idx1, idx2].
template<typename T>
void sortInsertion(
    std::vector<T>&     vec,
    bool                ascending,
    int                 idx1,
    int                 idx2
    )
{
    if (ascending)
    // An ascending order. Elements "bubble down"
    // towards the beginning of a vector.
    {
        for (int i=idx1 + 1; i<=idx2; i++)
        {
            T temp = vec[i];
            int j = i-1;

            while (j >= idx1 && vec[j] > temp)
            {
                vec[j+1] = vec[j];
                j--;
            }
            vec[j+1] = temp;
        }
    }
    else
    // A descending order. Elements "bubble up"
    // towards the end of a vector.
    {
        for (int i=idx2-1; i>=idx1; i--)
        {
            T temp = vec[i];
            int j = i+1;

            while (j < idx2+1 && vec[j] > temp)
            {
                vec[j-1] = vec[j];
                j++;
            }
            vec[j-1] = temp;
        }
    }
}

// A convenience method hiding vector indices.
template<typename T>
void sortInsertionRecursive(
    std::vector<T>&     vec,
    bool                ascending = true
    )
{
    int idx2 = ascending ? 1 : vec.size()-2;
    sortInsertionRecursive(vec, ascending, 0, idx2, vec.size()-1);
}

template<typename T>
void sortInsertionRecursive(
    std::vector<T>&     vec,
    bool                ascending,
    int                 idx1,
    int                 idx2,
    int                 idx3
    )
{
    if (ascending)
    {
        // An ascending order. Elements "bubble down"
        // towards the beginning of a vector.
        T temp = vec[idx2];
        int j = idx2-1;

        while (j >= idx1 && vec[j] > temp)
        {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = temp;

        if (++idx2 > idx3)
            return;
    }
    else
    {
        // A descending order. Elements "bubble up"
        // towards the end of a vector.
        T temp = vec[idx2];
        int j = idx2+1;

        while (j < idx3+1 && vec[j] > temp)
        {
            vec[j-1] = vec[j];
            j++;
        }
        vec[j-1] = temp;

        if (--idx2 < idx1)
            return;
    }

    sortInsertionRecursive(vec, ascending, idx1, idx2, idx3);
}



#endif  // DK_ALGO_SORT
