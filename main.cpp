//
// main.cpp
// Created on 21/10/2018

#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"
#include "manager.h"
#include "tcpserver.h"

using namespace std;

int main(int argc, const char* argv[])
{
    /// Tests et exercices realises pendant les TP pour s'assurer du bon fonctionnement
    /// Pour les activer, il faut definir VERSION_1_0

    #ifdef VERSION_1_0
        string sv1 = "test Video";
        string sv2 = "resources/video1.mp4";

        string si1 = "test Photo";
        string si2 = "resources/image1.png";

        Video * video = new Video(sv1,sv2,15);
        Photo * photo = new Photo(si1,si2,15.0,13.0);

        Multimedia ** tableau = new Multimedia * [10];
        unsigned int count = 0;

        tableau[count++] = video;
        tableau[count++] = photo;

        Film * film = new Film();
        int debug[4] = {1,2,3,4};
        film->setDurations(debug,4);
        film->printDurations();
        debug[3] = 5;
        film->printDurations();
        film->setDurations(debug,4);
        film->printDurations();

        //8e et 9e etapes
        Group * group = new Group("FirstGroup");
        shared_ptr<Multimedia> smartVideo (new Video(sv1,sv2,20));
        shared_ptr<Multimedia> smartPhoto (new Photo(si1,si2,20.0,20.0));
        group->push_back(smartVideo);
        group->push_back(smartPhoto);
        group->print(cout);
        group->pop_back();
        group->pop_back();
        cout << endl;
        //quand on sort de main, les pointeurs partagés sont automatiquement detruits

        //10e etape
        Manager * myManager = new Manager();
        myManager->createPhoto(si1,si2,25.0,20.0);
        myManager->displayMultimedia(si1,cout);

    #endif

    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    Manager * base = new Manager();

    // ajoute les données à jouer
    // il est possible de les ajouter à la main, avec le code commenté

/*     base->createPhoto("testImage", "resources/image1.png",25.0,20.0);
    base->createVideo("testVideo", "resources/video1.mp4",10); */

    // il est aussi possible de lire un fichier avec la serialisation des données
    // (recommandé)
    base->readSerialization("Serialized.txt");

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*base, &Manager::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
      cerr << "Could not start Server on port " << PORT << endl;
      return 1;
    }

    return 0;
}
