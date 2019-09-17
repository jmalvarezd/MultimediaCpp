#ifndef VIDEO_H
#define VIDEO_H


class Video:public Multimedia
{
private:
    int duration = 0;
public:
    Video();
    Video(int _duration);

    void setDuration(int _duration);
    int getDuration();
};

#endif // VIDEO_H
