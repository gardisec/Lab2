#ifndef LAB2_TASK5_H
#define LAB2_TASK5_H

#include "../Structures/arr.h"
#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    void insert(int value);
    void findForks(arr<int>& forks) const;
};

void task5();
#endif
