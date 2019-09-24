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
    string sv1 = "test Video";
    string sv2 = "/cal/homes/jalvarez/inf224/resources/video1.mp4";

    string si1 = "test Image";
    string si2 = "/cal/homes/jalvarez/inf224/resources/image1.png";

    Video * video = new Video(sv1,sv2,15);
    Photo * photo = new Photo(si1,si2,15.0,13.0);

    Multimedia ** tableau = new Multimedia * [10];
    unsigned int count = 0;

    tableau[count++] = video;
    tableau[count++] = photo;

    for (int i = 0; i < 2; i++){
        tableau[i]->play();
    };

    std::cout << "m: " << video << std::endl;
    return 0;
}
