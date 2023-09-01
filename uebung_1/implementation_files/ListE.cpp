#include "../header_files/ListE.hpp"

ListE::ListE()
{
    m_length = 0;
    m_head = nullptr;
    m_tail = nullptr;
};

ListE::ListE(std::initializer_list<int> init)
{
    m_length = 0;
    for (const int& item : init) this->add(item);
}

ListE::~ListE()
{
    while (m_head != nullptr)
    {
        NodeE* tmp = m_head->next;
        delete m_head;
        m_head = tmp;
    }
}

void ListE::add(const int& item)
{
    m_length++;
    NodeE* new_node = new NodeE();
    new_node->item = item;
    if (m_tail == nullptr) m_head = new_node;
    else m_tail->next = new_node;

    m_tail = new_node;
}

void ListE::print() const
{
    NodeE* current = m_head;
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

int ListE::length() const
{
    return m_length;
}

bool ListE::swap(const int& index)
{
    if (index >= m_length)
        return false;
    if (index < 1)
        return false;

    if (index == 1)
    {
        NodeE* tmp = m_head->next;
        m_head->next = m_head->next->next;
        tmp->next = m_head;
        m_head = tmp;
        if (m_length == 2)
            m_tail = m_head->next;
        return true;
    }

    NodeE* ptr = m_head;
    for (int iterator = 1; iterator < (index - 1); iterator++)
    {
        ptr = ptr->next;
    }
    NodeE* tmp1 = ptr->next->next->next;
    NodeE* tmp2 = ptr->next->next;
    NodeE* tmp3 = ptr->next;
    ptr->next = tmp2;
    ptr->next->next = tmp3;
    ptr->next->next->next = tmp1;

    if (index == (m_length - 1))
        m_tail = ptr->next->next;
    return true;
}

void ListE::print_reversed() const
{
    std::cout << "<< ";
    print_reversed_helper(m_head);
    std::cout << " >>" << std::endl;
}

void ListE::print_reversed_helper(NodeE* node) const
{
    if (!node)
        return;
    print_reversed_helper(node->next);
    std::cout << node->item;
    if (node != m_head)
        std::cout << ", ";
}