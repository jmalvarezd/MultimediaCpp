//
// main.cpp
// Created on 21/10/2018
//

#include <string>
#include <iostream>
#include "video.h"
#include "photo.h"

using namespace std;

int main(int argc, const char* argv[])
{
    string s1 = "test Image";
    string s2 = "/cal/homes/jalvarez/inf224/resources/image1.png";
    Photo * m = new Photo(s1,s2,15.0, 13.0);
    m->print(cout);
    m->play();
    std::cout << "Hello brave new world" << std::endl;
    return 0;
}
