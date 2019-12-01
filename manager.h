#ifndef MANAGER_H
#define MANAGER_H

#include <memory>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;

const int PORT = 3332;

class Manager
{
private:
    map<string,shared_ptr<Multimedia>> multimediaMap;
    map<string,shared_ptr<Group>> groupMap;
public:
    Manager();
    
    Photo createPhoto(string _objectName, string _filePath, float _latitude, float _longitude);
    Video createVideo(string _objectName, string _filePath, int _duration);
    Film createFilm(string _objectName, string _filePath, int _duration, int * _durations, int _numberOfChapters);
    Group createGroup(string _groupName);

    bool displayMultimedia(string _objectName, ostream& os);
    bool playMultimedia(string _objectName);

    bool displayGroup(string _objectName, ostream& os);
    bool playGroup(string _objectName);

    bool listMultimedia(ostream& os);
    bool listGroup(ostream& os);

    bool display(string _objectName, ostream& os);
    bool play(string _objectName);
    bool list(ostream& os);
    bool help(ostream& os);


    bool processRequest(TCPConnection& cnx, const string& request, string& response);
};

#endif // MANAGER_H
