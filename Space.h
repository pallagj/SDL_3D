#ifndef SPACE_H_INCLUDED
#define SPACE_H_INCLUDED

#include <vector>
#include "Object.h"
#include "Triangle.h"

class Space{
    std::vector<Object> objects;
public:
    Object& operator[] (int i);
    Object  operator[] (int i) const;
    int getSize() const;
    void addObject(Object obj);
    void removeObject(int i);
    Color intersection(Point A, Point B) const;
};


#endif // SPACE_H_INCLUDED
