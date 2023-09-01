#include <iostream>
#include <ranges>
#include "Aufgabe_5/header_files/BinarySearchTree.hpp"

int main() {
    BinarySearchTree tree;

    for (const int i : std::views::iota(1, 6))
        tree.add((i*5));

    tree.add(11);
    tree.add(13);
    tree.add(15);
    tree.add(9);

    std::cout << "postorder: ";
    tree.print_postorder();
    std::cout << std::endl;

    tree.exists(5) ? std::cout << "5 existiert" << std::endl : std::cout << "5 existiert nicht" << std::endl;
    tree.exists(20) ? std::cout << "20 existiert" << std::endl : std::cout << "20 existiert nicht" << std::endl;
    tree.exists(13) ? std::cout << "13 existiert" << std::endl : std::cout << "13 existiert nicht" << std::endl;
    tree.exists(3) ? std::cout << "3 existiert" << std::endl : std::cout << "3 existiert nicht" << std::endl;

    int tree_max = 0;
    tree.max(tree_max);
    std::cout << "max: " << tree_max << std::endl;

    std::cout << "levelorder: ";
    tree.print_niveau();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "postorder vor delete: " << std::endl;
    tree.print_postorder();
    std::cout << std::endl;


    tree.delete_node(13);
    std::cout << "postorder nach delete zahl 13:" << std::endl;
    tree.print_postorder();
    std::cout << std::endl;

    tree.delete_node(10);
    std::cout << "postorder nach delete Zahl 10:" << std::endl;
    tree.print_postorder();
    std::cout << std::endl;

    tree.delete_node(15);
    std::cout << "postorder nach delete Zahl 15:" << std::endl;
    tree.print_postorder();
    std::cout << std::endl;

    /*std::cout << "inorder vor delete" << std::endl;
    tree.print_inorder(tree.m_anker);
    std::cout << std::endl;

    tree.delete_node(15);
    std::cout << "inorder nach delete Zahl 15:" << std::endl;
    tree.print_inorder(tree.m_anker);
    std::cout << std::endl;*/

    return 0;
}
