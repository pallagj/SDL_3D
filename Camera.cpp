#include "Camera.h"
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "Triangle.h"

void Camera::rotate(float alfa, float beta, float gamma, Point p){
	top.rotate(alfa,beta,gamma,p);
	right.rotate(alfa,beta,gamma,p);
	center.rotate(alfa,beta,gamma,p);
	origo.rotate(alfa,beta,gamma,p);

}

void Camera::move(Point p){
	center += p-origo;
	top    += p-origo;
	right  += p-origo;
	origo  = p;
}

void Camera::move(float x, float y, float z){
	Point p(x,y,z);
	center += p-origo;
	top    += p-origo;
	right  += p-origo;
	origo  = p-origo;
}

void Camera::moveVector(Point p){
	center += p;
	top    += p;
	right  += p;
	origo  += p;
}

void Camera::moveVector(float x, float y, float z){
	Point p(x,y,z);
	center += p;
	top    += p;
	right  += p;
	origo  += p;
}


void Camera::render(int xfrom, int yfrom, int xto, int yto) const{
	int w = xto - xfrom;
	int h = yto - yfrom;
	for(int x = xfrom; x < xto;  x++){
		for(int y = yfrom; y < yto; y++){
			Color c = space.intersection(origo,  (right-center)*(2.0*(x-xfrom)/w - 1)+center - (top-center)*(2.0*(y-yfrom)/h - 1));//
			pixelRGBA(screen, x, y, c.r, c.g, c.b, 255);
        }
	}
	SDL_Flip(screen);
}

