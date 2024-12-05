#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
struct Stack{
    Node<T>* head;
    size_t size;

    Stack() : head(nullptr), size(0) {}

    friend ostream& operator<<(ostream& os, const Stack<T>& st) {
        auto curr = st.head;
        while (curr != nullptr){
            os << "[" << curr->value << "]";
            if (curr->next != nullptr) {
                os << " -> ";
            }
            curr = curr->next;
        }
        return os;
    }

    void push(T val);
    void pop();
    T top();
    void out();
    void clear();

};


template struct Stack<int>;
template struct Stack<char>;
template struct Stack<string>;


Stack<string> splitToStack(const string &input, char delimiter = ' ');
string unSplitStack(const Stack<string> &input, char delimiter = ' ');

#endif // STACK_H
