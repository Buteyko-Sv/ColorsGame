#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <GL/glut.h>

class Rectangle
{
public:

    Rectangle();
    Rectangle(int id, int X, int Y, float R, float G, float B);
    Rectangle(int id, float R, float G, float B);

    void setColor(float R, float G, float B);

    float getRed() const;
    float getGreen() const;
    float getBlue() const;

    void setPosition(int X, int Y);
    int getX() const;
    int getY() const;
    int getId() const;
    int getFid() const;
    void setFid(int fid);
    bool inPlace() const;

    void drawingRec(int widthR, int heightR) const;

    bool operator== (const Rectangle &R2) const;
    bool operator!= (const Rectangle &R2) const;

    bool operator== (const int a) const;
    bool operator!= (const int a) const;

    bool operator< (const Rectangle &R2) const;
    bool operator> (const Rectangle &R2) const;

private:
    float red=1, green=1, blue=1;
    int posX=0, posY=0, id=0, fakeid=0;
};



#endif // RECTANGLE_H
