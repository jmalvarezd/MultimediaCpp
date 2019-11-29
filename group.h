#ifndef GROUP_H
#define GROUP_H

#include "multimedia.h"
#include <memory>
#include <list>

class Group : public list< shared_ptr< Multimedia > >
{
private:
    string groupName = "";
public:
    Group( string _groupName ):
        list< shared_ptr<Multimedia> >()
    {
        groupName = _groupName;
    };
    string getName() const;
    void setName(string _name);

    void print(ostream &s){
        s << groupName << endl;
        for (Group :: iterator it = this-> begin(); it != this->end(); it++){
            (*it)->print(s);
        }
    }

    void play(){
        for (Group :: iterator it = this-> begin(); it != this->end(); it++){
            (*it)->play();
        }
    }
};

#endif // GROUPE_H
