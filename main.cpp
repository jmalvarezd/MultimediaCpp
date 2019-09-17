//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "multimedia.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia * m = new Multimedia("hey", "path");
    m->print(cout);
    std::cout << "Hello brave new world" << std::endl;
    return 0;
}
