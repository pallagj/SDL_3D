#include "Triangle.h"
#include <math.h>

void Triangle::rotate(float alpha, float beta, float gamma, Point origo){
    A.rotate(alpha, beta, gamma, origo);
    B.rotate(alpha, beta, gamma, origo);
    C.rotate(alpha, beta, gamma, origo);
}

void rotateTwoCoords(float& x, float& y, float alpha){
    float x0=x, y0=y;
    x=x0*cos(alpha)-y0*sin(alpha);
    y=y0*cos(alpha)+x0*sin(alpha);
}

void Point::rotate(float alpha, float beta, float gamma, Point origo){
    float x0=x-origo.x;
    float y0=y-origo.y;
    float z0=z-origo.z;
    rotateTwoCoords(y0, z0, alpha);
    rotateTwoCoords(x0, z0, beta);
    rotateTwoCoords(x0, y0, gamma);
    x=x0+origo.x;
    y=y0+origo.y;
    z=z0+origo.z;
}

Point Point::rotated(float alpha, float beta, float gamma, Point origo) const{
    Point b = *this;
    b.rotate(alpha, beta, gamma, origo);
    return b;
}

bool inIterval(float start, float x, float end){ return start <= x && x <= end; }

float Triangle::intersection(Point D, Point E) const{
    Point BmA = B-A;
    Point CmB = C-B;
    Point DmE = D-E;
    Point DmA = D-A;
    float a=BmA.x, d=CmB.x, g=DmE.x, j=DmA.x;
    float b=BmA.y, e=CmB.y, h=DmE.y, k=DmA.y;
    float c=BmA.z, f=CmB.z, i=DmE.z, l=DmA.z;

    float x, p, q;

    if(a != 0){
        x=a;
        a=1;   d/=x;   g/=x;   j/=x;
        x=b;
        b-=a*x; e-=d*x; h-=g*x; k-=j*x;
        x=c;
        c-=a*x; f-=d*x; i-=g*x; l-=j*x;
        if(e!=0){
            x=e;
            e=1;   h/=x;   k/=x;
            x=f;
            f-=e*x; i-=h*x; l-=k*x;
            if(i==0) return -1;
            l/=i;
            q = k-l*h; p = j-g*l-d*q;
            float d = (C-B).absSquare();
            if(0<=p && p<=1 && 0<=q && q<=1 && d*p*p >= d*q*q)
                return l;
        }else if(f!=0){
            x=f;
            f=1;   i/=x;   l/=x;
            x=e;
            e-=f*x; h-=i*x; k-=l*x;
            if(h==0) return -1;
            k/=h;
            q = l-i*k; p = j-g*k-d*q;
            float d = (C-B).absSquare();
            if(0<=p && p<=1 && 0<=q && q<=1 && d*p*p >= d*q*q)
                return k;
        }
    }else if(b!=0){
        x=b;
        b=1;   e/=x;   h/=x;   k/=x;
        x=a;
        a-=b*x; d-=e*x; g-=h*x; j-=k*x;
        x=c;
        c-=b*x; f-=e*x; i-=h*x; l-=k*x;
        if(d!=0){
            x=d;
            d=1;   g/=x;   j/=x;
            x=f;
            f-=d*x; i-=g*x; l-=j*x;
            if(i==0) return -1;
            l/=i;
            q = j-g*l; p = k-h*l-e*q;
            float d = (C-B).absSquare();
            if(0<=p && p<=1 && 0<=q && q<=1 && d*p*p >= d*q*q)
                return l;
        }else if(f!=0){
            x=f;
            f=1;   i/=x;   l/=x;
            x=d;
            d-=f*x; g-=i*x; j-=l*x;
            if(g==0) return -1;
            j/=g;
            q = l-i*j; p = k-h*j-e*q;
            float d = (C-B).absSquare();
            if(0<=p && p<=1 && 0<=q && q<=1 && d*p*p >= d*q*q)
                return j;
        }
    }else if(c!=0){
        x=c;
        c=1;   f/=x;   i/=x;   l/=x;
        x=a;
        a-=c*x; d-=f*x; g-=i*x; j-=l*x;
        x=b;
        b-=c*x; e-=f*x; h-=i*x; k-=l*x;
        if(d!=0){
            x=d;
            d=1;   g/=x;   j/=x;
            x=e;
            e-=d*x; h-=g*x; k-=j*x;
            if(h==0) return -1;
            k/=h;
            q = j-g*k; p = l-i*j-f*q;
            float d = (C-B).absSquare();
            if(0<=p && p<=1 && 0<=q && q<=1 && d*p*p >= d*q*q)
                return k;
        }else if(e!=0){
            x=e;
            e=1;   h/=x;    k/=x;
            x=d;
            d-=e*x; g-=h*x; j-=k*x;
            if(g==0) return -1;
            j/=g;
            q = k-h*j; p = l-i*j-f*q;
            float d = (C-B).absSquare();
            if(0<=p && p<=1 && 0<=q && q<=1 && d*p*p >= d*q*q)
                return j;
        }
    }

    return -1;
}
