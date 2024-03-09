#include <iostream>
#include <cmath>
#include <algorithm>
#include"Square.h"

using namespace std;

Square::Square(){}

//input coordinates
void Square::feedSensorData()
{
    int p = 0;
    for(int i=0; i<8; i=i+2)
    {
        cout << "Please enter x-ordinate of pt." << ++p << ": ";
        cin >> this->vertices[i] ;
        cout << "Please enter y-ordinate of pt." << p << ": ";
        cin >> this->vertices[i+1] ;
    }
}

//compute square area
double Square::computeArea()
{
    double temp_area = 0.0 ;
    int position = 4 ;
    for(int i=1; i<=4; i++)
    {
        temp_area += (this->vertices[(position*2)-2] + this->vertices[(i*2)-2]) * (this->vertices[(position*2)-1] - this->vertices[(i*2)-1]);
        position = i;
    }
    return abs(temp_area /2.0);
}

string Square::toString()
{
    string tempString = this->getName() ;
    if(this->getContainsWarpSpace()==true)
    {
        tempString += " WS" ;
    }
    else
    {
        tempString += " NS" ;
    }
    tempString += "" ;
    string temp = "" ;
    for(int i=0; i<8; i=i+2)
    {
        temp = "(" + to_string(this->vertices[i]) + "," + to_string(this->vertices[i+1]) + ") ";
        tempString += temp ;
    }
    return tempString ;
}

//check if point on shape
bool Square::isPointOnShape(int x, int y)
{
    int min_x = this->vertices[0];
    for(int i=0; i<8; i=i+2)
    {
        if(this->vertices[i]<min_x)
        {
            min_x = this->vertices[i];
        }
    }
	
    int max_x = this->vertices[0];
    for(int i=0; i<8; i=i+2)
    {
        if(this->vertices[i]>max_x)
        {
            max_x = this->vertices[i];
        }
    }
    
    int min_y = this->vertices[1];
    for(int i=1; i<8; i=i+2)
    {
        if(this->vertices[i]<min_y)
        {
            min_y = this->vertices[i];
        }
    }

    int max_y = this->vertices[1];
    for(int i=1; i<8; i=i+2)
    {
        if(this->vertices[i]>max_y)
        {
            max_y = this->vertices[i];
        }
    } 
    return (((x > min_x && x < max_x) && (y == min_y || y == max_y)) ||
            ((y > min_y && y < max_y) && (x == min_x || x == max_x)));
}

//check if point in shape
bool Square::isPointInShape(int x,int y) 
{
    int min_x = this->vertices[0];
    for(int i=0; i<8; i=i+2)
    {
        if(this->vertices[i]<min_x)
        {
            min_x = this->vertices[i];
        }
    }

    int max_x = this->vertices[0];
    for(int i=0; i<8; i=i+2)
    {
        if(this->vertices[i]>max_x)
        {
            max_x = this->vertices[i];
        }
    }
    
    int min_y = this->vertices[1];
    for(int i=1; i<8; i=i+2)
    {
        if(this->vertices[i]<min_y)
        {
            min_y = this->vertices[i];
        }
    }

    int max_y = this->vertices[1];
    for(int i=1; i<8; i=i+2)
    {
        if(this->vertices[i]>max_y)
        {
            max_y = this->vertices[i];
        }
    }
    return ((x > min_x && x < max_x) && (y > min_y && y < max_y));
}

//display vertices
void Square::displayVertices()
{
    int t = 0 ;
    for(int i=0; i<8; i=i+2)
    {
        cout << "Point[" << t++ << "]" << ": (" << this->vertices[i] << "," << this->vertices[i+1] << ")" << endl; 
    }
}

int Square::greatest(int a, int b, int c, int d)  
{  
    if (a > b) {  
        if (a > c) {  
            if (a > d) {  
                return a;  
            }  
            else {  
                return d;  
            }  
        }  
    }  
    else if (b > c) {  
        if (b > d) {  
            return b;  
        }  
        else {  
            return d;  
        }  
    }  
    else if (c > d) {  
        return c;  
    }  
    else {  
        return d;  
    } 
    return -1; 
}

//display points on perimeter
void Square::displayPointsOnPerimeter()
{
    int maximum_x = greatest(vertices[0],vertices[2],vertices[4],vertices[6]);
    int maximum_y = greatest(vertices[1],vertices[3],vertices[5],vertices[7]);
    bool flag=false ;
	
	//checking if point is on shape
    for(int i=1; i<=maximum_x; i++)
    {
        for(int j=1; j<=maximum_y; j++)
        {
            if(this->isPointOnShape(i,j)==true)
            {
                flag=true ;
                cout << "(" << i << "," << j << "), "; 
            }
        }
    }
    if(!flag)
    {
        cout << "none!" << endl;
        return  ;
    }
    cout << endl;
}

//display point in shape
void Square::displayPointsInShape()
{
    int maximum_x = greatest(vertices[0],vertices[2],vertices[4],vertices[6]);
    int maximum_y = greatest(vertices[1],vertices[3],vertices[5],vertices[7]);
    bool flag=false ;
	
	//checking if point is in shape
    for(int i=1; i<=maximum_x; i++)
    {
        for(int j=1; j<=maximum_y; j++)
        {
            if(this->isPointInShape(i,j)==true)
            {
                flag=true ;
                cout << "(" << i << "," << j << "), "; 
            }
        }
    }
    if(!flag)
    {
        cout << "none!" << endl;
        return;
    }
    cout << endl;
}