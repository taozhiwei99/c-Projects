#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "ShapeTwoD.h"

using namespace std ;

class Square: public ShapeTwoD
{
    public:
        Square();
        Square(string name,bool containsWarpSpace):ShapeTwoD(name,containsWarpSpace){};
        string toString();
        double computeArea();
        bool isPointInShape(int x,int y);
        bool isPointOnShape(int x,int y);
        void feedSensorData();
        void displayVertices();
        void displayPointsOnPerimeter();
        void displayPointsInShape();
        int  greatest(int,int,int,int);    
		
    private:
        int vertices[8];
};

#endif