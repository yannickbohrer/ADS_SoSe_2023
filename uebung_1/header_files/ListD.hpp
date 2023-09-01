#ifndef LIST_D_HPP
#define LIST_D_HPP

#include <list>
#include <iostream>

#include "NodeD.hpp"

class ListD
{
public:
    ListD();
    ListD(std::initializer_list<int> init);
    ~ListD();
    void add(const int& item);
    void print() const;
    void print_reversed() const;
    int length() const;
    bool swap(const int& index);
private:
    NodeD* m_head;
    NodeD* m_tail;
    int m_length;
};

#endif