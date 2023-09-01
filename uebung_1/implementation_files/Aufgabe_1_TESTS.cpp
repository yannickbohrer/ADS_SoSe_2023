#include <iostream>

#include "../header_files/Aufgaben.hpp"
#include "../header_files/ListD.hpp"
#include "../header_files/ListE.hpp"

void Aufgabe_1()
{
    ListE evListe;
    evListe.add(1);
    evListe.add(2);
    evListe.add(3);
    evListe.add(4);
    std::cout << "Einfache Liste vor swap: ";
    evListe.print();

    evListe.swap(1);
    evListe.swap(3);

    std::cout << "Einfache Liste nach swap: ";
    evListe.print();
    std::cout << std::endl;

    ListD dvListe;
    dvListe.add(1);
    dvListe.add(2);
    dvListe.add(3);
    dvListe.add(4);

    std::cout << "Doppelte Liste vor swap: ";
    dvListe.print();

    dvListe.swap(1);
    dvListe.swap(4);
    dvListe.swap(3);

    std::cout << "Doppelte Liste nach swap: ";
    dvListe.print();
    std::cout << std::endl;
}