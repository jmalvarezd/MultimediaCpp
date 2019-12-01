#include "photo.h"

void Photo::setLatitude(float _latitude){
    latitude = _latitude;
}
int Photo::getLatitude() const{
    return latitude;
}

void Photo::setLongitude(float _longitude){
    longitude = _longitude;
}
int Photo::getLongitude() const{
    return longitude;
}

void Photo::play(){
    system(("imagej "+ getFilePath() +" &").c_str());
}

void Photo::print(ostream& s) {
    Multimedia::print(s);
    s<< "Photo: Latitude: " << getLatitude()  << " Longitude: "  << getLongitude() << " ";
}

Photo::~Photo(){
    cout << "Photo" << endl;
    this->print(cout);
}

void Photo::write(ostream &os) const{
    os << "Photo\n";
    os << getObjectName() << endl;
    os << getFilePath() << endl;
    os << getLatitude() << endl;
    os << getLongitude() << endl;
}

void Photo::read(istream &is){
    string data;
    getline(is,data);
    setObjectName(data);
    getline(is,data);
    setFilePath(data);
    getline(is,data);
    latitude = atof(data.c_str());
    getline(is,data);
    longitude = atof(data.c_str());
}
