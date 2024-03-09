#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include "Cross.h"

using namespace std;

Cross::Cross() {}

//input the coordinates
void Cross::feedSensorData()
{
    int p = 0 ;
	int t = 0;
    for(int i=0; i<12; i++)
    {
        cout << "Please enter x-ordinate of pt." << ++p << ": ";
		cin >> xCoordinateArr[i];
		vertices[t] = xCoordinateArr[i];
        cout << "Please enter y-ordinate of pt." << p << ": ";
        cin >> yCoordinateArr[i];
		vertices[++t] = yCoordinateArr[i];
		t++;
    }
}

//compute area for cross
double Cross::computeArea()
{
    double temp_area = 0.0;
    int position = 12;
    for(int i=1; i<=12; i++)
    {
        temp_area += (this->vertices[(position*2)-2] + this->vertices[(i*2)-2]) * (this->vertices[(position*2)-1] - this->vertices[(i*2)-1]);
        position = i;
    }
	
    return abs(temp_area /2.0);
}

//display vertices
void Cross::displayVertices()
{
    int p=0;
    for(int i=0; i<12; i++)
    {
        cout << "Point[" << p++ << "]" << ": (" << this->xCoordinateArr[i] << "," << this->yCoordinateArr[i] << ")" << endl;
    }
}

int Cross::biggestX()
{
	int temp = xCoordinateArr[0];
	for (int i = 0; i <12; i++)
	{
		if (temp < xCoordinateArr[i])
		{
			temp = xCoordinateArr[i];
		}
	}
	return temp;
}

int Cross::biggestY()
{
	int temp = yCoordinateArr[0];
	for (int i = 0; i <12; i++)
	{
		if (temp < yCoordinateArr[i])
		{
			temp = yCoordinateArr[i];
		}	
	}
	return temp;
}

int Cross::smallestX()
{
	int temp = xCoordinateArr[0];
	for (int i = 0; i < 12; i++)
	{
		if (temp > xCoordinateArr[i])
		{
			temp = xCoordinateArr[i];
		}	
	}
	return temp;
}

int Cross::smallestY()
{
	int temp = yCoordinateArr[0];
	for (int i = 0; i < 12; i++)
	{
		if (temp > yCoordinateArr[i])
		{
			temp = yCoordinateArr[i];
		}	
	}
	return temp;
}

vector <int> Cross::findSideLength()
{
	vector <int> sideLength;
	for (int i = 0; i <12; i++)
	{
		int nextValue = i+1;
		if (i +1 ==12)
		{
			nextValue = 0;
		}
		sideLength.push_back(findLength(xCoordinateArr[i], xCoordinateArr[nextValue], yCoordinateArr[i], yCoordinateArr[nextValue]));
	}
	return sideLength;
}

vector <int> Cross:: findXValueChanges()
{
	vector<int> xValueChanges;
	for (int i = 0; i <12; i++)
	{
		int nextValue = i+1;
		if(i +1 ==12)
		{
			nextValue = 0;
		}
		xValueChanges.push_back(findXDirectionChange(xCoordinateArr[i], xCoordinateArr[nextValue]));
	}
	return xValueChanges;
}

vector <int> Cross:: findYValueChanges()
{
	vector<int> yValueChanges;
	for (int i = 0; i <12; i++)
	{
		int nextValue = i+1;
		if(i +1 ==12)
		{
			nextValue = 0;
		}
		yValueChanges.push_back(findYDirectionChange(yCoordinateArr[i], yCoordinateArr[nextValue]));
	}
	return yValueChanges;
}

vector <int> Cross:: findXPerimeter()
{
	vector <int> sideLength = findSideLength();
	vector <int> xValueChanges = findXValueChanges();
	vector <int> xPerimeterPoints;
	
	for (int i = 0; i < 12; i ++)
	{
		int nextValue = i +1;
		if(i+1 == 12)
		{
			nextValue = 0;
		}
		if (sideLength[i] >1)
		{
			for (int j = 0; j < sideLength[i]-1; j ++)
			{
				if (xCoordinateArr[i] < xCoordinateArr[nextValue])
				{
					xPerimeterPoints.push_back(findPointXCoordinate(xCoordinateArr[i]+j, xCoordinateArr[nextValue], xValueChanges[i]));
				}
				else if ( xCoordinateArr[i] == xCoordinateArr[nextValue])
				{
					xPerimeterPoints.push_back(findPointXCoordinate(xCoordinateArr[i], xCoordinateArr[nextValue], xValueChanges[i]));
				}
				else
				{
					xPerimeterPoints.push_back(findPointXCoordinate(xCoordinateArr[i] - j, xCoordinateArr[nextValue], xValueChanges[i]));
				}
			}
		}
	}
	return xPerimeterPoints;
}

