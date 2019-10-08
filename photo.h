#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"
#include <string>
#include <cstring>
#include <iostream>

class Photo : public Multimedia
{
private:
    float latitude = 0.0;
    float longitude = 0.0;
public:
    Photo();
    Photo(string _objectName, string _filePath, float _latitude, float _longitude)
        : Multimedia(_objectName, _filePath) {
        latitude = _latitude;
        longitude = _longitude;
    }

    void setLatitude(float _latitude);
    int getLatitude() const;

    void setLongitude(float _longitude);
    int getLongitude() const;

    void print(ostream &s) override;

    void play() override;

    ~Photo();
};

#endif // PHOTO_H
