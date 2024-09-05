#include "ReturnRandom.h"

// Constructor
template <typename T>
ReturnRandom<T>::ReturnRandom() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
}

// Insert an item of type T
template <typename T>
void ReturnRandom<T>::insert(const T& item) {
    items.push_back(item);
}

// Get a random item and remove it from the array
template <typename T>
T ReturnRandom<T>::getRandom() {
    if (items.empty()) {
        throw std::out_of_range("No items available");
    }

    int index = rand() % items.size();
    T randomItem = items[index];
    items.erase(items.begin() + index);

    return randomItem;
}
