#include "../header_files/ListE.hpp"

void Aufgabe_4()
{
    ListE list;
    for (int index = 0; index < 9; index++)
    {
        list.add(index*10);
    }
    list.print_reversed();
}