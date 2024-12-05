#include "task2.h"

int main(int argc, char *argv[]) {
    try {
        request request = getRequest(argc, argv);
        if (argc == 1){
            throw runtime_error("Nothing arguments.");
        }
        if (request.query.size == 0){
            throw runtime_error("Query of request is empty");
        }
        if (!isFileExist(request.file) || request.file.empty()) {
            //проверяем доступ указанного файла/указан ли файл
            throw runtime_error("Incorrect file name, you must create file");
        }

                switch (commandRequest(request.query[0])) {
                    case SETADD:
                        setAdd(request);
                        break;
                    case SETDEL:
                        setDel(request);
                        break;
                    case SET_AT:
                        setAt(request);
                        break;
                    case SETPRINT:
                        printSet(request);
                        break;
                    default:
                        throw runtime_error("Invalid set command");
                }
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
        return -1;
    }
}