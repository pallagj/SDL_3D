#include "Space.h"
#include <vector>
#include "Triangle.h"
#include "Object.h"
#include <iostream>

Object& Space::operator[] (int i){
	return objects[i];
}

Object  Space::operator[] (int i) const{
	return objects[i];
}

int Space::getSize() const{
	return objects.size();
}

void Space::addObject(Object obj){
	objects.push_back(obj);
}

void Space::removeObject(int i){
    objects.erase(objects.begin() + i);
}

Color Space::intersection(Point A, Point B) const{
	float r_min = -1;
	Color color = Color(0,0,0);
	for(Object obj : objects){
		for(Triangle t : obj.parts){
			float r = t.intersection(A, B);
			if(r >= 0 &&(r_min < 0 || r < r_min)){
				r_min = r;
				color = t.getColor();
			}
		}
	}
	return color;
}
