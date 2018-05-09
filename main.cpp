#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <math.h>
#include <iostream>

#include "Camera.h"
#include "Object.h"
#include "Space.h"
#include "Triangle.h"

Uint32 idozit(Uint32 ms, void *param) {
    SDL_Event ev;
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
    return ms;   /* ujabb varakozas */
}

int main(int argc, char *argv[]) {
    SDL_Event ev;
    SDL_Surface *screen;

    /* SDL inicializálása és ablak megnyitása */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    screen = SDL_SetVideoMode(200,200, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    SDL_WM_SetCaption("3D C++", "3D C++");

    Space space = Space();
    Object object = Object(Color(), Point());

    object.parts.push_back(Triangle(Point(0, 0, 0),Point(100,0,0),Point(100,0,100),Color(40)));
    object.parts.push_back(Triangle(Point(0, 0, 0),Point(100,0,100),Point(0,0,100),Color(40)));

    object.parts.push_back(Triangle(Point(0, 0, 0),Point(0,100,0),Point(0,100,100),Color(80)));
    object.parts.push_back(Triangle(Point(0, 0, 0),Point(0,100,100),Point(0,0,100),Color(80)));

    object.parts.push_back(Triangle(Point(0, 100, 0),Point(100,100,0),Point(100,100,100),Color(120)));
    object.parts.push_back(Triangle(Point(0, 100, 0),Point(100,100,100),Point(0,100,100),Color(120)));

    object.parts.push_back(Triangle(Point(100, 0, 0),Point(100,100,0),Point(100,100,100),Color(160)));
    object.parts.push_back(Triangle(Point(100, 0, 0),Point(100,100,100),Point(100,0,100),Color(160)));

    object.parts.push_back(Triangle(Point(0, 0, 0),Point(100,0,0),Point(100,100,0),Color(200)));
    object.parts.push_back(Triangle(Point(0, 0, 0),Point(100,100,0),Point(0,100,0),Color(200)));

    object.parts.push_back(Triangle(Point(0, 0, 100),Point(100,0,100),Point(100,100,100),Color(240)));
    object.parts.push_back(Triangle(Point(0, 0, 100),Point(100,100,100),Point(0,100,100),Color(240)));
    object.move(Point(-50,-50,-50));
    space.addObject(object);

    Camera cam(screen, space);

    cam.origo  = Point(  0, -300,  0 );
    cam.center = Point(  0,   30,  0 )+ cam.origo;
    cam.right  = Point( 10,    0,  0 )+ cam.center;
    cam.top    = Point(  0,    0, 10 )+ cam.center;

    cam.render(0,0,200,200);
    SDL_TimerID id = SDL_AddTimer(100, idozit, NULL);
    /* szokasos esemenyhurok */
    bool quit = false;
    bool act_event[8] = {0};
    while (!quit) {
        SDL_WaitEvent(&ev);
        switch (ev.type) {
            /* felhasznaloi esemeny: ilyeneket general az idozito fuggveny */
            case SDL_USEREVENT:
                    cam.rotate(0.1,0.1,0.1);
                    cam.render(0,0,200,200);

                if(act_event[0]){
                    cam.rotate(0,0,0.1,cam.origo);
                    cam.render(0,0,200,200);}
                if(act_event[1]){
                    cam.rotate(0.1,0,0,cam.origo);
                    cam.render(0,0,200,200);}
                if(act_event[2]){
                    cam.rotate(0,0,-0.1,cam.origo);
                    cam.render(0,0,200,200);}
                if(act_event[3]){
                    cam.rotate(-0.1,0,0,cam.origo);
                    cam.render(0,0,200,200);}

                if(act_event[4]){
                    cam.moveVector(cam.center-cam.right);
                    cam.render(0,0,200,200);}
                if(act_event[5]){
                    cam.move(cam.center);
                    cam.render(0,0,200,200);}
                if(act_event[6]){
                    cam.moveVector(cam.right-cam.center);
                    cam.render(0,0,200,200);}
                if(act_event[7]){
                    cam.move(cam.origo*2-cam.center);
                    cam.render(0,0,200,200);}
                break;
            case SDL_KEYDOWN:
                switch(ev.key.keysym.sym){
                case SDLK_LEFT:
                    act_event[0] = true;
                    break;
                case SDLK_UP:
                    act_event[1] = true;
                    break;
                case SDLK_RIGHT:
                    act_event[2] = true;
                    break;
                case SDLK_DOWN:
                    act_event[3] = true;
                    break;
                case SDLK_a:
                    act_event[4] = true;
                    break;
                case SDLK_w:
                    act_event[5] = true;
                    break;
                case SDLK_d:
                    act_event[6] = true;
                    break;
                case SDLK_s:
                    act_event[7] = true;
                    break;
                default:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch(ev.key.keysym.sym){
                case SDLK_LEFT:
                    act_event[0] = false;
                    break;
                case SDLK_UP:
                    act_event[1] = false;
                    break;
                case SDLK_RIGHT:
                    act_event[2] = false;
                    break;
                case SDLK_DOWN:
                    act_event[3] = false;
                    break;
                case SDLK_a:
                    act_event[4] = false;
                    break;
                case SDLK_w:
                    act_event[5] = false;
                    break;
                case SDLK_d:
                    act_event[6] = false;
                    break;
                case SDLK_s:
                    act_event[7] = false;
                    break;
                default:
                    break;
                }
                break;
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
    /* idozito torlese */
    SDL_RemoveTimer(id);

    SDL_Quit();

    return 0;
}
