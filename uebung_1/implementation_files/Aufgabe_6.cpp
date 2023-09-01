#include <string>
#include <iostream>
#include <stack>
#include "../header_files/Aufgaben.hpp"

std::string extract_num(const std::string& input, const int& start_index)
{
    std::string result;
    int index = start_index;
    while(std::isdigit(input[index]) || input[index] == '.')
    {
        result += input[index];
        index++;
    }
    return result;
}

bool test_infix_brackets(std::string input) {
    int bracket_counter = 0;

    for (const char element: input) {
        if (element == '(')
            bracket_counter++;
        else if (element == ')')
            bracket_counter--;

        if (bracket_counter < 0)
            return false;
    }

    return bracket_counter == 0;
}

std::string infix_to_postfix(const std::string& input)
{
    if (!test_infix_brackets(input))
    {
        std::cout << "Klammern falsch gesetzt" << std::endl;
        return input;
    }

    const char legal_operations[] = {'+', '-', '*', '/' };
    std::stack<char> operations;
    std::string result;

    for (int index = 0; index < input.size(); index++)
    {
        if (input[index] == '(' || input[index] == ' ')
            continue;

        std::string tmp;
        if (std::isdigit(input[index]))
        {
            tmp = extract_num(input, index);
            result += " " + tmp;
            index += int(tmp.size() - 1);
            continue;
        }

        bool legal_operation = false;
        for (const char operation : legal_operations)
            if (input[index] == operation)
            {
                tmp = extract_num(input, (index + 1));
                result += " " + tmp;
                index += int(tmp.size());
                operations.push(operation);
                legal_operation = true;
                break;
            }

        if (input[index] == ')')
        {
            while(!operations.empty())
            {
                result += " ";
                result += operations.top();
                operations.pop();
            }
        }

        else if (!legal_operation)
        {
            std::cout << "Der Ausdruck beinhaltet illegale Zeichen" << std::endl;
            exit(-1);
        }
    }

    return result;
}

double calculate_postfix(const std::string& input)
{
    std::stack<double> numbers;

    for (int index = 0; index < input.size(); index++)
    {
        if (input[index] == ' ')
            continue;

        if (std::isdigit(input[index]))
        {
            std::string tmp = extract_num(input, index);
            numbers.push(std::stod(tmp));
            index += int(tmp.size() - 1);
        }
        else
        {
            double first_number = numbers.top();
            numbers.pop();
            double second_number = numbers.top();
            numbers.pop();
            switch (input[index])
            {
            case '+':
                numbers.push(second_number + first_number);
                break;
            case '-':
                numbers.push(second_number - first_number);
                break;
            case '*':
                numbers.push(second_number * first_number);
                break;
            case'/':
                if (second_number == 0)
                {
                    std::cout << "Durch 0 wird nicht geteilt mein bester" << std::endl;
                    exit(-2);
                }
                numbers.push(second_number / first_number); // PROBLEM: Falls second_number == 0
                break;
            }
        }
    }
    return numbers.top();
}


void Aufgabe_6()
{
    std::string test_1 = "hallo123.456ioooooooo";
    double number_1 = std::stod(extract_num(test_1, 5));
    std::cout << number_1 << std::endl;

    std::string test_true = "((6+4)*3)-15";
    std::string test_false = "((6+4*3)-15";
    if (test_infix_brackets(test_true))
        std::cout << "test_true: true";
    else
        std::cout << "test_true: false";

    if (test_infix_brackets(test_false))
        std::cout << "test_false: true";
    else
        std::cout << "test_false: false";

    std::cout << std::endl << std::endl << "---------- jetzt infix -> postfix ----------" << std::endl << std::endl;

    std::string test_infix = "(45.6+7)-(4*6)";
    std::string postfix = infix_to_postfix(test_infix);
    std::cout << "infix: " << test_infix << std::endl;
    std::cout << "postfix: " << postfix << std::endl;
    std::cout << "ergebnis: " << calculate_postfix(postfix) << std::endl;
}