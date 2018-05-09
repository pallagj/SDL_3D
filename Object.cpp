#include "Triangle.h"
#include "Object.h"

void Object::move(Point a){
    for(Triangle& t : parts){
        t.move(a.x-origo.x, a.y-origo.y, a.z-origo.z);
    }
    origo=a;
}

void Object::move(float x, float y, float z){
    Point a(x,y,z);
    for(Triangle& t : parts){
        t.move(a);
    }
    origo=a;
}

void Object::moveVector(Point a){
    for(Triangle& t : parts){
        t.move(a.x, a.y, a.z);
    }
    origo += a;
}

void Object::moveVector(float x, float y, float z){
    Point a(x,y,z);
    for(Triangle& t : parts){
        t.move(x, y, z);
    }
    origo+=a;
}

void Object::rotate(float alpha, float beta, float gamma, Point center){
    for(Triangle& t : parts){
        t.rotate(alpha, beta, gamma, center);
    }
}
