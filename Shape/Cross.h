#ifndef CROSS_H
#define CROSS_H 
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include "ShapeTwoD.h"

using namespace std;

class Cross : public ShapeTwoD
{
    private:
        int xCoordinateArr[12];
        int yCoordinateArr[12];
		int vertices[24];
		
    public:
        Cross();
		Cross(string name,bool containsWarpSpace):ShapeTwoD(name,containsWarpSpace){};
        int biggestX();
        int biggestY();
        int smallestX();
        int smallestY();
        vector <int> findXPerimeter();
        vector <int> findYPerimeter();
        int findLength(int x1, int x2, int y1, int y2);
        bool findXDirectionChange(int x1, int x2);
        bool findYDirectionChange(int y1, int y2);
        int findPointXCoordinate(int x1, int x2, int xChange);
        int findPointYCoordinate(int y1, int y2, int yChange);
        vector<int> findSideLength();
        vector<int> findXValueChanges();
        vector<int> findYValueChanges();
        vector <int> findBoundaryXValues(int start);
        vector <int> findBoundaryYValues(int start);
        vector <int> findXPointsInBetweenTwoVertices(vector<int> boundaryXValues);
        vector <int> findYPointsInBetweenTwoVertices(int start, vector<int> boundaryXValues);
        vector <int> findXPointsInShape();
        vector <int> findYPointsInShape();
        double computeArea();
        bool isPointInShape(int, int);
        bool isPointOnShape(int, int);
		string toString();
		void feedSensorData();
		void displayVertices();
		void displayPointsOnPerimeter();
        void displayPointsInShape();
};
#endif