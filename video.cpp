#include "video.h"

int Video::getDuration() const{
    return duration;
}

void Video::setDuration(int _duration){
    duration = _duration;
}

void Video::play(){
    system(("mpv " + getFilePath() +" &").c_str());    
}

void Video::print(ostream& s) {
    Multimedia::print(s);
    s << "Video: Duration: " << getDuration()  << " ";
}

Video::~Video(){
    cout << "destroying Video" << endl;
    this->print(cout);
}
