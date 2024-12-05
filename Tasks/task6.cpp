#include "task6.h"

string intToRoman(int num) {
    hashMap romanMap;

    romanMap.insert("1000", "M");
    romanMap.insert("900", "CM");
    romanMap.insert("500", "D");
    romanMap.insert("400", "CD");
    romanMap.insert("100", "C");
    romanMap.insert("90", "XC");
    romanMap.insert("50", "L");
    romanMap.insert("40", "XL");
    romanMap.insert("10", "X");
    romanMap.insert("9", "IX");
    romanMap.insert("5", "V");
    romanMap.insert("4", "IV");
    romanMap.insert("1", "I");

    arr<int> keys;
    keys.push_back(1000);
    keys.push_back(900);
    keys.push_back(500);
    keys.push_back(400);
    keys.push_back(100);
    keys.push_back(90);
    keys.push_back(50);
    keys.push_back(40);
    keys.push_back(10);
    keys.push_back(9);
    keys.push_back(5);
    keys.push_back(4);
    keys.push_back(1);

    string result;

    for (size_t i = 0; i < keys.getSize(); ++i) {
        int value = keys[i];
        string romanSymbol = romanMap.Get(to_string(value)).value;

        while (num >= value) {
            result += romanSymbol;
            num -= value;
        }
    }

    return result;
}

void task6() {
    int number;
    cout << "Input: ";
    cin >> number;

    if (number <= 0 || number > 3999) { // Ограничение римской системы
        cout << "the number must not exceed 3999" << endl;
        return;
    }

    string roman = intToRoman(number);
    cout << "Romans: " << roman << endl;

    return;
}