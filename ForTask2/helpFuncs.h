#ifndef LAB2_HELPFUNCS_H
#define LAB2_HELPFUNCS_H


#include <fstream>
#include "../Structures/arr.h"
using namespace std;

struct request{
    arr<string> query;
    string file;
};

enum commands{
    SETADD, SETDEL, SET_AT, SETPRINT
};

struct fileData{
    string name;
    string data;

    fileData () = default;
    fileData (string n, string d) : name(n), data(d) {};

    void getInfo(const string &input);
};

bool isFileExist(const string& fileName);
request getRequest(int argc, char *argv[] );
commands commandRequest(const string& request);
bool isItNum(const string& str);

#endif //LAB2_HELPFUNCS_H
