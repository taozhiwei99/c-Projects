#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Point2D.h"

using namespace std;

class Point3D : public Point2D
{
	friend ostream & operator <<(ostream & os, Point3D & P);
	
	public:
			Point3D();
			~Point3D();
			Point3D(int x, int y, int z);
			int getZ();
			void setZ(int z);
			bool operator == (Point3D p);
			double operator - (Point3D p);
	
	protected:
			int z = 0;
			void setDistFrOrigin();
};

#endif