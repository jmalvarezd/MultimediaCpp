//
// main.cpp
// Created on 21/10/2018
//

#include <string>
#include <iostream>
#include <memory>
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"
#include "manager.h"

using namespace std;

int main(int argc, const char* argv[])
{
    string sv1 = "test Video";
    string sv2 = "/cal/homes/jalvarez/inf224/resources/video1.mp4";

    string si1 = "test Photo";
    string si2 = "/cal/homes/jalvarez/inf224/resources/image1.png";

    Video * video = new Video(sv1,sv2,15);
    Photo * photo = new Photo(si1,si2,15.0,13.0);

    Multimedia ** tableau = new Multimedia * [10];
    unsigned int count = 0;

    tableau[count++] = video;
    tableau[count++] = photo;

    Film * film = new Film();
    int debug[4] = {1,2,3,4};
    film->setDurations(debug,4);
    film->printDurations();
    debug[3] = 5;
    film->printDurations();
    film->setDurations(debug,4);
    film->printDurations();

    //8e et 9e etapes
    Group * group = new Group("FirstGroup");
    shared_ptr<Multimedia> smartVideo (new Video(sv1,sv2,20));
    shared_ptr<Multimedia> smartPhoto (new Photo(si1,si2,20.0,20.0));
    group->push_back(smartVideo);
    group->push_back(smartPhoto);
    group->print(cout);
    group->pop_back();
    group->pop_back();
    cout << endl;
    //quand on sort de main, les pointeurs partagés sont automatiquement detruits

    //std::cout << "m: " << video << std::endl;
    return 0;
}
