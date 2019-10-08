#ifndef GROUP_H
#define GROUP_H

#include "multimedia.h"
#include <list>

class Group : public list< Multimedia * >
{
private:
    string groupName = "";
public:
    Group( string _groupName ):
        list<Multimedia *>()
    {
        groupName = _groupName;
    };
    string getName();
    void setName();

    void print(ostream &s){
        s << groupName << endl;
        for (Group :: iterator it = this-> begin(); it != this->end(); it++){
            (*it)->print(s);
        }
    }
};

#endif // GROUPE_H
