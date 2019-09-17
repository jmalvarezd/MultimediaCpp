#include "multimedia.h"

Multimedia::Multimedia();

Multimedia::Multimedia(string _objectName, string _filePath){
    objectName = _objectName;
    filePath = _filePath;
}

void setObjectName(string _objectName){
    objectName = _objectName;
}
string getObjectName(){
    return objectName;
}

void setFilePath(string _filePath){
    filePath = _filePath;
}
string getFilePath(){
    return filePath;
}

void print(ostream& os){
    os << "name: " << objectName << " filePath: " << filePath;
}

~Multimedia(){}

