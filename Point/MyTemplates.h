#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

#include <math.h>

template <typename T>
double scalar_difference (T & x, T & y) //length difference
{
	return abs(x.getScalarValue() - y.getScalarValue());
}

template <typename T>
bool equals (T &x, T &y) //if x and y equal
{
	if (x == y)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

#endif