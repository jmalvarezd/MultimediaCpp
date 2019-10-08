#include "multimedia.h"

Multimedia::Multimedia(string _objectName, string _filePath)
{
    objectName = _objectName;
    filePath = _filePath;
}

void Multimedia::setObjectName(string _objectName){
    objectName = _objectName;
}
string Multimedia::getObjectName() const{
    return objectName;
}

void Multimedia::setFilePath(string _filePath){
    filePath = _filePath;
}
string Multimedia::getFilePath() const{
    return filePath;
}

void Multimedia::print(ostream& os){
    os << "name: " << objectName << " filePath: " << filePath << endl;
}

Multimedia::~Multimedia(){
    cout << "destroying Multimedia " << endl;
    this->print(cout);
}


