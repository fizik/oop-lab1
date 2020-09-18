#ifndef ROOM_H
#define ROOM_H
#include "lamp.h"

class LampCollection
{
public:
    static const float HEIGHT_MIN;
    static const float HEIGHT_DEFAULT;
    static const float HEIGHT_MAX;
    LampCollection(const int n, const int m);
    double getIlluminance(const float x, const float y, const float z, const float height = HEIGHT_DEFAULT) const;
    void setLamp(const int x, const int y, Lamp &lamp);
    Lamp getLamp(const int x, const int y) const;
    int getLength() const;
    int getWidth() const;
    ~LampCollection();
private:
    Lamp **collection_;
    int n_, m_;
};

#endif // ROOM_H
