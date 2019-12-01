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
    cout << "Video" << endl;
    this->print(cout);
}

void Video::write(ostream &os) const{
    os << "Video\n";
    os << getObjectName() << endl;
    os << getFilePath() << endl;
    os << getDuration() << endl;
}

void Video::read(istream &is){
    string data;
    getline(is,data);
    setObjectName(data);
    getline(is,data);
    setFilePath(data);
    getline(is,data);
    duration = atoi(data.c_str());
}