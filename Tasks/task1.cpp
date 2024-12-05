#include "task1.h"


int polskMethod(const string& line) {
    Stack<int> currStack;

    istringstream stream(line);
    string sym;

    while (stream >> sym) {
        // Проверка: число или оператор
        if (isdigit(sym[0]) || (sym.size() > 1 && sym[0] == '-' && isdigit(sym[1]))) {
            // Это число (включая отрицательное)
            currStack.push(stoi(sym));
        } else {
            // Это оператор
            if (currStack.size < 2) {
                throw invalid_argument("Incorrect num of operands");
            }

            // Извлекаем два верхних числа из стека
            int b = currStack.top(); currStack.pop();
            int a = currStack.top(); currStack.pop();

            // Выполняем операцию
            if (sym == "+") {
                currStack.push(a + b);
            } else if (sym == "-") {
                currStack.push(a - b);
            } else if (sym == "*") {
                currStack.push(a * b);
            } else if (sym == "/") {
                if (b == 0) {
                    throw runtime_error("Division by zero");
                }
                currStack.push(a / b);
            } else {
                throw invalid_argument("Incorrect operator:  " + sym);
            }
        }
    }

    // После всех операций в стеке должен остаться ровно один элемент
    if (currStack.size != 1) {
        throw invalid_argument("Incorrect nums of operators and operands");
    }

    return currStack.top();
}

void task1() {
    try {
        string line;
        cout << "Input: ";
        getline(cin, line);

        int result = polskMethod(line);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}