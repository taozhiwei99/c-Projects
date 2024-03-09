#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;

//input coordinates
void Circle::feedSensorData()
{
    cout << "Enter x-ordinate of center: ";
    cin >> center[0];
    cout << "Enter y-ordinate of center: ";
    cin >> center[1];
    cout << "Please enter radius (units): ";
    cin >> radius;
}

//compute circle area 
double Circle::computeArea()
{
    double diameter = pow(radius,2);
    return (3.1412*diameter);
}

string Circle::toString()
{
    string finalString = this->getName();
    if(this->getContainsWarpSpace()==true)
	{
		finalString += " WS";
	}
	else
	{
		finalString += " NS";
	} 
    finalString +="";
    string temp = "(";
    temp = temp + to_string(center[0]) + "," + to_string(center[1]) + ") ";
    finalString += temp;
    finalString += to_string(radius);
    return finalString;
}

//check if point on shape
bool Circle::isPointOnShape(int x,int y)
{
    int left_side = ((x - this->center[0])*(x - this->center[0])) + pow((y - this->center[1]), 2); 
    int right_side = this->radius*this->radius ; 
    if(left_side==right_side)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//display point on perimeter
void Circle::displayPointsOnPerimeter()
{
	int n1 = this->center[0];
	int n2 = this->center[1] - radius;
	int e1 = this->center[0] + radius;
	int e2 = this->center[1];
	int s1 = this->center[0];
	int s2 = this->center[1] + radius;
	int w1 = this->center[0] - radius;
	int w2 = this->center[1];
	
	if (n1 > 0 )
	{
		cout << "(" << n1 <<"," << n2 << ")";
		cout << ", " << "(" << e1 << "," << e2 << ")";
		cout << ", " << "(" << s1 << "," << s2 << ")";
		cout << ", " << "(" << w1 << "," << w2 <<")" << endl;
	}
	else
	{
		cout << "none!" << endl;
	}
}

//check if point in shape
bool Circle::isPointInShape(int x,int y)
{
    int left_side = ((x - this->center[0])*(x - this->center[0])) + pow((y - this->center[1]), 2); 
    int right_side = this->radius*this->radius ; 

    if(left_side<right_side)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//display point in shape
void Circle::displayPointsInShape()
{
    bool found=false;
    int start_y = this->center[1] - radius; 
    int y_last = this->center[1] + radius;
    int start_x = this->center[0] - radius; 
    int x_last = this->center[0] + radius;

    for (int i = start_x; i <= x_last; i++)
    {
        for (int j = start_y; j <= y_last; j++)
        {
            if (isPointInShape(i, j))
            {
                if((i == this->center[0] && j == this->center[1])==false)
                {
                     cout << "(" << i << "," << j << "),";
                    found = true;
                }
            }
        }
    }
    if(found==false)
    {
        cout << "none!" <<endl;
        return  ;
    }
    cout << endl;
}

//display vertices
void Circle::displayVertices()
{
    cout << "Center: " <<  "(" <<this->center[0] << "," << this->center[1] << ")" << endl;
    cout << "Radius: " << this->radius << endl;
}