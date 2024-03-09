#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Line2D.h"

using namespace std;

//default constructor
Line2D::Line2D() {}

//de-constructor
Line2D:: ~Line2D() {}

//other constructor
Line2D::Line2D(Point2D pt1, Point2D pt2):Point2D(x, y)
{
	this->pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}

//accessor
Point2D Line2D::getPt1()
{
	return pt1;
}

Point2D Line2D::getPt2()
{
	return pt2;
}

//mutator
double Line2D::getScalarValue()
{
	return length;
}

void Line2D::setPt1(Point2D pt1)
{
	this->pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2)
{
	this->pt2 = pt2;
}

void Line2D::setLength()
{
	double x = pt1.getX() - pt2.getX();
	double y = pt1.getY() - pt2.getY();
	double result = sqrt(pow(x, 2) + pow(y, 2));
	this->length = result;
}

//operator overload
bool Line2D::operator ==(Line2D l)
{
	return (getPt1() == l.getPt1() && getPt2() == l.getPt2());
}

double Line2D::operator - (Line2D l)
{
	return abs(getScalarValue() - l.getScalarValue());
}

//output data using this format
ostream & operator<<(ostream & os, Line2D & L)
{
	os << "[" << right << setfill(' ') << setw(4) << L.getPt1().getX() << ","
			<< setw(4) << L.getPt1().getY() << "]   ["
			<< setw(4) << L.getPt2().getX() << ","
			<< setw(4) << L.getPt2().getY() << "]   "
			<< left << setfill(' ') << fixed << setprecision(3) << L.getScalarValue() << endl;
	return os;	
}