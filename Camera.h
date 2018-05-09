#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include "Space.h"
#include <SDL.h>
#include "Triangle.h"

class Camera{
    SDL_Surface* screen;
    Space &space;
public:
    Camera(SDL_Surface* screen, Space &space)
        :screen(screen), space(space){}

    Point center, top, right, origo;

    void rotate(float alfa, float beta, float gamma, Point p = Point());
    void move(Point p);
    void move(float x, float y, float z);
    void moveVector(Point p);
    void moveVector(float x, float y, float z);

    void render(int x, int y, int xto, int yto) const;
};

#endif // CAMERA_H_INCLUDED
