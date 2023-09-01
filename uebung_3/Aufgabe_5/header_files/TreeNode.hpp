#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

class TreeNode
{
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int _key, TreeNode* left_child = nullptr, TreeNode* right_child = nullptr)
    {
        key = _key;
        left = left_child;
        right = right_child;
    }
};

#endif