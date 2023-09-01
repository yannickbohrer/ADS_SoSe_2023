#include <iostream>
#include "../header_files/Deque.hpp"

Deque::Deque()
{
    m_head = nullptr;
    m_tail = nullptr;
}
Deque::Deque(std::initializer_list<int> init)
{
    for (const int& item : init) this->push_back(item);
}
Deque::~Deque()
{
    if (m_head == nullptr) return;
    while (m_head->next != nullptr)
    {
        m_head = m_head->next;
        delete m_head->prev;
    }
    delete m_head;
}

void Deque::push_front(const int& item)
{
    auto* new_entry = new NodeD { item, nullptr, nullptr };
    if (!m_head)
        m_tail = new_entry;
    else
    {
        m_head->prev = new_entry;
        new_entry->next = m_head;
    }
    m_head = new_entry;
}

int Deque::pop_front()
{
    if (!m_head)
        return 0;   // Null symbolisiert hier eine leere queue
    int front_data = m_head->item;
    m_head = m_head->next;
    delete m_head->prev;
    m_head->prev = nullptr;
    return front_data;
}

void Deque::push_back(const int& item)
{
    auto* new_entry = new NodeD { item, nullptr, nullptr };
    if (!m_head)
        m_head = new_entry;
    else
    {
        m_tail->next = new_entry;
        new_entry->prev = m_tail;
    }
    m_tail = new_entry;
}

int Deque::pop_back()
{
    if (!m_head)
        return 0;   // Null symbolisiert hier eine leere queue
    int back_data = m_tail->item;
    m_tail = m_tail->prev;
    delete m_tail->next;
    m_tail->next = nullptr;
    return back_data;
}

void Deque::print_all() const
{
    NodeD* ptr = m_head;
    std::cout << "| ";
    while(ptr)
    {
        std::cout << ptr->item;
        if (ptr->next)
            std::cout << ", ";
        ptr = ptr->next;
    }
    std::cout << " |" << std::endl;
}