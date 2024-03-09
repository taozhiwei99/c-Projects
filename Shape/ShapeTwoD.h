#ifndef SHAPE_TWO_D_H
#define SHAPE_TWO_D_H
#include <iostream>
#include <string>

using namespace std;

class ShapeTwoD
{
    public:
        ShapeTwoD();
        ShapeTwoD(string name, bool containsWarpSpace);
        string getName();
        bool getContainsWarpSpace();
        virtual string toString();
        virtual double computeArea();
        virtual bool isPointInShape(int x,int y);
        virtual bool isPointOnShape(int x,int y);
        void setName(string name);
        void setContainsWarpSpace(bool containsWarpSpace);

        //additonal functions

        //takes points input from user
        virtual void feedSensorData(){} ;                       
        //displays all vertices of shape
        virtual void displayVertices(){} ;                      
        //displays those points which are on perimeter of shape
        virtual void displayPointsOnPerimeter(){} ;             
        //displays those points which are inside the shape
        virtual void displayPointsInShape(){} ;      
		
    protected:
        string name;
        bool containsWarpSpace;
};

#endif