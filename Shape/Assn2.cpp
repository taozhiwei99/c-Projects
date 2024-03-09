#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include"Assn2.h"

using namespace std;
{
    {this->index=0;}
}

//display menu
void Assn2::displayMenu () 
{
	cout << "--------------------------------------------------" << endl;
	cout << "Welcome to Assn2 program!" << endl;
	cout << endl;
	cout << "1)\tInput sensor data" << endl;
	cout << "2)\tCompute area (for all records)" << endl;
	cout << "3)\tPrint shapes report" << endl;
	cout << "4)\tSort shape data" << endl;
	cout << "5)\tQuit" << endl;
	cout << endl;
	cout << "Please enter your choice: ";
}

//display submenu
void Assn2::subMenu ()
{
	cout << "\ta)\tSort by area(ascending)" << endl;
	cout << "\tb)\tSort by area(descending)" << endl;
	cout << "\tc)\tSort by special type and area" << endl;
	cout << endl;
	cout << "Please select sort option ('q' to go main menu): ";
}

void Assn2::swap(double *xp,double *yp) 
{ 
    double temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

float Assn2::round(float var)
{
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}

void Assn2::selectionSortAscending(double arr[], int n, ShapeTwoD **shapes) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j; 
			}
		}
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]);
        //swaping shapes too
        ShapeTwoD *temp_shape = shapes[i] ;
        shapes[i] = shapes[min_idx] ;
        shapes[min_idx] = temp_shape ; 
    } 
}

void Assn2::selectionSortDescending(double arr[], int n, ShapeTwoD **shapes) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++)
		{
			if (arr[j] > arr[min_idx])
			{
				min_idx = j; 
			}
		}
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
        //swaping shapes too
        ShapeTwoD *temp_shape = shapes[i] ;
        shapes[i] = shapes[min_idx] ;
        shapes[min_idx] = temp_shape ; 
    } 
}

string Assn2::toLower(string s)
{
    string lower_name = "";
    for(int i=0; i<s.length(); i++)
    {
        lower_name.push_back(tolower(s[i]));
    }
    return lower_name;
}

bool Assn2::isShapeNameValid(string lower_name)
{
    //checking if shape name consists of valid shape name or not
    if(lower_name == "square" || lower_name == "rectangle" || lower_name == "cross" || lower_name == "circle")
        return true;
    else    
        return false;
}

bool Assn2::isSpecialTypeValid(string lower_type)
{
    //now checking if special type is valid or not
    if(lower_type == "ns" || lower_type == "ws")
        return true;
    else
        return false;
}

