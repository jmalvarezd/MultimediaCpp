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
    cout << "destroying photo" << endl;
    this->print(cout);
}