vector <int> Cross:: findYPerimeter()
{
	vector <int> sideLength = findSideLength();
	vector <int> yValueChanges = findYValueChanges();
	vector <int> yPerimeterPoints;
	
	for (int i = 0; i < 12; i ++)
	{
		int nextValue = i +1;
		if(i+1 == 12)
		{
			nextValue = 0;
		}
		
		if (sideLength[i] >1)
		{
			for (int j = 0; j < sideLength[i]-1; j ++)
			{
				if (yCoordinateArr[i] < yCoordinateArr[nextValue])
				{
					yPerimeterPoints.push_back(findPointYCoordinate(yCoordinateArr[i]+j, yCoordinateArr[nextValue], yValueChanges[i]));
				}
				else if ( yCoordinateArr[i] == yCoordinateArr[nextValue])
				{
					yPerimeterPoints.push_back(findPointYCoordinate(yCoordinateArr[i], yCoordinateArr[nextValue], yValueChanges[i]));
				}
				else
				{
					yPerimeterPoints.push_back(findPointYCoordinate(yCoordinateArr[i] - j, yCoordinateArr[nextValue], yValueChanges[i]));
				}
			}
		}
	}
	return yPerimeterPoints;
}

int Cross::findLength(int x1, int x2, int y1, int y2)
{
	if (x2 -x1 ==0)
	{
		return (abs(y2-y1));
	}
	else
	{
		return (abs(x2-x1));
	}
}

