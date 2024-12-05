#include "task5.h"


void TreeNode::insert(int value) {
    if (value < this->value) {
        if (this->left == nullptr) {
            this->left = new TreeNode(value);
        } else {
            this->left->insert(value);
        }
    } else if (value > this->value) {
        if (this->right == nullptr) {
            this->right = new TreeNode(value);
        } else {
            this->right->insert(value);
        }
    }
}

void TreeNode::findForks(arr<int>& forks) const {
    if (this->left != nullptr && this->right != nullptr) {
        forks.push_back(this->value);
    }
    if (this->left != nullptr) {
        this->left->findForks(forks);
    }
    if (this->right != nullptr) {
        this->right->findForks(forks);
    }
}

void bubbleSort(arr<int>& array) {
    size_t n = array.getSize();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void task5() {
    arr<int> sequence;
    int num;
    while (cin >> num && num != 0) {
        sequence.push_back(num);
    }

    TreeNode* root = nullptr;
    for (size_t i = 0; i < sequence.getSize(); ++i) {
        if (root == nullptr) {
            root = new TreeNode(sequence[i]);
        } else {
            root->insert(sequence[i]);
        }
    }

    arr<int> forks;
    if (root != nullptr) {
        root->findForks(forks);
    }

    bubbleSort(forks);
    for (size_t i = 0; i < forks.getSize(); ++i) {
        cout << forks[i] << " ";
    }
    cout << endl;

}