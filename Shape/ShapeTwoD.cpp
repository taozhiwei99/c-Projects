#include <iostream>
#include <string>
#include "ShapeTwoD.h"

using namespace std;

ShapeTwoD::ShapeTwoD() {} //default constructor

//constructor
ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace)
{
    this->name = name;
    this->containsWarpSpace = containsWarpSpace;
}

double ShapeTwoD::computeArea()
{
    return 0.0;
}

string ShapeTwoD::getName()
{
    return this->name;
}

bool ShapeTwoD::getContainsWarpSpace()
{
    return this->containsWarpSpace;
}

string ShapeTwoD::toString(){}

bool ShapeTwoD::isPointInShape(int x, int y)
{
    return false;
}

bool ShapeTwoD::isPointOnShape(int x, int y)
{
    return false;
}

void ShapeTwoD::setName(string name)
{
    this->name = name;
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
    this->containsWarpSpace = containsWarpSpace;
}