//run the program
void Assn2::Run()
{
	int ch = 0;
	
    while(ch!=5)
    {
		displayMenu();
		cin >> ch;
		cout << endl;
		
		while (!cin.good() || ch >5 || ch < 1)
		{
			cout <<"Invalid choice!" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			displayMenu();
			cin >> ch;
			cout << endl;	
		}
		
        if(ch==1)
        {
            string shapeName,type;
            cout << "[Input sensor data]" << endl ;
            cout << "Please enter name of shape: ";
            cin >> shapeName;
            shapeName = toLower(shapeName);
            while(isShapeNameValid(shapeName) == false)
            {
                cout << "\nPlease enter valid shape name!\n\n";
                cout << "Please enter name of shape: ";
                cin >> shapeName;
            }
            cout << "Please enter special type: ";
            cin >> type;
            type = toLower(type);
            while(isSpecialTypeValid(type)==false)
            {
                cout << "\nPlease enter valid special type\n\n";
                cout << "Please enter special type: ";
                cin >> type;
            }
            if(shapeName=="square")
            {
                bool warpSpace;
                if(type=="ws")
                    warpSpace=true;
                else if(type=="ns")
                    warpSpace=false;
                //making object for square using polymorphism
                ShapeTwoD *shape = new Square(shapeName,warpSpace);
                //now popuating the data for square
                shape->feedSensorData();
                //now saving in shapes array
                this->shapes[index++] = shape;
                cout << "\nRecord successfully stored. Going back to main menu...\n\n";
            }
            else if(shapeName=="rectangle")
            {
                bool warpSpace;
                if(type=="ws")
                    warpSpace=true;
                else if(type=="ns")
                    warpSpace=false;
                //making object for square using polymorphism
                ShapeTwoD *shape = new Rectangle(shapeName,warpSpace);
                //now popuating the data for rectangle
                shape->feedSensorData();
                //now saving in shapes array
                this->shapes[index++] = shape;
                cout << "\nRecord successfully stored. Going back to main menu...\n\n";
            }
            else if(shapeName=="cross")
            {
                bool warpSpace;
                if(type=="ws")
                    warpSpace=true;
                else if(type=="ns")
                    warpSpace=false;
                //making object for square using polymorphism
                ShapeTwoD *shape = new Cross(shapeName,warpSpace);
                //now popuating the data for cross
                shape->feedSensorData();
                //now saving in shapes array
                this->shapes[index++] = shape;
                cout << "\nRecord successfully stored. Going back to main menu...\n\n";
            }
            else if(shapeName=="circle")
            {
                bool warpSpace;
                if(type=="ws")
                    warpSpace=true;
                else if(type=="ns")
                    warpSpace=false;
                //making object for square using polymorphism
                ShapeTwoD *shape = new Circle(shapeName,warpSpace);
                //now popuating the data for circle
                shape->feedSensorData();
                //now saving in shapes array
                this->shapes[index++] = shape;
                cout << "\nRecord successfully stored. Going back to main menu...\n\n";
            }
            else
            {
                cout << "\nShape not found!\n" << endl;
            }
        }
        else if(ch==2)
        {
            //calcuting areas of all shapes and storing in areas array
            for(int i=0; i<index; i++)
            {
                //cout << shapes[i]->computeArea() << endl ;
                this->areas[i] = shapes[i]->computeArea();
            }
            cout << "Computation completed! (" << index << " records were updated)\n\n";
        }
        else if(ch==3)
        {
            //printing total number of records
            cout << "Total no. of records available = " << index << endl << endl;
            for(int i=0; i<index; i++)
            {
                cout << "Shape [" << i << "]" << endl ;
                cout << "Name : " << shapes[i]->getName() << endl;
                string warpSpace = "";
                if(shapes[i]->getContainsWarpSpace()==true)
                    warpSpace="WS";
                else
                    warpSpace="NS";
                cout << "Special Type : " << warpSpace << endl;
                cout << "Area : " << round(this->areas[i]) << " units square" << endl;
                cout << "Vertices : " << endl;
                shapes[i]->displayVertices();
                cout << "\nPoints on perimeter : ";
                shapes[i]->displayPointsOnPerimeter();
                cout << "\nPoints within shape : ";
                shapes[i]->displayPointsInShape();
				cout << endl;
            }
        }
        else if(ch==4)
        {
			string ch2;
			while(ch2!="q")
			{
				subMenu();
				cin >> ch2;
				transform(ch2.begin(), ch2.end(), ch2.begin(), ::tolower);
				cout << endl;
				
				while (!cin.good() || ch2 != "a" && ch2 != "b" && ch2 != "c" && ch2 !="q")
				{
					cout << "Invalid choice!" << endl;
					cout << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					subMenu();
					cin >> ch2;
					transform(ch2.begin(), ch2.end(), ch2.begin(), ::tolower);
					cout << endl;
				}
				
				if(ch2=="a")
				{
					//area=>ascending
					cout << "Sort by area(smallest to largest)...\n" ;
					this->selectionSortAscending(areas,index,this->shapes);
					for(int i=0; i<this->index; i++)
					{
						cout << "\nShape["<< i << "]" << endl ;
						cout << "Name : " << shapes[i]->getName() << endl;
						string warpSpace = "" ;
						shapes[i]->getContainsWarpSpace() == true ? warpSpace="WS" : warpSpace="NS"; 
						cout << "Special Type : " << warpSpace << endl;
						cout << "Area : " << round(areas[i]) << " units square" << endl;
						cout << "Vertices : " << endl;
						shapes[i]->displayVertices();
						cout << "\nPoints On Perimeter : ";
						shapes[i]->displayPointsOnPerimeter();
						cout << "\nPoints In Shape : ";
						shapes[i]->displayPointsInShape();
						cout << endl;
					}	
				}
				else if(ch2=="b")
				{
					//area=>descending
					cout << "Sort by area(largest to smallest)...\n";
					this->selectionSortDescending(areas,index,this->shapes);
					for(int i=0; i<this->index; i++)
					{
						cout << "\nShape["<< i << "]" << endl;
						cout << "Name : " << shapes[i]->getName() << endl;
						string warpSpace = "";
						shapes[i]->getContainsWarpSpace() == true ? warpSpace="WS" : warpSpace="NS"; 
						cout << "Special Type : " << warpSpace << endl;
						cout << "Area : " << round(areas[i]) << " units square" << endl;
						cout << "Vertices : " << endl;
						shapes[i]->displayVertices();
						cout << "\nPoints On Perimeter : ";
						shapes[i]->displayPointsOnPerimeter();
						cout << "\nPoints In Shape : ";
						shapes[i]->displayPointsInShape();
						cout << endl;
					}
				}
				else if(ch2=="c")
				{
					//sort by special type and area descending
					//first displaying all 'WS' special type in descending order
					this->selectionSortDescending(areas,index,this->shapes);
					int counter = 0;
					for(int i=0; i<index; i++)
					{
						if(shapes[i]->getContainsWarpSpace()==true)
						{
							cout << "Shape["<< counter << "]" << endl;
							cout << "Name : " << shapes[i]->getName() << endl;
							string warpSpace = "WS";
							cout << "Special Type : " << warpSpace << endl;
							cout << "Area : " << round(areas[i]) << " units square" << endl;
							cout << "Vertices : " << endl;
							shapes[i]->displayVertices();
							cout << "\nPoints On Perimeter : ";
							shapes[i]->displayPointsOnPerimeter();
							cout << "\nPoints In Shape : ";
							shapes[i]->displayPointsInShape();
							cout << endl;
							counter ++;
						}
					}
					
					this->selectionSortDescending(areas,index,this->shapes);
					int counter2 = counter;
					// now displaying all 'NS' in descending order
					for(int i=0; i<index; i++)
					{
						if(shapes[i]->getContainsWarpSpace()==false)
						{
							cout << "Shape["<< counter2 << "]" << endl ;
							cout << "Name : " << shapes[i]->getName() << endl;
							string warpSpace = "NS";
							cout << "Special Type : " << warpSpace << endl;
							cout << "Area : " << round(areas[i]) << " units square" << endl;
							cout << "Vertices : " << endl;
							shapes[i]->displayVertices();
							cout << "\nPoints On Perimeter : ";
							shapes[i]->displayPointsOnPerimeter();
							cout << "\nPoints In Shape : ";
							shapes[i]->displayPointsInShape();
							cout << endl;
							counter2 ++;
						}
                    }
                }
            }
        }
		else if ( ch == 5)
		{
			cout << "Goobye!" << endl;
		}
    }
}