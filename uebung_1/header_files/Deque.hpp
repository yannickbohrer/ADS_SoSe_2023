#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <list>
#include "NodeD.hpp"

class Deque
{
public:
    Deque();
    Deque(std::initializer_list<int> init);
    ~Deque();

    void push_front(const int& item);
    int pop_front();
    void push_back(const int& item);
    int pop_back();
    void print_all() const;
private:
    NodeD* m_head;
    NodeD* m_tail;
};

#endif