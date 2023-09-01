#include "../header_files/ListD.hpp"

ListD::ListD() {
    m_length = 0;
    m_head = nullptr;
    m_tail = nullptr;
};

ListD::ListD(std::initializer_list<int> init)
{
    m_length = 0;
    for (const int& item : init) this->add(item);
}

ListD::~ListD()
{
    if (m_head == nullptr) return;
    while (m_head->next != nullptr)
    {
        m_head = m_head->next;
        delete m_head->prev;
    }
    delete m_head;
}

void ListD::add(const int& item)
{
    m_length++;

    NodeD* new_node = new NodeD();
    new_node->item = item;
    new_node->prev = m_tail;

    if (m_tail == nullptr) m_head = new_node;
    else m_tail->next = new_node;

    m_tail = new_node;
}

void ListD::print() const
{
    NodeD* current = m_head;
    std::cout << "[";
    while (true)
    {
        std::cout << current->item;
        if (current->next != nullptr)
        {
            std::cout << ", ";
            current = current->next;
        }
        else break;
    }
    std::cout << "]" << std::endl;
}

void ListD::print_reversed() const
{
    NodeD* current = m_tail;
    std::cout << "[";
    while (true)
    {
        std::cout << current->item;
        if (current->prev != nullptr)
        {
            std::cout << ", ";
            current = current->prev;
        }
        else break;
    }
    std::cout << "]" << std::endl;
}

int ListD::length() const
{
    return m_length;
}

bool ListD::swap(const int& index)
{
    if (index >= m_length)
        return false;
    if (index < 1)
        return false;

    if (index == 1)
    {
        NodeD* tmp = m_head->next;
        m_head->prev = m_head->next;
        m_head->next = m_head->next->next;
        m_head->next->prev = m_head;
        tmp->next = m_head;
        tmp->prev = nullptr;
        m_head = tmp;
        if (m_length == 2)
            m_tail = m_head->next;
        return true;
    }

    NodeD* ptr = m_head;
    for (int iterator = 1; iterator < (index - 1); iterator++)
    {
        ptr = ptr->next;
    }
    NodeD* tmp3 = ptr->next->next->next;
    NodeD* tmp2 = ptr->next->next;
    NodeD* tmp1 = ptr->next;

    ptr->next = tmp2;
    ptr->next->prev = ptr;
    ptr->next->next = tmp1;
    ptr->next->next->prev = tmp2;
    ptr->next->next->next = tmp3;
    if (ptr->next->next->next)
        ptr->next->next->next->prev = tmp1;

    if (index == (m_length - 1))
        m_tail = ptr->next->next;

    return true;
}