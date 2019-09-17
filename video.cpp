#include "video.h"

Video::Video(string _objectName, string _filePath, int _duration) :
    Multimedia(_objectName, _filePath)
{
    duration = _duration;
}

int Video::getDuration(){
    return duration;
}

void Video::setDuration(int _duration){
    duration = _duration;
}

void Video::play(){
    system(c_str("mpv " + filePath +" &"));    // nom_du_fichier est le chemin complet
}
