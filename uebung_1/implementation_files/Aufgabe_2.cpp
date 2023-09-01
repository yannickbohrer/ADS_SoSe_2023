#include "../header_files/Aufgaben.hpp"

#include <list>
#include <iostream>
#include <algorithm>

std::list<int> union_of_lists(const std::list<int>& l1,
                              const std::list<int>& l2)
{
    std::list<int> result = l1;
    for(const int l2_element : l2)
    {
        if (l2_element <= result.front())
            result.push_front(l2_element);
        else if (l2_element >= result.back())
            result.push_back(l2_element);
        else
        {
            auto index = result.begin();
            for (const int result_element : result)
            {
                if (l2_element <= result_element)
                {
                    result.insert(index, l2_element);
                    break;
                }
                ++index;
            }
        }
    }
    return result;
}

std::list<int> intersection_of_lists(const std::list<int>& l1,
                                     const std::list<int>& l2)
{
    std::list<int> result;
    for (const int l1_element : l1)
    {
        bool match = false;
        for (const int l2_element : l2)
        {
            if (l1_element == l2_element)
            {
                match = true;
                break;
            }
        }
        if(match)
            result.push_back(l1_element);
    }
    return result;
}

void print_list(const std::list<int>& list)
{
    int counter = 0;
    int length = list.size();
    std::cout << "<< ";
    for(const int element : list)
    {
        std::cout << element;
        if (counter != (length - 1))
            std::cout << ", ";
        counter++;
    }
    std::cout << " >>" << std::endl;

}

void Aufgabe_2_a(const std::list<int>& l1,
                 const std::list<int>& l2)
{
    std::list<int> result = union_of_lists(l1, l2);
    print_list(result);
}

void Aufgabe_2_b (const std::list<int>& l1,
                  const std::list<int>& l2)
{
    std::list<int> result = intersection_of_lists(l1, l2);
    print_list(result);
}

void Aufgabe_2()
{
    std::list<int> l1 = {10, 11, 13, 15, 18, 20, 21};
    std::list<int> l2 = {4, 8, 10, 12, 14, 15, 18, 23};

    std::cout << "Aufgabe 2 a): ";
    Aufgabe_2_a(l1, l2);
    std::cout << "Aufgabe 2 b): ";
    Aufgabe_2_b(l1, l2);
}

