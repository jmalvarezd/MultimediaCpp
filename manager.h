#ifndef MANAGER_H
#define MANAGER_H

#include <memory>
#include <string>
#include <map>
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"

using namespace std;

class Manager
{
private:
    map<string,shared_ptr<Multimedia>> multimediaMap;
    map<string,shared_ptr<Group>> groupMap;
public:
    Manager();
};

#endif // MANAGER_H
