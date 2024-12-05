#include "SetCommands.h"

void printSet(const request& request) {//SETPRINT
    ifstream file(request.file);
    string tempLine;
    fileData setting;

    if (request.query.size == 1){
        while (getline(file, tempLine)) {
            if (tempLine == " " || tempLine.empty()){
                continue;
            }
            setting.getInfo(tempLine);
            Set currentValue = setFromStr(setting.data);
            cout << setting.name << ": " << currentValue << endl;
        }
    }
    else if (request.query.size == 2) { //SETPRINT name
        string name = request.query[1];
        bool isDone = false;
        while (getline(file, tempLine)){
            if (tempLine == " " || tempLine.empty()) {
                continue;
            }
            setting.getInfo(tempLine);
            if (setting.name == name){
                isDone = true;
                Set currentValue = setFromStr(setting.data);
                cout << setting.name << ": " << currentValue << endl;
            }
        }
        if (!isDone){
            throw runtime_error("Incorrect name");
        }
    }
    else {
        throw runtime_error("Incorrect query");
    }
    file.close();
}

void setAdd(const request& request) {//SETADD name value

    fstream file(request.file, ios::in);

    if (request.query.size != 3){
        throw runtime_error("Incorrect query");
    }
    string name = request.query[1];
    string value = request.query[2];
    if (!isItNum(value)) {
        throw runtime_error("Value should be number");
    }
    string tempLine;
    fileData setting;
    arr<string> buffer;
    bool isDone = false;
    while (getline(file, tempLine)){
        if (tempLine == " " || tempLine.empty()) {
            continue;
        }
        setting.getInfo(tempLine);
        if (setting.name == name && !isDone){
            isDone = true;
            Set currentValue = setFromStr(setting.data);
            currentValue.insert(stoi(value));
            tempLine = setting.name + ';' + strFromSet(currentValue);
            buffer.push_back(tempLine);
        }
        else {
            buffer.push_back(tempLine);
        }
    }
    if (!isDone){
        Set newVar;
        newVar.insert(stoi(value));
        tempLine = name + ';' + strFromSet(newVar);
        buffer.push_back(tempLine);
    }
    file.close();
    file.open(request.file, ios::out);
    for (auto i = 0; i < buffer.size;i++){
        file << buffer.data[i] << endl;
    }
    file.close();
}

void setDel(const request& request) { //SETDEL name value

    fstream file(request.file, ios::in);
    if (request.query.size != 3){
        throw runtime_error("Incorrect query");
    }
    string name = request.query[1];
    if (!isItNum(request.query[2])) {
        throw runtime_error("Value should be number");
    }
    int value = stoi(request.query[2]);
    string tempLine;
    fileData setting;
    arr<string> buffer;
    bool isDone = false;
    while (getline(file, tempLine)){
        if (tempLine == " " || tempLine.empty()) {
            continue;
        }
        setting.getInfo(tempLine);
        if (setting.name == name && !isDone){
            isDone = true;
            Set currentValue = setFromStr(setting.data);
            currentValue.del(value);
            tempLine = setting.name + ';' + strFromSet(currentValue);
            if (currentValue.pairCount != 0){
               buffer.push_back(tempLine);
            }
        }
        else {
            buffer.push_back(tempLine);
        }
    }
    file.close();

    if (!isDone){
        throw runtime_error("Incorrect name");
    } else {
        file.open(request.file, ios::out);

       for (auto i = 0; i < buffer.size; i++){
           file << buffer.data[i] << endl;
       }
        file.close();
    }
}
void setAt(const request& request) {//SET_AT name value

    ifstream file(request.file);
    if (request.query.size != 3) {
        throw runtime_error("Incorrect query");
    }
    string name = request.query[1];
    if (!isItNum(request.query[2])) {
        throw runtime_error("Value should be number");
    }
    int value = stoi(request.query[2]);
    string tempLine;
    fileData setting;
    bool isDone = false;
    while (getline(file, tempLine)){
        if (tempLine == " " || tempLine.empty()){
            continue;
        }
        setting.getInfo(tempLine);
        if (setting.name == name && !isDone){
            isDone = true;
            Set currentValue = setFromStr(setting.data);
            if (currentValue.at(value)){
                cout <<  value << " is in set " << name << endl;
            }
            else {
                cout << value << " isn't in set " << name << endl;
            }
        }
    }
    if (!isDone){
        throw runtime_error("Incorrect name");
    }
}