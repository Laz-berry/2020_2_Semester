#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    unsigned long long int getPathSum (struct TreeNode* root);
    struct TreeNode* buildTree (std::string filename);
};

#endif