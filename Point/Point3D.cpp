#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Point3D.h"

using namespace std;

//default constructor
Point3D::Point3D() {}

//de-constructor
Point3D:: ~Point3D() {}

//other constructor
Point3D::Point3D(int x, int y, int z) : Point2D(x,y)
{
	this->z = z;
	setDistFrOrigin();
}

//mutator
void Point3D::setDistFrOrigin()
{
	double result = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	this->distFrOrigin = result;
}

int Point3D::getZ() 
{
	return z;
}

void Point3D::setZ(int z)
{
	this->z = z;
}

//operator overload
bool Point3D::operator ==(Point3D p)
{
	return (getX() == p.getX() && getY() == p.getY() && getZ() == p.getZ());
}

double Point3D::operator - (Point3D p)
{
	return abs(getScalarValue() - p.getScalarValue());
}

//output data using this format
ostream & operator <<(ostream & os, Point3D & P)
{
	os << "[" << right << setw(4) << P.getX() << ","
		<< setw(4) << P.getY() << ","
		<< setw(4) << P.getZ() << "]   "
		<< left << fixed << setprecision(3) << P.getScalarValue() << endl;
	return os;	
}