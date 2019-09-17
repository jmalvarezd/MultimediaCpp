#include "video.h"

int Video::getDuration(){
    return duration;
}

void Video::setDuration(int _duration){
    duration = _duration;
}

void Video::play(){
    system(("mpv " + getFilePath() +" &").c_str());    // nom_du_fichier est le chemin complet
}
