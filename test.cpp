#include <iostream>
#include "ReturnRandom.h"

int main() {
    // Test with integers
    ReturnRandom<int> intRandomizer;
    intRandomizer.insert(10);
    intRandomizer.insert(20);
    intRandomizer.insert(30);

    std::cout << "Random integer: " << intRandomizer.getRandom() << std::endl;
    std::cout << "Random integer: " << intRandomizer.getRandom() << std::endl;
    std::cout << "Random integer: " << intRandomizer.getRandom() << std::endl;

    // Test with strings
    ReturnRandom<std::string> stringRandomizer;
    stringRandomizer.insert("apple");
    stringRandomizer.insert("banana");
    stringRandomizer.insert("cherry");

    std::cout << "Random string: " << stringRandomizer.getRandom() << std::endl;
    std::cout << "Random string: " << stringRandomizer.getRandom() << std::endl;
    std::cout << "Random string: " << stringRandomizer.getRandom() << std::endl;

    return 0;
}
