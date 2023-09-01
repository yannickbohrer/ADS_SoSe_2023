#include <iostream>
#include "Aufgabe_2/Aufgabe_2.hpp"

int main ()
{
    std::cout << "rekursiv: " << gtest(1, 10) << std::endl;
    std::cout << "iterativ: " << gtest_iterativ(1, 10) << std::endl;
    gtest(1,10) == gtest_iterativ(1,10) ?
    std::cout << "jup" << std::endl :
    std::cout << "nope" << std::endl;
    return 0;
}
