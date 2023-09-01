#include <iostream>
#include "../header_files/DoubleStack.hpp"

DoubleStack::DoubleStack(int size)
{
    m_array = new int[size] { 0 };
    m_size = size;
    m_allocation_size = size;
    m_top_stack0 = -1;
    m_top_stack1 = size;

    pop_from_stack_0 = false;
    pop = 0;
}

int DoubleStack::get_m_top_stack0() const
{
    return m_top_stack0;
}

int DoubleStack::get_m_top_stack1() const
{
    return m_top_stack1;
}

void DoubleStack::push0(const int& item)
{
    if (m_top_stack0 + 1 != m_top_stack1)
    {
        m_array[m_top_stack0 + 1] = item;
        m_top_stack0++;
        return;
    }

    m_allocation_size = m_size + 1;
    resize();
    m_array[m_top_stack0 + 1] = item;
    m_top_stack0++;
}

void DoubleStack::push1(const int& item)
{
    if (m_top_stack1 - 1 != m_top_stack0)
    {
        m_array[m_top_stack1 - 1] = item;
        m_top_stack1--;
        return;
    }

    m_allocation_size = m_size + 1;
    resize();
    m_array[m_top_stack1 - 1] = item;
    m_top_stack1--;
}

int DoubleStack::pop0()
{
    if (m_top_stack0 == -1)
        exit(-1);
    m_allocation_size = m_size - 1;
    pop_from_stack_0 = true;
    pop = m_array[m_top_stack0];
    resize();
    m_top_stack0--;
    m_top_stack1--;
    return pop;
}

int DoubleStack::pop1()
{
    if (m_top_stack1 == m_size)
        exit(-1);
    m_allocation_size = m_size - 1;
    pop_from_stack_0 = false;
    pop = m_array[m_top_stack1];
    resize();
    return pop;
}

void DoubleStack::print_test()
{
    for (int index = 0; index < m_size; index++)
    {
        std::cout << m_array[index];
        if (index != m_size - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void DoubleStack::resize()
{
    int* m_new_array = new int[m_allocation_size];
    for (int index = 0; index < m_allocation_size; index++)
        m_new_array[index] = 0;
    if (m_allocation_size > m_size)
    {
        for (int index = 0; index <= m_top_stack0; index++)
            m_new_array[index] = m_array[index];

        for (int index = m_top_stack1; index < m_allocation_size; index++)
            m_new_array[index + 1] = m_array[index];
        m_top_stack1++;
    }
    else {
        if (pop_from_stack_0)
        {
            for (int index = 0; index < m_top_stack0; index++)
                m_new_array[index] = m_array[index];

            for (int index = m_top_stack1; index < m_size; index++)
                m_new_array[index - 1] = m_array[index];
        }
        else
        {
            for (int index = 0; index <= m_top_stack0; index++)
            {
                m_new_array[index] = m_array[index];
            }

            for (int index = m_top_stack1 + 1; index < m_size; index++)
                m_new_array[index - 1] = m_array[index];
        }
    }

    m_size = m_allocation_size;
    delete [] m_array;
    m_array = m_new_array;
}