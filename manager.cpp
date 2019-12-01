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

bool Manager::displayMultimedia(string _objectName, ostream& os){
    if(multimediaMap.find(_objectName) == multimediaMap.end()){
        return false;
    }
    else{
        multimediaMap[_objectName]->print(os);
        return true;
    }
}

bool Manager::playMultimedia(string _objectName){
    if(multimediaMap.find(_objectName) == multimediaMap.end()){
        return false;
    }
    else{
        multimediaMap[_objectName]->play();
        return true;
    }
}

bool Manager::displayGroup(string _objectName, ostream& os){
    if(groupMap.find(_objectName) == groupMap.end()){
        return false;
    }
    else{
        groupMap[_objectName]->print(os);
        return true;
    }
}

bool Manager::playGroup(string _objectName){
    if(groupMap.find(_objectName) == groupMap.end()){
        return false;
    }
    else{
        groupMap[_objectName]->play();
        return true;
    }
}

bool Manager::listMultimedia(ostream& os){
    for (auto const& element : multimediaMap) {
        os << element.first << endl;
    }
    return true;
}
bool Manager::listGroup(ostream& os){
    for (auto const& element : groupMap) {
        os << element.first << endl;
    }
    return true;
}

/// Les quatre actions principales du serveur:

/// \fn display() : Cherche le Multimedia ou Groupe à partir de son nom dans les maps
/// et envoi sur le ostream os le titre et le nom du fichier
bool Manager::display(string _objectName, ostream& os){
    if(!(displayMultimedia(_objectName,os) || displayGroup(_objectName,os))){
        return false;
    }
    return true;
}

/// \fn play() : Joue un objet multimedia donné
/// à partir de son nom
bool Manager::play(string _objectName){
    if(!(playMultimedia(_objectName) || playGroup(_objectName))){
        return false;
    }
    return true;
}

/// \fn list() : Cherche les noms de tous les medias ajoutés aux maps
/// et envoi sur le ostream os leurs titres.
bool Manager::list(ostream& os){
    listMultimedia(os);
    listGroup(os);
    return true;
}

/// \fn help() : Envoi sur le ostream os une petite explication pour
/// utiliser correctement la Telecommande.
bool Manager::help(ostream& os){
    os << "Welcome to the Juan-Alvarez Set-Top Box!" << endl;
    os << "To use this controller, please write the media to play in the textbox labeled 'Target Media' at the bottom." << endl;
    os << "If you dont know which Medias are included, press the 'List' button at the top of the interface." << endl;
    os << "After you write a Target Media, please press 'Find' to receive it's location, or 'Play' to play it." << endl;

    return true;
}

bool Manager::processRequest(TCPConnection& cnx, const string& request, string& response)
{
  cerr << "\nRequest: '" << request << "'" << endl;

  // 1) pour decouper la requête:
  // on peut par exemple utiliser stringstream et getline()
  stringstream str;
  str << request;
  string action, target;
  str >> action;
  str >> target;

  // 2) faire le traitement:
  // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
  // - sinon juste: TCPLock lock(cnx);
  TCPLock lock(cnx);

  // 3) retourner la reponse au client:
  // - pour l'instant ca retourne juste OK suivi de la requête
  // - pour retourner quelque chose de plus utile on peut appeler la methode print()
  //   des objets ou des groupes en lui passant en argument un stringstream
  // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
  //   ils servent à délimiter les messages entre le serveur et le client
  stringstream answer;

  if(action == "find"){
      display(target,answer);
  }
  else if(action == "play"){
      if(play(target)){
          answer << "Playing: " << target << endl;
      }
  }
  else if(action == "list"){
      list(answer);
  }
  else if (action == "help"){
      help(answer);
  }

  if(answer.str().empty()){
      response = "404 COULD NOT FIND \n";
  }
  else{
      response = "OK: " + answer.str() + "\n";
  }
  cerr << "Response: " << response << endl;

  // renvoyer false si on veut clore la connexion avec le client
  return true;
}

/// Fonctions à utiliser pour la serialisation
/// writeSerialization ouvre un fichier et ecrit touts les medias
bool Manager::writeSerialization(const string &outFile){
    ofstream outStream(outFile);
    if(outStream){
        for(auto element = multimediaMap.begin(); element != multimediaMap.end(); element++){
            element->second->write(outStream);
        }
        outStream.close();
        return true;
    }
    else{
        cout << "Could not open file";
        return false;
    }
    return false;
}

/// readSerialization ouvre un ficihier et lit tous les medias
/// fonctionne seulement pour les phots et les videos
bool Manager::readSerialization(const string &inFile){
    ifstream inStream(inFile);
    if(inStream){
        while(inStream){
            string className;
            getline(inStream,className);
            if(className.compare("Photo") == 0){
                saveSerializedPhoto(inStream);
            }
            else{
                saveSerializedVideo(inStream);
            }
        }
        return true;
    }
    else{
        cout << "Could not open file";
        return false;
    }
    return false;
}

void Manager::saveSerializedPhoto(istream &is){
    string name, path;
    getline(is,name);
    getline(is,path);

    string data;
    float lat, lon;
    getline(is,data);
    lat = atof(data.c_str());
    getline(is,data);
    lon = atof(data.c_str());
    createPhoto(name,path,lat,lon);

}

void Manager::saveSerializedVideo(istream &is){
    string name, path;
    getline(is,name);
    getline(is,path);

    string data;
    int len;
    getline(is,data);
    len = atoi(data.c_str());
    createVideo(name,path,len);

}
