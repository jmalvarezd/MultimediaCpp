#include "manager.h"

Manager::Manager()
{

}

Photo Manager::createPhoto(string _objectName, string _filePath, float _latitude, float _longitude){
    shared_ptr<Photo> smartPhoto(new Photo(_objectName, _filePath, _latitude, _longitude));
    multimediaMap[smartPhoto->getObjectName()] = smartPhoto;
    return *(smartPhoto.get());
}

Video Manager::createVideo(string _objectName, string _filePath, int _duration){
    shared_ptr<Video> smartVideo(new Video( _objectName,  _filePath,  _duration));
    multimediaMap[smartVideo->getObjectName()] = smartVideo;
    return *(smartVideo.get());
}

Film Manager::createFilm(string _objectName, string _filePath, int _duration, int * _durations, int _numberOfChapters){
    shared_ptr<Film> smartFilm(new Film(_objectName, _filePath, _duration, _durations, _numberOfChapters));
    multimediaMap[smartFilm->getObjectName()] = smartFilm;
    return *(smartFilm.get());
}

Group Manager::createGroup(string _groupName){
    shared_ptr<Group> smartGroup(new Group( _groupName));
    groupMap[smartGroup->getName()] = smartGroup;
    return *(smartGroup.get());
}

void Manager::displayMultimedia(string _objectName, ostream& os){
    multimediaMap[_objectName]->print(os);
}

bool Manager::processRequest(TCPConnection& cnx, const string& request, string& response)
{
  cerr << "\nRequest: '" << request << "'" << endl;

  // 1) pour decouper la requête:
  // on peut par exemple utiliser stringstream et getline()


  // 2) faire le traitement:
  // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
  // - sinon juste: TCPLock lock(cnx);


  // 3) retourner la reponse au client:
  // - pour l'instant ca retourne juste OK suivi de la requête
  // - pour retourner quelque chose de plus utile on peut appeler la methode print()
  //   des objets ou des groupes en lui passant en argument un stringstream
  // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
  //   ils servent à délimiter les messages entre le serveur et le client

  response = "OK: " + request;
  cerr << "response: " << response << endl;

  // renvoyer false si on veut clore la connexion avec le client
  return true;
}
