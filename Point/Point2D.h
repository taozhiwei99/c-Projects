#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Point2D
{
	friend ostream & operator<<(ostream & os, Point2D & P);
	
	public:
			Point2D();
			~Point2D();
			Point2D(int x, int y);
			int getX();
			int getY();
			double getScalarValue();
			void setX(int x);
			void setY(int y);
			bool operator == (Point2D p);
			double operator - (Point2D p);

	protected:
			int x = 0;
			int y = 0;
			double distFrOrigin = 0.0;
			void setDistFrOrigin();
};

#endif