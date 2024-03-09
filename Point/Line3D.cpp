#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Line3D.h"

using namespace std;

//default constructor
Line3D::Line3D() {}

//de-constructor
Line3D::~Line3D() {}

//other constructor
Line3D::Line3D(Point3D pt1, Point3D pt2)
{
	this->pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}

//accessor
Point3D Line3D::getPt1()
{
	return pt1;
}

Point3D Line3D::getPt2()
{
	return pt2;
}

//mutator
double Line3D::getScalarValue()
{
	return length;
}

void Line3D::setPt1(Point3D pt1)
{
	this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2)
{
	this->pt2 = pt2;
}

void Line3D::setLength()
{
	double x = pt1.getX() - pt2.getX();
	double y = pt1.getY() - pt2.getY();
	double z = pt1.getZ() - pt2.getZ();
	double result = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	this->length = result;
}

//operator overload
bool Line3D::operator == (Line3D l)
{
	return (getPt1() == l.getPt1() && getPt2() == l.getPt2());
}

double Line3D::operator - (Line3D l)
{
	return abs(getScalarValue() - l.getScalarValue());
}

//output data using this format
ostream & operator<<(ostream & os, Line3D & L)
{
	os << "[" << right << setfill(' ') << setw(4) << L.getPt1().getX() << ","
		<< setw(4) << L.getPt1().getY() << ","
		<< setw(4) << L.getPt1().getZ() << "]   ["
		<< setw(4) << L.getPt2().getX() << ","
		<< setw(4) << L.getPt2().getY() << ","
		<< setw(4) << L.getPt2().getZ() << "]   "
		<< left << setfill(' ') << fixed << setprecision(3) << L.getScalarValue() << endl;
	return os;
}

