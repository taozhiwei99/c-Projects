#ifndef ASSN2_H
#define ASSN2_H
#include <iostream>
#include <algorithm>
#include "Square.cpp"
#include "Cross.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "ShapeTwoD.cpp"
#define SIZE 500
                   
using namespace std;

class Assn2{
    public:
        //default constructor
        Assn2(); 
        //prints menu
		void displayMenu();
		void subMenu();
		//runs the program
        void Run();                                          
        //swaps two numbers
        void swap(double*,double*);
        //sort in ascending order                          
        void selectionSortAscending(double arr[],int, ShapeTwoD **shapes);
        //sort in descending order                
        void selectionSortDescending(double arr[],int, ShapeTwoD **shapes);   
        //function to convert string to lower case
        string toLower(string s);
        //function to check if given shape name is valid or not
        bool isShapeNameValid(string name);  
        //function to check if special type is valid or not
        bool isSpecialTypeValid(string type); 
		//function to round up number to 2 decimal places
		float round(float var);
		
    private:
        ShapeTwoD** shapes = new ShapeTwoD*[100];	//array pointers to ShapeTWOD
        double areas[SIZE];			//array to store areas of all shapes
        int index =0;			//stores number of shapes
};

#endif