#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <string>
#include <iostream>

class Film : public Video
{
private:
    int * durations;
    int numberOfChapters;
    Multimedia ** chapters;
public:
    Film();

    Film(string _objectName, string _filePath, int _duration,
         int * _durations, int _numberOfChapters, Multimedia ** _chapters) :
        Video(_objectName, _filePath, _duration)
    {
        durations = _durations;
        numberOfChapters = _numberOfChapters;
        chapters = _chapters;
    }

    void setDurations(int * _durations, int _size);
    int * getDurations() const;
    void modifyDurations(int * _durations, int _size);

    void setNumberOfChapters(int _numberOfChapters);
    int getNumberOfChapters() const;

    void setChapters(Multimedia ** _chapters, int _size);
    Multimedia ** getChapters() const;

    void printDurations() const;

};

#endif // FILM_H
