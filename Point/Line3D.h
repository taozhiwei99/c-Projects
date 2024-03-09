#ifndef LINE_3D
#define LINE_3D

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Point3D.h"
#include "Line2D.h"

using namespace std;

class Line3D : public Line2D
{
	friend ostream & operator <<(ostream & os, Line3D & L);
	
	public:
			Line3D();
			~Line3D();
			Line3D(Point3D pt1, Point3D pt2);
			Point3D getPt1();
			Point3D getPt2();
			double getScalarValue();
			void setPt1(Point3D pt1);
			void setPt2(Point3D pt2);
			bool operator == (Line3D l);
			double operator - (Line3D l);
	
	protected:
			void setLength();
	
	private:
			Point3D pt1;
			Point3D pt2;	
};

#endif