bool Cross:: findXDirectionChange(int x1, int x2)
{
	if (x2 - x1 ==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Cross:: findYDirectionChange(int y1, int y2)
{
	if (y2 - y1 ==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Cross::findPointXCoordinate(int x1, int x2, int xChange)
{
	if (xChange == 1)
	{
		if (x1 < x2)
		{
			return x1 +1;
		}
		else
		{
			return x1-1;
		}
	}
	else
	{
		return x1;
	}
}

int Cross::findPointYCoordinate(int y1, int y2, int yChange)
{
	if (yChange == 1)
	{
		if (y1 < y2)
		{
			return y1 +1;
		}
		else
		{
			return y1-1;
		}
	}
	else 
	{
		return y1;
	}
}

vector < int > Cross::findBoundaryXValues(int start)
{
	vector <int> xPerimeterPoints = findXPerimeter();
	vector <int> yPerimeterPoints = findYPerimeter();
	vector <int> boundaryXValues;
	
	for (int i = 0; i <12; i ++)
	{
		if ( yCoordinateArr[i] == start)
		{
			boundaryXValues.push_back(xCoordinateArr[i]);
		}
		
	}
	
	for (int j = 0; j <xPerimeterPoints.size(); j++)
	{
		if (yPerimeterPoints[j] == start)
		{
			boundaryXValues.push_back(xPerimeterPoints[j]);
		}
	}
	return boundaryXValues;
}

vector < int > Cross::findBoundaryYValues(int start)
{
	vector <int> yPerimeterPoints = findYPerimeter();
	vector <int> boundaryYValues;
	
	for (int i = 0; i <12; i ++)
	{
		if ( yCoordinateArr[i] == start)
		{
			boundaryYValues.push_back(yCoordinateArr[i]);
		}
		
	}
	
	for (int j = 0; j <yPerimeterPoints.size(); j++)
	{
		if (yPerimeterPoints[j] == start)
		{
			boundaryYValues.push_back(yPerimeterPoints[j]);
		}
	}
	return boundaryYValues;
}

vector <int> Cross::findXPointsInBetweenTwoVertices(vector<int> boundaryXValues)
{
	int pointsInBetweenCounter = 0;
	vector <int> xPointsInBetween;
	int smallX = boundaryXValues[0];
	int bigX = boundaryXValues[0];
	
	for (int i = smallestX(); i <boundaryXValues.size(); i++)
	{
		if (boundaryXValues[i] < smallX)
		{
			smallX = boundaryXValues[i];
		}
		if (boundaryXValues[i] > bigX)
		{
			bigX = boundaryXValues[i];
		}
	}
	for (int i =smallX; i <bigX -1; i ++)
	{
		xPointsInBetween.push_back(smallX+pointsInBetweenCounter +1);
		pointsInBetweenCounter ++;
	}
	return xPointsInBetween;
}

vector <int> Cross::findYPointsInBetweenTwoVertices(int start, vector<int> boundaryXValues)
{
	vector <int> yPointsInBetween;
	int smallX = boundaryXValues[0];
	int smallY = start;
	int bigX = boundaryXValues[0];
	int bigY = start;
	
	for (int i = smallestX(); i <boundaryXValues.size(); i++)
	{
		if (boundaryXValues[i] < smallX)
		{
			smallX = boundaryXValues[i];
		}
		if (boundaryXValues[i] > bigX)
		{
			bigX = boundaryXValues[i];
		}
	}
	for (int i =smallX; i <bigX -1; i ++)
	{
		yPointsInBetween.push_back(smallY);
	}
	return yPointsInBetween;
}

vector <int> Cross::findXPointsInShape ()
{
	int start = smallestY();
	int end = biggestY();
	vector <int> boundaryXValues;
	vector <int> xPointsInBetween;
	vector <int> xPointInShape;
	for (start; start < end+1; start++)
	{
		boundaryXValues = findBoundaryXValues(start);
		xPointsInBetween = findXPointsInBetweenTwoVertices(boundaryXValues);
		int pointsInBetweenSize = xPointsInBetween.size();
		vector <int>::iterator it;
		for (int i = 0; i <pointsInBetweenSize; i++)
		{
			it = find(boundaryXValues.begin(), boundaryXValues.end(), xPointsInBetween[i]);
			if (it != boundaryXValues.end())
			{
				
			}
			else
			{
				xPointInShape.push_back(xPointsInBetween[i]);
			}
			*it = 0;
		}
	}
	return xPointInShape;
}

string Cross::toString()
{
    string finalString = this->getName();
    if(this->getContainsWarpSpace()==true)
	{
		finalString += " WS";
	}   
    else
	{
		finalString += " NS";
	} 
    finalString += "";
    string temp = "" ;
    for(int i=0; i<24; i=i+2)
    {
        temp = "(" + to_string(xCoordinateArr[i]) + "," + to_string(yCoordinateArr[i]) + ") ";
        finalString = finalString + temp;
    }
    return finalString;
}

vector <int> Cross::findYPointsInShape ()
{
	int start = smallestY();
	int end = biggestY();
	vector <int> boundaryXValues;
	vector <int> boundaryYValues;
	vector <int> xPointsInBetween;
	vector <int> yPointsInBetween;
	vector <int> yPointInShape;
	for (start; start < end+1; start++)
	{
		boundaryXValues = findBoundaryXValues(start);
		boundaryYValues = findBoundaryYValues(start);
		xPointsInBetween = findXPointsInBetweenTwoVertices(boundaryXValues);
		yPointsInBetween = findYPointsInBetweenTwoVertices(start, boundaryXValues);
		int pointsInBetweenSize = xPointsInBetween.size();
		vector <int>::iterator it;
		for (int i = 0; i <pointsInBetweenSize; i++)
		{
			it = find(boundaryXValues.begin(), boundaryXValues.end(), xPointsInBetween[i]);
			if (it != boundaryXValues.end())
			{
				
			}
			else
			{
				yPointInShape.push_back(yPointsInBetween[i]);
			}
			*it = 0;
		}
	}
	return yPointInShape;
}

//check if point in shape
bool Cross::isPointInShape(int x, int y)
{
	vector <int> xPointInShape = findXPointsInShape();
	vector <int> yPointInShape = findYPointsInShape();
	for (int i =0; i < xPointInShape.size(); i++)
	{
		if (xPointInShape[i] == x && yPointInShape[i] == y)
		{
			return true;
		}
		else
		{
			return false;
		}		
	}
}

//check if point on shape
bool Cross::isPointOnShape(int x, int y)
{
	vector <int> xPerimeterPoints = findXPerimeter();
	vector <int> yPerimeterPoints = findYPerimeter();
	for (int i = 0; i < xPerimeterPoints.size(); i ++)
	{
		if (xPerimeterPoints[i] == x && yPerimeterPoints[i] == y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
}

//display points on perimeter
void Cross::displayPointsOnPerimeter(){
	if (findXPerimeter().size() == 0)
	{
		cout << "none!"<< endl;
	}
	else
	{
		for (int i = 0; i < findXPerimeter().size(); i++)
		{
			cout << "(" <<findXPerimeter()[i] << ",";
			cout << findYPerimeter()[i] << "), "; 
		}
	}
	cout << endl;
}

//display points in shape
void Cross::displayPointsInShape(){
	if (findXPointsInShape().size() == 0)
	{
		cout << "none!"<<endl;
	}
	else
	{
		for (int i = 0; i < findXPointsInShape().size(); i++)
		{
			cout << "(" <<findXPointsInShape()[i] << ",";
			cout << findYPointsInShape()[i] << "), "; 
		}
	}
}