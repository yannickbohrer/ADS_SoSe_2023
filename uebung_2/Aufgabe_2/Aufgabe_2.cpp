#include <iostream>
#include <vector>
#include "Aufgabe_2.hpp"

int g(int a) {
    return a % 2 == 0;
}

int gtest(int li, int re)
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (li > re) return 0;
    int m = (li + re) / 2;
    return gtest(li, m-1) + g(a[m-1]) + gtest(m+1, re);
}

int gtest_iterativ(int li, int re)
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = 0;
    while(li <= re)
    {
        int m = (li + re) / 2;
        if (g(a[m-1]))
            result++;
        li++;
    }

    return result;
}

