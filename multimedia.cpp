#include "multimedia.h"

Multimedia::Multimedia(string _objectName, string _filePath){
    objectName = _objectName;
    filePath = _filePath;
}

void Multimedia::setObjectName(string _objectName){
    objectName = _objectName;
}
string Multimedia::getObjectName(){
    return objectName;
}

void Multimedia::setFilePath(string _filePath){
    filePath = _filePath;
}
string Multimedia::getFilePath(){
    return filePath;
}

void Multimedia::print(ostream& os){
    os << "name: " << objectName << " filePath: " << filePath << endl;
}


