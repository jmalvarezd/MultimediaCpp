#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H


class Multimedia
{
private:
    string objectName = "";
    string filePath = "";
public:
    Multimedia();
    Multimedia(string _objectName, string _filePath);

    void setObjectName(string _objectName);
    string getObjectName();

    void setFilePath(string _filePath);
    string getFilePath();

    ~Multimedia();
};

#endif // MULTIMEDIA_H
