#include "video.h"

Video::Video(int _duration)
{
    duration = _duration;
}

int Video::getDuration(){
    return duration;
}

void Video::setDuration(int _duration){
    duration = _duration;
}
