#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
#include <cmath>
#include "ShapeTwoD.h"

using namespace std ;

class Rectangle: public ShapeTwoD
{
    public:
        Rectangle();
        Rectangle(string name,bool containsWarpSpace):ShapeTwoD(name,containsWarpSpace){};
        string toString();
        double computeArea();
        bool isPointInShape(int x,int y);
        bool isPointOnShape(int x,int y);
        void feedSensorData();
        void displayVertices();
        void displayPointsOnPerimeter();
        void displayPointsInShape();
        int greatest(int,int,int,int);
		
    private:
        int vertices[8];
};

#endif