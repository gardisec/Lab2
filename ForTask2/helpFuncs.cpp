#include "helpFuncs.h"

commands commandRequest(const string& request){
    if (request == "SETADD") return SETADD;
    if (request == "SETDEL") return SETDEL;
    if (request == "SET_AT") return SET_AT;
    if (request == "SETPRINT") return SETPRINT;

    throw runtime_error("This command isn't exist");
}

request getRequest(int argc, char *argv[]){
    request output;
    for (int i = 0; i < argc; ++i){
        if (static_cast<string>(argv[i]) == "--file") {
            //если после флага ничего нет || если после флага другой флаг
            if (i + 1 == argc || argv[i + 1][0] == '-') { //Если первое условие выполняется - второе не приведёт к ошибке т.к. не будет проверяться
                throw runtime_error(("Error: empty query.\n Specify what to execute"));
            }
            output.file = argv[i + 1];
            continue;
        }
        if (static_cast<string>(argv[i]) == "--query") {
            if (i + 1 == argc || argv[i + 1][0] == '-') { //если после флага ничего нет || если после флага другой флаг
                throw runtime_error(("Error: empty query.\n Specify what to execute"));
            }
            output.query = splitToArr(argv[i + 1]);
        }
    }
    return output;
}

void fileData :: getInfo(const string &input) {
    arr<string> split;
    split = splitToArr(input, ';');
    if(split.size != 2) {
        throw runtime_error("fileData error");
    }
    this->name = split[0];
    this->data = split[1];
}

bool isFileExist(const string& fileName){
    ifstream file(fileName);
    if(!file.is_open()) return false;
    file.close();
    return true;
}

bool isItNum(const string& str) {
    for (auto ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}