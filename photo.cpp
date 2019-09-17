#include "photo.h"

Photo::Photo(string _objectName, string _filePath, float _latitude, float _longitude) :
    Multimedia(_objectName, _filePath)
{
    latitude = _latitude;
    longitude = _longitude;
}

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
