#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>


using namespace std;
class Multimedia
{
private:
    string objectName = "";
    string filePath = "";
public:
    Multimedia() {};
    Multimedia(string _objectName, string _filePath);

    virtual void setObjectName(string _objectName);
    virtual string getObjectName() const;

    virtual void setFilePath(string _filePath);
    virtual string getFilePath() const;

    virtual void print(ostream& os);

    virtual void play() {};

    virtual ~Multimedia();
};

#endif // MULTIMEDIA_H
