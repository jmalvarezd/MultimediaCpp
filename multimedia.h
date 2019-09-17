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
    Multimedia();
    Multimedia(string _objectName, string _filePath);

    void setObjectName(string _objectName);
    string getObjectName();

    void setFilePath(string _filePath);
    string getFilePath();

    void print(ostream& os);

    ~Multimedia();
};

#endif // MULTIMEDIA_H
