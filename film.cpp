#include "film.h"

Film::Film(){
    numberOfChapters = 0;
}

void Film::setDurations(int * _durations, int _size){
    durations = new int[_size];
    for(int i = 0; i < _size; i++){
        durations[i] = _durations[i];
    }
    numberOfChapters = _size;
}

int * Film::getDurations() const{
    return durations;
}

//On fait une copie profonde du tableau durations
//sur un nouveau tableau "newDurations"
//Apres on fait une copie profonde du tableau
//_durations a la fin du newDurations
//A la fin on modifie durations
void Film::modifyDurations(int * _durations, int _size){
    int * newDurations = new int[numberOfChapters+_size];
    for(int i = 0; i < numberOfChapters; i++){
        newDurations[i] = durations[i];
    }
    for(int i = numberOfChapters; i < numberOfChapters+_size; i++){
        newDurations[i] = _durations[i];
    }
    durations = newDurations;
    numberOfChapters = _size;
};

//void Film::setChapters(Multimedia ** _chapters, int _size){
//    chapters = new Multimedia * [_size];
//    for(int i = 0; i < _size; i++){
//        chapters[i] = _chapters[i];
//    }
//    numberOfChapters = _size;
//};
//Multimedia ** Film::getChapters() const{
//    return chapters;
//};

void Film::printDurations() const{
    for(int i = 0; i < numberOfChapters; i++){
        cout <<"Chapter "<< i << " duration: " << durations[i] << " ";
    }
};

Film::~Film(){
    cout << "Deleting durations pointer"<< endl;
    delete[] durations;
}
