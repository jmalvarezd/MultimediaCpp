#include "manager.h"

Manager::Manager()
{

}

Photo Manager::createPhoto(){
    shared_ptr<Photo> smartPhoto();
    multimediaMap[smartPhoto->getObjectName()] = smartPhoto;
    return *(smartPhoto.get());
}
Photo Manager::createPhoto(string _objectName, string _filePath, float _latitude, float _longitude){
    shared_ptr<Photo> smartPhoto(string _objectName, string _filePath, float _latitude, float _longitude);
    multimediaMap[smartPhoto->getObjectName()] = smartPhoto;
    return *(smartPhoto.get());
}


Video Manager::createVideo(){
    shared_ptr<Video> smartPhoto(string _objectName, string _filePath, int _duration);
    multimediaMap[smartPhoto->getObjectName()] = smartPhoto;
    return *(smartPhoto.get());
}
Video Manager::createVideo(string _objectName, string _filePath, int _duration){
    shared_ptr<Video> smartVideo(string _objectName, string _filePath, int _duration);
    multimediaMap[smartVideo->getObjectName()] = smartVideo;
    return *(smartVideo.get());
}
