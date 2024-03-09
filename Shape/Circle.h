#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include <cmath>
#include "ShapeTwoD.h"

using namespace std;

class Circle:public ShapeTwoD
{
    public:
        Circle();
        Circle(string name,bool containsWarpSpace):ShapeTwoD(name,containsWarpSpace){};
        string toString();
        double computeArea();
        bool isPointInShape(int,int);
        bool isPointOnShape(int,int);
        void feedSensorData();
        void displayVertices();
        void displayPointsOnPerimeter();
        void displayPointsInShape();
		
    private:
        int center[2];
        int radius;
};

#endif