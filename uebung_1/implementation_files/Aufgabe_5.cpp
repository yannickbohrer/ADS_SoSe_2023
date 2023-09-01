#include <iostream>
#include "../header_files/Aufgaben.hpp"
#include "../header_files/DoubleStack.hpp"

void Aufgabe_5()
{
    DoubleStack test(10);
    test.push0(1);
    test.push0(3);
    test.push0(5);
    test.push0(7);
    test.push1(2);
    test.push1(4);
    test.push1(6);
    test.push1(8);
    std::cout << "initial: ";
    test.print_test();
    std::cout << "m_top_stack0: " << test.get_m_top_stack0() << std::endl;
    std::cout << "m_top_stack1: " << test.get_m_top_stack1() << std::endl << std::endl;

    test.push0(9);
    test.push0(11);
    test.push0(13);
    test.push0(15);
    std::cout << "test push0: ";
    test.print_test();
    std::cout << std::endl;

    test.push1(10);
    test.push1(12);
    test.push1(14);
    test.push1(16);
    std::cout << "test push1: ";
    test.print_test();
    std::cout << std::endl;
    std::cout << "m_top_stack0 am Ende: " << test.get_m_top_stack0() << std::endl;
    std::cout << "m_top_stack1 am Ende: " << test.get_m_top_stack1() << std::endl;

    std::cout << std::endl << "---------- jetzt pop ----------" << std::endl << std::endl;

    test.pop0();
    test.pop0();
    std::cout << "test pop0: ";
    test.print_test();
    std::cout << "m_top_stack0: " << test.get_m_top_stack0() << std::endl;
    std::cout << "m_top_stack1: " << test.get_m_top_stack1() << std::endl << std::endl;


    test.pop1();
    test.pop1();
    std::cout << "test pop1: ";
    test.print_test();
    std::cout << "m_top_stack0: " << test.get_m_top_stack0() << std::endl;
    std::cout << "m_top_stack1: " << test.get_m_top_stack1() << std::endl << std::endl;
}
