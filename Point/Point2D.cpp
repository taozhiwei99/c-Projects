#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Point2D.h"

using namespace std;

//default constructor
Point2D::Point2D() {}

//de-constructor
Point2D:: ~Point2D() {}

//other constructor
void Point2D::setDistFrOrigin() 
{
	double result = sqrt(pow(x,2) + pow(y,2));
	this->distFrOrigin = result;
}

//accessor
Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
	setDistFrOrigin();
}

//mutator
int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}

double Point2D::getScalarValue()
{
	return distFrOrigin;
}

void Point2D::setX(int x)
{
	this->x = x;
}

void Point2D::setY(int y)
{
	this->y = y;
}

//operator overload
bool Point2D::operator ==(Point2D p)
{
	return (getX() == p.getX() && getY() == p.getY());
}

double Point2D::operator - (Point2D p)
{
	return abs(getScalarValue() - p.getScalarValue());
}

//output data using this format
ostream & operator <<(ostream & os, Point2D & P)
{
	os << "[" << right << setw(4) << P.getX() << ","
		<< setw(4) << P.getY() << "]   "
		<< left << fixed << setprecision(3) << P.getScalarValue() << endl;
	return os;	
}


