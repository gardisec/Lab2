#ifndef LAB2_SETCOMMANDS_H
#define LAB2_SETCOMMANDS_H

#include "helpFuncs.h"
#include "../Structures/Set.h"
#include "../Structures/arr.h"
#include <cctype>

using namespace std;

void printSet(const request& request);
void setAdd(const request& request);
void setDel(const request& request);
void setAt(const request& request);

#endif //LAB2_SETCOMMANDS_H
