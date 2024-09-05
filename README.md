# ReturnRandom
A template class that stores elements, and returns them randomly.
# Notes
1. `ReturnRandom.h`:
  - Declares the `ReturnRandom` template class with methods to insert items and retrieve a random item while removing it from the internal list.
2. `ReturnRandom.cpp`:
  - Implements the methods declared in `ReturnRandom.h`.
  - Uses a `std::vector` to store items.
  - The `getRandom` method uses `rand()` to select a random index, returns the corresponding item, and removes it from the vector.
3. `test.cpp`:
  - Demonstrates the usage of `ReturnRandom` with int and `std::string` types.
  - The program inserts items into the `ReturnRandom` object and then retrieves and prints random items.
4. `Makefile`:
  - Compiles the `test.cpp` file along with the template class.
  - Handles compilation, linking, cleaning, and running the program.
