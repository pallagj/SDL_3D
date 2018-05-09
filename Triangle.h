#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include <math.h>
class Point{
public:
    float x, y, z;

    Point(float x=0, float y=0, float z=0) : x(x), y(y), z(z){}

    void rotate(float alpha, float beta, float gamma, Point origo=Point());
    Point rotated(float alpha, float beta, float gamma, Point origo=Point()) const;

    void operator+=(Point a){x+=a.x; y+=a.y; z+=a.z;};
    void operator-=(Point a){x-=a.x; y-=a.y; z-=a.z;};

    Point operator+(Point a) const {return Point(x+a.x, y+a.y, z+a.z);};
    Point operator-(Point a) const {return Point(x-a.x, y-a.y, z-a.z);};
    Point operator*(float a) const {return Point(a*x,   a*y,   a*z);};

    float absSquare() const { return x*x+y*y+z*z; }
    float abs() const { return sqrt(absSquare()); }
};

class Color{
public:
    int r, g, b;
    Color(int R, int G, int B){r=R; g=G;b=B;};
    Color(int rgb){r=rgb; g=rgb;b=rgb;}
    Color(){r=0; g=0; b=0;}
};

class Triangle{
public:
    Point A, B, C;
    Color color;
    Triangle(Point A, Point B, Point C, Color color): A(A), B(B), C(C), color(color){}

    void move(float x, float y, float z){A.x+=x; B.x+=x; C.x+=x; A.y+=y; B.y+=y; C.y+=y; A.z+=z; B.z+=z; C.z+=z;};
    void move(Point p){move(p.x, p.y, p.z);}
    Color getColor() const {return color;}
    void rotate(float alpha, float beta, float gamma, Point origo=Point());
    float intersection(Point p1, Point p2) const;
};

#endif // TRIANGLE_H_INCLUDED
