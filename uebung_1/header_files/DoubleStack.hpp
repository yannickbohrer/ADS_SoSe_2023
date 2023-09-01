#ifndef DOUBLE_STACK_HPP
#define DOUBLE_STACK_HPP

class DoubleStack
{
public:
    explicit DoubleStack(int size = 0);

    [[nodiscard]] int get_m_top_stack0() const;
    [[nodiscard]] int get_m_top_stack1() const;

    void push0(const int& item);
    void push1(const int& item);
    int pop0();
    int pop1();

    void print_test();

private:
    int* m_array;
    bool pop_from_stack_0;  // Von welchem Stack wird geloescht
    int pop;    // Zahl die returned wird
    int m_allocation_size;  // Wie viel Speicher alloziert werden soll bei einer vergroeßerung des Arrays
    int m_size; // Groeße des Arrays

    /* Stack 0 kommt von links, Stack 1 von rechts */
    int m_top_stack0;  // Top von Stack 0
    int m_top_stack1;  // Top von Stack 1

    void resize();  // Interne Resize Methode um bei vollem Array mehr Speicher zu allozieren
};


#endif