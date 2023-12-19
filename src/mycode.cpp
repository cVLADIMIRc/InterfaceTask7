#include "mycode.h"

void hello(istream &ist, ostream& ost) {
    std::string name;

    ist >> name;

    ost << "hello " << name;
}
