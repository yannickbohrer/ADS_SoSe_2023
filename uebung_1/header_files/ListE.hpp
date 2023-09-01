#ifndef LIST_E_HPP
#define LIST_E_HPP

#include <list>
#include <iostream>

#include "NodeE.hpp"

class ListE
{
public:
    ListE();
    ListE(std::initializer_list<int> init);

    ~ListE();

    void add(const int& item);  // Knoten am Ende der Liste einfuegen
    void print() const;
    int length() const;

    bool swap(const int& index); // Knoten an der stelle Index mit dem naechsten tauschen => Aufgabe 1
    void print_reversed() const; // Liste rueckwaerts (in O(n)) ausgeben. => Aufgabe 4
private:
    NodeE* m_head;
    NodeE* m_tail;
    int m_length;

    void print_reversed_helper(NodeE* node) const;  // Hilfsmethode falls print_reversed rekursiv
};

#endif