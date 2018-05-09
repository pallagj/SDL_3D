#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <vector>
#include "Triangle.h"


class Object{
    Color color;
    Point origo;
public:
    std::vector<Triangle> parts;

    Object( Color c, Point o ) : color(c), origo(o){ }

    void move(Point a);
    void move(float x, float y, float z);
    void moveVector(Point a);
    void moveVector(float x, float y, float z);
    void rotate(float alpha, float beta, float gamma, Point center);

    void setColor(Color c){color=c;};
    Color getColor()const {return color;};
};

#endif // OBJECT_H_INCLUDED
