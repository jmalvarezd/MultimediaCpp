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
