#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"

class Photo
{
private:
    float latitude = 0.0;
    float longitude = 0.0;
public:
    Photo();
    Photo(string _objectName, string _filePath, float _latitude, float _longitude);

    void setLatitude(float _latitude);
    int getLatitude() const;

    void setLongitude(float _longitude);
    int getLongitude() const;
};

#endif // PHOTO_H
