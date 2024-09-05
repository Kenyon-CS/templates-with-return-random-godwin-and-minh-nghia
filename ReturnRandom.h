#ifndef RETURN_RANDOM_H
#define RETURN_RANDOM_H

#include <vector>
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()

template <typename T>
class ReturnRandom {
private:
    std::vector<T> items;

public:
    // Constructor
    ReturnRandom();

    // Insert an item of type T
    void insert(const T& item);

    // Get a random item and remove it from the array
    T getRandom();
};

#include "ReturnRandom.cpp" // Include the template implementation

#endif // RETURN_RANDOM_H
