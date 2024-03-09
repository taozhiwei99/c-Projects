#ifndef LINE2D_H
#define LINE2D_H

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Point2D.h"

using namespace std;

class Line2D : public Point2D
{
	friend ostream & operator <<(ostream & os, Line2D & L);
	
	public:
			Line2D();
			~Line2D();
			Line2D(Point2D pt1, Point2D pt2);
			Point2D getPt1();
			Point2D getPt2();
			double getScalarValue();
			void setPt1(Point2D pt1);
			void setPt2(Point2D pt2);
			bool operator == (Line2D l);
			double operator - (Line2D l);
			
	protected:
			double length = 0.0;
			void setLength();
	
	private:
			Point2D pt1;
			Point2D pt2;
};

#endif