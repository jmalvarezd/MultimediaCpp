#ifndef PHOTO_H
#define PHOTO_H


class Photo
{
private:
    float latitude = 0.0;
    float longitude = 0.0;
public:
    Photo();
    Photo(float _latitude, float _longitude);

    void setLatitude(float _latitude);
    int getLatitude();

    void setLongitude(float _longitude);
    int getLongitude();
};

#endif // PHOTO_H
