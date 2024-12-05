#include "task3.h"

Set intersection(const Set& a, const Set& b) {
    Set result;
    for (size_t i = 0; i < a.bucketCount; ++i) {
        auto node = a.buckets[i].first;
        while (node != nullptr) {
            if (b.at(node->value)) { // если элемент есть
                result.insert(node->value);
            }
            node = node->next;
        }
    }
    return result;
}

void task3() {
    arr<string> input;
    input.push_back("1_2_3");
    input.push_back("2_3_4");
    input.push_back("5_6");
    input.push_back("3_4_5");

    arr<Set> subsets(input.size);
    for (size_t i = 0; i < input.getSize(); ++i) {
        subsets[i] = setFromStr(input[i]);
    }

    Pair maxPair = {to_string(-1),to_string(-1)};
    size_t interSize = 0;
    Set elements;
    for (size_t i = 0; i < subsets.size; ++i) {
        for (size_t j = i + 1; j < subsets.size; ++j) {
            Set common = intersection(subsets[i], subsets[j]);

            if (common.pairCount >= interSize) {
                interSize = common.pairCount;
                maxPair = {to_string(i), to_string(j)};
                elements = common;
            }
        }
    }

    // Вывод результата
    if (stoi(maxPair.key) != -1) {
        cout << "Sets with max intersection: " << endl;
        cout << subsets[stoi(maxPair.key)] << " " << subsets[stoi(maxPair.value)] << endl;
        cout << "Count of intersection: " << interSize << endl;
        cout << "Elements, which coincidence: " << elements << endl;
    } else {
        cout << "Empty" << endl;
    }
}
