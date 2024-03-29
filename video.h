#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include <string>
#include <iostream>

class Video : public Multimedia
{
private:
    int duration = 0;
public:
    Video(){};

    Video(string _objectName, string _filePath, int _duration) :
        Multimedia(_objectName, _filePath)
    {
        duration = _duration;
    }

    void setDuration(int _duration);
    int getDuration() const;

    void print(ostream &s) override;

    void play() override;

    ~Video();

    void write(ostream &s) const;
    void read(istream &s);

};

#endif // VIDEO_H
