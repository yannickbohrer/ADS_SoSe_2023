#include <iostream>
#include <queue>

#include "../header_files/BinarySearchTree.hpp"

void BinarySearchTree::m_add(const int& key, TreeNode* parent)
{
    auto* new_entry = new TreeNode(key);

    if (!m_anker)
    {
        m_anker = new_entry;
        return;
    }

    if (key == parent->key) // doppelte Eintraege werden nicht gespeichert
        return;

    if (key < parent->key)
    {
        if (parent->left)
            m_add(key, parent->left);
        else
        {
            parent->left = new_entry;
            return;
        }
    }

    if (key > parent->key)
    {
        if (parent->right)
            m_add(key, parent->right);
        else
        {
            parent->right = new_entry;
            return;
        }
    }
}

TreeNode* BinarySearchTree::m_search_helper(const int _key, TreeNode* node) const
{
    if (!node)
        return nullptr;
    if (node->key == _key)
        return node;
    if (node->key > _key)
        return m_search_helper(_key, node->left);
    if (node->key < _key)
        return m_search_helper(_key, node->right);
}

TreeNode* BinarySearchTree::m_search(const int& key) const
{
    if (!m_anker)
        return nullptr;

    // recursive solution
    // return m_search_helper(key, m_anker);

    TreeNode* node = m_anker;
    while(node && node->key != key)
    {
        if (key < node->key)
            node = node->left;
        else if (key > node->key)
            node = node->right;
    }
    return node;
}

void BinarySearchTree::m_print_postorder(TreeNode* node) const
{
    if (node->left)
        m_print_postorder(node->left);
    if (node->right)
        m_print_postorder(node->right);

    node != m_anker ? std::cout << node->key << ", " : std::cout << node->key << std::endl;
}

void BinarySearchTree::print_postorder() const
{
    if (!m_anker)
        return;

    m_print_postorder(m_anker);
}

void BinarySearchTree::print_niveau() const
{
    std::queue<TreeNode*> queue;
    TreeNode* node;

    if (m_anker)
    {
        queue.push(m_anker);
        while(!queue.empty())
        {
            node = queue.front();
            queue.pop();
            std::cout << node->key << " ";
            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
    }
}

TreeNode* BinarySearchTree::m_find_parent(TreeNode* node, const int key) const
{
    if (!node)
        return nullptr;

    if (key < node->key)
    {
        if (node->left->key == key)
            return node;
        return m_find_parent(node->left, key);
    }

    if (key > node->key)
    {
        if (node->right->key == key)
            return node;
        return m_find_parent(node->right, key);
    }
}

bool BinarySearchTree::m_has_subtree(TreeNode* node) const
{
    return node->left || node->right;
}

bool BinarySearchTree::m_to_delete_is_left_of_parent(TreeNode* parent, TreeNode* to_delete, bool subtree_left, bool subtree_right)
{
    // to_delete hat genau einen Nachfolger links
    if (to_delete->left && !to_delete->right)
    {
        if (!subtree_left)
        {
            parent->left = to_delete->left;
            delete to_delete;
            return true;
        }
    }

    // to_delete hat genau einen Nachfolger rechts
    if (to_delete->right && !to_delete->left)
    {
        if (!subtree_right)
        {
            parent->left = to_delete->left;
            delete to_delete;
            return true;
        }
    }

    // to_delete hat zwei Nachfolger
    TreeNode* max_left_subtree = m_max(to_delete->left);
    int max_value_left_subtree = max_left_subtree->key;
    delete_node(max_value_left_subtree);
    parent->right = new TreeNode(max_value_left_subtree);parent->left->left = to_delete->left;
    parent->left->right = to_delete->right;
    delete to_delete;
    return true;
}

bool BinarySearchTree::m_to_delete_is_right_of_parent(TreeNode* parent, TreeNode* to_delete, bool subtree_left, bool subtree_right)
{
    // to_delete hat genau einen Nachfolger links
    if (to_delete->left && !to_delete->right)
    {
        if (!subtree_left)
        {
            parent->left = to_delete->left;
            delete to_delete;
            return true;
        }
    }

    // to_delete hat genau einen Nachfolger rechts
    if (to_delete->right && !to_delete->left)
    {
        if (!subtree_right)
        {
            parent->left = to_delete->left;
            delete to_delete;
            return true;
        }
    }

    // to_delete hat zwei Nachfolger
    TreeNode* max_left_subtree = m_max(to_delete->left);
    int max_value_left_subtree = max_left_subtree->key;
    delete_node(max_value_left_subtree);
    parent->right = new TreeNode(max_value_left_subtree);
    parent->right->left = to_delete->left;
    parent->right->right = to_delete->right;
    delete to_delete;
    return true;
}

bool BinarySearchTree::delete_node(const int& key)
{
    TreeNode* to_delete = m_search(key);
    if (!to_delete)
        return false;

    TreeNode* parent = m_find_parent(m_anker, key);

    if (!to_delete->left && !to_delete->right)
    {
        if (parent->left == to_delete)
        {
            delete to_delete;
            parent->left = nullptr;
            return true;
        }

        if (parent->right == to_delete)
        {
            delete to_delete;
            parent->right = nullptr;
            return true;
        }
    }

    bool subtree_left = false,
         subtree_right = false;

    if (to_delete->left->left || to_delete->left->right ||
        to_delete->right->left || to_delete->right->right)
    {
        if (to_delete->left)
            subtree_left = m_has_subtree(to_delete->left);
        if (to_delete->right)
            subtree_right = m_has_subtree(to_delete->right);
    }

    if (parent->left == to_delete)
        return m_to_delete_is_left_of_parent(parent, to_delete, subtree_left, subtree_right);

    return m_to_delete_is_right_of_parent(parent, to_delete, subtree_left, subtree_right);
}

TreeNode* BinarySearchTree::m_max(TreeNode* node) const
{
    if (node->right)
        return m_max(node->right);
    return node;
}

// zum testen
void BinarySearchTree::print_inorder(TreeNode* node) const
{
    if (node->left)
        print_inorder(node->left);
    std::cout << node->key;
    if (node != m_max(m_anker))
        std::cout << ", ";
    if (node->right)
        print_inorder(node->right);
}