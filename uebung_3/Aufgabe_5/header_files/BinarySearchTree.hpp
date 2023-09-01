#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "TreeNode.hpp"
#include <stack>


class BinarySearchTree
{
public:
    // Konstruktor
    BinarySearchTree() : m_anker(nullptr) {};
    // Hier gehoert eigentlich ein Copy Konstruktor hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)

    // Dekonstruktor
    ~BinarySearchTree()
    {
        std::stack<TreeNode*> nodes;
        nodes.push(m_anker);
        while (!nodes.empty())
        {
            TreeNode* node = nodes.top();
            nodes.pop();

            if (node == nullptr) continue;

            nodes.push(node->left);
            nodes.push(node->right);

            delete node;
        }
    }

    // Fuegt einen Knoten zum Baum hinzu
    void add(const int& key) { m_add(key, m_anker); }

    // Guckt ob ein key im Baum vorhanden ist
    bool exists(const int& key) const { return m_search(key) != nullptr; }

    // 3. Rekursive Methode die alle Knoten in Postorder ausgibt
    void print_postorder() const;

    // 4. Iterative Methode die alle Knoten Niveauweise ausgibt
    void print_niveau() const;

    // 5. Loescht einen beliebigen Knoten im BST und setzt an dessen Stelle das Maximum vom linken Teilbaum
    bool delete_node(const int& key);

    // Gibt den maximalen Key Wert zurueck
    bool max(int& max) {
        if (m_anker == nullptr) return false;
        else
        {
            max = m_max(m_anker)->key;
            return true;
        }
    }

    void print_inorder(TreeNode* node) const;

    // Hier gehoert eigentlich ein Assignment (copy) Operator hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)
private:
    TreeNode* m_anker;

    // 1. Fuegt einen Knoten als Nachfolger eines gegeben Knoten ein
    void m_add(const int& key, TreeNode* parent);

    // 2. Sucht einen Knoten im BST
    TreeNode* m_search(const int& key) const;

    // Hilfsmethode fuer 3.
    void m_print_postorder(TreeNode* node) const;

    // 6. Recursive Methode die den maximalen Knoten zurueck gibt
    TreeNode* m_max(TreeNode* node) const;

    // custom helpers
    TreeNode* m_search_helper(int _key, TreeNode* node) const;

    TreeNode* m_find_parent(TreeNode* node, int key) const;
    bool m_has_subtree(TreeNode* node) const;
    bool m_to_delete_is_left_of_parent(TreeNode* parent, TreeNode* to_delete, bool subtree_left, bool subtree_right);
    bool m_to_delete_is_right_of_parent(TreeNode* parent, TreeNode* to_delete, bool subtree_left, bool subtree_right);

};
#endif