#include "vector.h"
//#include <boost/random/random_number_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

using namespace std;


vector<int> makeVectorInt(
    size_t  n,                  // number of generated results
    int     startFrom,          // start from this number
    int     step                // interval between consequtive numbers
    )
{
    vector<int> vec;
    int gen = startFrom;

    for (size_t i=0; i<n; i++) 
    {
        vec.push_back(gen);
        gen += step;
    }

    return vec;
}

// Random Uniform generation in the range [min, max]
vector<int> makeVectorIntUniform(
    size_t  n,      // number of generated results
    int     min,    // start from this number
    int     max     // interval between consequtive numbers
    )
{
    vector<int> vec;
    boost::random::mt19937 gen;
    boost::random::uniform_int_distribution<> uniformGen(min, max);

    for (size_t i=0; i<n; i++)
        vec.push_back(uniformGen(gen));

    return vec;
}