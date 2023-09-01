#include "../header_files/Deque.hpp"

void Aufgabe_3()
{
    Deque queue;
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
    queue.print_all();
    queue.push_front(4);
    queue.push_front(5);
    queue.push_front(6);
    queue.print_all();
    queue.pop_back();
    queue.print_all();
    queue.pop_front();
    queue.pop_front();
    queue.print_all();
}