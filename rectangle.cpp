#include "rectangle.h"

Rectangle :: Rectangle(){};
Rectangle :: Rectangle(int id, int X, int Y, float R, float G, float B)
{
    this->id=id;
    this->posX=X;
    this->posY=Y;
    this->red=R;
    this->green=G;
    this->blue=B;
}

Rectangle :: Rectangle(int id, float R, float G, float B)
{
    this->id=id;
    this->red=R;
    this->green=G;
    this->blue=B;
}

void Rectangle :: setColor(float R, float G, float B)
{
    this->red=R;
    this->green=G;
    this->blue=B;
}
float Rectangle :: getRed() const
{
    return this->red;
}
float Rectangle :: getGreen() const
{
    return this->green;
}
float Rectangle :: getBlue() const
{
    return this->blue;
}

void Rectangle :: setPosition(int X, int Y)
{
    this->posX=X;
    this->posY=Y;
}
int Rectangle :: getX() const
{
    return this->posX;
}
int Rectangle :: getY() const
{
    return this->posY;
}

int Rectangle :: getId() const
{
    return this->id;
}

int Rectangle :: getFid() const
{
    return this->fakeid;
}

void Rectangle :: setFid(int fid)
{
    this->fakeid=fid;
}

bool Rectangle :: inPlace() const
{
    return (this->getFid()==this->getId());
}

void Rectangle :: drawingRec(int widthR, int heightR) const
{
    glColor3f(this->getRed(), this->getGreen(), this->getBlue());
    glBegin(GL_QUADS);

    glVertex2f(this->getX(), this->getY());
    glVertex2f(this->getX()+widthR, this->getY());
    glVertex2f(this->getX()+widthR, this->getY()+heightR);
    glVertex2f(this->getX(), this->getY()+heightR);

    glEnd();
}

bool Rectangle :: operator== (const Rectangle &R2) const
{
    return (this->getFid()==R2.getFid());
}

bool Rectangle :: operator!= (const Rectangle &R2) const
{
    return !(this->getX()==R2.getX() && this->getY()==R2.getY() && this->getRed()==R2.getRed() && this->getGreen()==R2.getGreen() && this->getBlue()==R2.getBlue());
}

bool Rectangle :: operator== (const int a) const
{
    return (this->getFid()==a);
}
bool Rectangle :: operator!= (const int a) const
{
    return !(this->getFid()==a);
}

bool Rectangle :: operator< (const Rectangle &R2) const
{
    return (this->getFid() < R2.getFid());
}
bool Rectangle :: operator> (const Rectangle &R2) const
{
    return (this->getFid() > R2.getFid());
}
