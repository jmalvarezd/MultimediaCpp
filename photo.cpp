#include "photo.h"

Photo::Photo(float _latitude, float _longitude)
{
    latitude = _latitude;
    longitude = _longitude;
}

void Photo::setLatitude(float _latitude){
    latitude = _latitude;
}
int Photo::getLatitude(){
    return latitude;
}

void Photo::setLongitude(float _longitude){
    longitude = _longitude;
}
int Photo::getLongitude(){
    return longitude;
}
