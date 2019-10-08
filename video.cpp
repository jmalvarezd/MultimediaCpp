#include "video.h"

int Video::getDuration() const{
    return duration;
}

void Video::setDuration(int _duration){
    duration = _duration;
}

void Video::play(){
    system(("mpv " + getFilePath() +" &").c_str());    // nom_du_fichier est le chemin complet
}

void Video::print(ostream& s) {
    Multimedia::print(s);
    s<< "Video: Duration: " << getDuration()  << endl;
}

Video::~Video(){
    cout << "destroying Video" << endl;
    this->print(cout);
}
