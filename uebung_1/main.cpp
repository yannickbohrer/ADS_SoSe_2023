#include <iostream>
#include <string>
#include "header_files/Aufgaben.hpp"

int main ()
{
    int ex = 5;

    switch (ex)
    {
    case 1:
        Aufgabe_1();
        break;
    case 2:
        Aufgabe_2();
        break;
    case 3:
        Aufgabe_3();
        break;
    case 4:
        Aufgabe_4();
        break;
    case 5:
        Aufgabe_5();
        break;
    case 6:
        Aufgabe_6();
        break;
    default:
        std::cout << "nah, bad input" << std::endl;
    }
    return 0;
}