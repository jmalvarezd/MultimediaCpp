//
// main.cpp
// Created on 21/10/2018
//

#include <string>
#include <iostream>
#include "video.h"

using namespace std;

int main(int argc, const char* argv[])
{
    string s1 = "asd";
    string s2 = "abc";
    Video * m = new Video(s1,s2,10);
    m->print(cout);
    std::cout << "Hello brave new world" << std::endl;
    return 0;
}
