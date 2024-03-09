#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include<cstring>
#include <vector>
#include <cctype>
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"


using namespace std;

//variables
string currentFilter = "Point2D";
string currentSort = "x-ordinate";
string currentOrder = "ASC";
string txtFile;
int totalData;
vector <string> aFile;
vector <string> lines;
vector <Point2D> point2D;
vector <Point3D> point3D;
vector <Line2D> line2D;
vector <Line3D> line3D;

//get the file name
void getFile()
{
	fstream file;
	string fileName;
	
	//loop until user have enter a correct file
	do
	{
		cout <<"Please enter filename : ";
		cin >> fileName;
		cout << endl;
		
		file.open(fileName);
		if (!file)
		{
			cout <<"File: <" << fileName << "> not found, try again!" << endl;
			cout << endl;
			continue;
		}
		
		//store the file name
		txtFile = fileName;
		aFile.push_back(fileName);
		file.close();
		break;
	}while(true);
}

//process the file
void processFile()
{
	fstream file;
	string aLine;
	
	//open file
	file.open(txtFile);
	if (file.good())
	{
		//output all the lines into a vector
		while (getline (file, aLine))
		{
			if (aLine.empty() != true)
			{
				lines.push_back(aLine);
			}
		}
	}
	file.close();
	
	//sort the vector to remove duplicate data
	sort(lines.begin(), lines.end());
	lines.erase(unique(lines.begin(), lines.end()), lines.end());
	//erase the empty line
	lines.erase(lines.begin());
	//get the total number of data
	totalData = lines.size();
	
	cout << totalData << " records read in successfully!" << endl;
	cout << endl;
	cout << "Going back to main menu..." << endl;
	cout << endl;
}

//load the data into respective class/vectors
void loadData()
{
	//load into point2D class
	for (int i = 0; i < lines.size(); i++)
	{
		if(lines[i].substr(0, lines[i].find(",")) == "Point2D")
		{
			string p1;
			string p2;
			int P1;
			int P2;
			
			string str1 = lines[i].erase(0,lines[i].find("[") +1);
			
			int num1 = str1.find_first_of(",");
			
			for (int j = 0; j < num1; j++)
			{
				p1 += str1[j];
			}
			
			string str2 = str1.erase(0, str1.find(",") +2);
			int num2 = str2.find_first_of("]");
			
			for (int j2 = 0; j2 < num2; j2++)
			{
				p2 += str2[j2];
			}
			P1 = stoi(p1);
			P2 = stoi(p2);
			point2D.push_back(Point2D(P1, P2));
		}
		//load into point3D class
		else if (lines[i].substr(0, lines[i].find(",")) == "Point3D")
		{
			string p3D1;
			string p3D2;
			string p3D3;
			int P3D1;
			int P3D2;
			int P3D3;
			
			string str3 = lines[i].erase(0, lines[i].find("[") +1);
			int num3 = str3.find_first_of(",");
			
			for (int j3 = 0; j3 < num3; j3++)
			{
				p3D1 += str3[j3];
			}
			
			string str4 = lines[i].erase(0, lines[i].find(",") +2);
			int num4 = str4.find_first_of(",");
			
			for (int j4 = 0; j4 < num4; j4++)
			{
				p3D2 += str4[j4];
			}
			
			string str5 = lines[i].erase(0, lines[i].find(",") +2);
			int num5 = str5.find_first_of("]");
			
			for (int j5 = 0; j5 < num5; j5++)
			{
				p3D3 += str5[j5];
			}
			
			P3D1 = stoi(p3D1);
			P3D2 = stoi(p3D2);
			P3D3 = stoi(p3D3);
			point3D.push_back(Point3D(P3D1, P3D2, P3D3));
		}
		//load into line2D class
		else if (lines[i].substr(0, lines[i].find(",")) == "Line2D")
		{
			string l1;
			string l2;
			string l3;
			string l4;
			int L1;
			int L2;
			int L3;
			int L4;
			
			string Line1 = lines[i].erase(0, lines[i].find("[") +1);
			int no1 = Line1.find_first_of(",");
			
			for (int k = 0; k < no1; k++)
			{
				l1 += Line1[k];
			}
			
			string Line2 = lines[i].erase(0, lines[i].find(",") +2);
			int no2 = Line2.find_first_of("]");
			
			for (int k2 = 0; k2 < no2; k2++)
			{
				l2 += Line2[k2];
			}
			
			string Line3 = lines[i].erase(0, lines[i].find("[") +1);
			int no3 = Line3.find_first_of(",");
			
			for (int k3 = 0; k3 < no3; k3++)
			{
				l3 += Line3[k3];
			}
			
			string Line4 = lines[i].erase(0, lines[i].find(",") +2);
			int no4 = Line4.find_first_of("]");
			
			for (int k4 = 0; k4 < no4; k4++)
			{
				l4 += Line4[k4];
			}
			
			L1 = stoi(l1);
			L2 = stoi(l2);
			L3 = stoi(l3);
			L4 = stoi(l4);
			line2D.push_back(Line2D(Point2D(L1,L2), Point2D(L3,L4)));
		}
		//load into Line3D class
		else if (lines[i].substr(0, lines[i].find(",")) == "Line3D")
		{
			string l3D1;
			string l3D2;
			string l3D3;
			string l3D4;
			string l3D5;
			string l3D6;
			int L3D1;
			int L3D2;
			int L3D3;
			int L3D4;
			int L3D5;
			int L3D6;
			
			string Line5 = lines[i].erase(0, lines[i].find("[") +1);
			int no5 = Line5.find_first_of(",");
			
			for (int m = 0; m < no5; m++)
			{
				l3D1 += Line5[m];
			}
			
			string Line6 = lines[i].erase(0, lines[i].find(",") +2);
			int no6 = Line6.find_first_of(",");
			
			for (int m2 = 0; m2 < no6; m2++)
			{
				l3D2 += Line6[m2];
			}
			
			string Line7 = lines[i].erase(0, lines[i].find(",") +2);
			int no7 = Line7.find_first_of("]");
			
			for (int m3 = 0; m3 < no7; m3++)
			{
				l3D3 += Line7[m3];
			}
			
			string Line8 = lines[i].erase(0, lines[i].find("[") +1);
			int no8 = Line8.find_first_of(",");
			
			for (int m4 = 0; m4 < no8; m4++)
			{
				l3D4 += Line8[m4];
			}
			
			string Line9 = lines[i].erase(0, lines[i].find(",") +2);
			int no9 = Line9.find_first_of(",");
			
			for (int m5 = 0; m5 < no9; m5++)
			{
				l3D5 += Line9[m5];
			}
			
			string Line10 = lines[i].erase(0, lines[i].find(",") +2);
			int no10 = Line10.find_first_of("]");
			
			for (int m6 = 0; m6 < no10; m6++)
			{
				l3D6 += Line10[m6];
			}
			
			L3D1 = stoi(l3D1);
			L3D2 = stoi(l3D2);
			L3D3 = stoi(l3D3);
			L3D4 = stoi(l3D4);
			L3D5 = stoi(l3D5);
			L3D6 = stoi(l3D6);
			line3D.push_back(Line3D(Point3D(L3D1, L3D2, L3D3), Point3D(L3D4, L3D5, L3D6)));
		}
	}
}

void option1() 
{
	getFile();
	processFile();
	loadData();
}

//get filter criteria
void option2()
{
	string filter;
	
	cout << "[Specifying filtering criteria (current : " << currentFilter << ")]" << endl;
	cout << endl;
	cout << "\ta)\tPoint2D records" << endl;
	cout << "\tb)\tPoint3D records" << endl;
	cout << "\tc)\tLine2D records" << endl;
	cout << "\td)\tLine3D records" << endl;
	cout << endl;
	cout << "\tPlease enter your criteria (a-d) : ";
	cin >> filter;
	cout << endl;
	
	//to lowercase for comparison
	transform(filter.begin(), filter.end(), filter.begin(), ::tolower);
	
	//to handle wrong option entries
	while (!cin.good() || filter !="a" && filter !="b" && filter !="c" && filter !="d")
	{
		cout <<"\tInvalid choice!" << endl;
		cout << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\tPlease enter your criteria (a-d) : ";
		cin >> filter;
		transform(filter.begin(), filter.end(), filter.begin(), ::tolower);
		cout << endl;
	}
	
	if (filter == "a")
	{
		currentFilter = "Point2D";
		currentSort = "x-ordinate";
	}
	else if (filter == "b")
	{
		currentFilter = "Point3D";
		currentSort = "x-ordinate";
	}
	else if (filter == "c")
	{
		currentFilter = "Line2D";
		currentSort = "Pt. 1";
	}
	else if (filter == "d")
	{
		currentFilter = "Line3D";
		currentSort = "Pt. 1";
	}
	
	cout << "\tFilter criterial successfully set to '" << currentFilter <<"'!" << endl;
	cout << endl;
}

//get sorting criteria
void option3() 
{
	string sort1;
	
	cout << "[Specifying sorting criteria (current : " << currentSort << ")]" << endl;
	cout << endl;
	
	if (currentFilter == "Point2D")
	{
		cout << "\ta)\tx-ordinate value" << endl;
		cout << "\tb)\ty-ordinate value" << endl;
		cout << "\tc)\tDist. Fr Origin value" << endl;
		cout << endl;
		cout << "\tPlease enter your criteria (a-c) : ";
		cin >> sort1;
		cout << endl;
		
		transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
	
		while (!cin.good() || sort1 !="a" && sort1 !="b" && sort1 !="c")
		{
			cout <<"\tInvalid choice!" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\tPlease enter your criteria (a-c) : ";
			cin >> sort1;
			transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
			cout << endl;
		}
		
		if (sort1 == "a")
		{
			currentSort = "x-ordinate";
		}
		else if (sort1 == "b")
		{
			currentSort = "y-ordinate";
		}
		else if (sort1 == "c")
		{
			currentSort = "Dist. Fr Origin";
		}
	}
	else if (currentFilter == "Point3D")
	{
		cout << "\ta)\tx-ordinate value" << endl;
		cout << "\tb)\ty-ordinate value" << endl;
		cout << "\tc)\tz-ordinate value" << endl;
		cout << "\td)\tDist. Fr Origin value" << endl;
		cout << endl;
		cout << "\tPlease enter your criteria (a-d) : ";
		cin >> sort1;
		cout << endl;
		
		transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
	
		while (!cin.good() || sort1 !="a" && sort1 !="b" && sort1 !="c" && sort1 !="d")
		{
			cout <<"\tInvalid choice!" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\tPlease enter your criteria (a-d) : ";
			cin >> sort1;
			transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
			cout << endl;
		}
		
		if (sort1 == "a")
		{
			currentSort = "x-ordinate";
		}
		else if (sort1 == "b")
		{
			currentSort = "y-ordinate";
		}
		else if (sort1 == "c")
		{
			currentSort = "z-ordinate";
		}
		else if (sort1 == "d")
		{
			currentSort = "Dist. Fr Origin";
		}
	}
	else if (currentFilter == "Line2D")
	{
		cout << "\ta)\tPt. 1's (x, y) values" << endl;
		cout << "\tb)\tPt. 2's (x, y) values" << endl;
		cout << "\tc)\tLength value" << endl;
		cout << endl;
		cout << "\tPlease enter your criteria (a-c) : ";
		cin >> sort1;
		cout << endl;
		
		transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
	
		while (!cin.good() || sort1 !="a" && sort1 !="b" && sort1 !="c")
		{
			cout <<"\tInvalid choice!" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\tPlease enter your criteria (a-c) : ";
			cin >> sort1;
			transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
			cout << endl;
		}
		
		if (sort1 == "a")
		{
			currentSort = "Pt. 1";
		}
		else if (sort1 == "b")
		{
			currentSort = "Pt. 2";
		}
		else if (sort1 == "c")
		{
			currentSort = "Length";
		}
	}
	else if (currentFilter == "Line3D")
	{
		cout << "\ta)\tPt. 1's (x, y) values" << endl;
		cout << "\tb)\tPt. 2's (x, y) values" << endl;
		cout << "\tc)\tLength value" << endl;
		cout << endl;
		cout << "\tPlease enter your criteria (a-c) : ";
		cin >> sort1;
		cout << endl;
		
		transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
	
		while (!cin.good() || sort1 !="a" && sort1 !="b" && sort1 !="c")
		{
			cout <<"\tInvalid choice!" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\tPlease enter your criteria (a-c) : ";
			cin >> sort1;
			transform(sort1.begin(), sort1.end(), sort1.begin(), ::tolower);
			cout << endl;
		}
		
		if (sort1 == "a")
		{
			currentSort = "Pt. 1";
		}
		else if (sort1 == "b")
		{
			currentSort = "Pt. 2";
		}
		else if (sort1 == "c")
		{
			currentSort = "Length";
		}
	}
	
	cout << "\tSorting criterial successfully set to '" << currentSort <<"'!" << endl;
	cout << endl;
}

//get sorting order
void option4()
{
	string order1;
	
	cout << "[Specifying sorting criteria (current : " << currentOrder << ")]" << endl;
	cout << endl;
	cout << "\ta)\tASC (Ascending order)" << endl;
	cout << "\tb)\tDSC (Descending order)" << endl;
	cout << endl;
	cout << "\tPlease enter your criteria (a-b) : ";
	cin >> order1;
	cout << endl;
	
	transform(order1.begin(), order1.end(), order1.begin(), ::tolower);
	
	while (!cin.good() || order1 !="a" && order1 !="b")
	{
		cout <<"\tInvalid choice!" << endl;
		cout << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\tPlease enter your criteria (a-b) : ";
		cin >> order1;
		transform(order1.begin(), order1.end(), order1.begin(), ::tolower);
		cout << endl;
	}
	
	if (order1 == "a")
	{
		currentOrder = "ASC";
	}
	else if (order1 == "b")
	{
		currentOrder = "DSC";
	}

	cout << "\tSorting order successfully set to '" << currentOrder <<"'!" << endl;
	cout << endl;
}

//display data by using the classes ostream
void displayData()
{
	if (currentFilter == "Point2D")
	{
		cout << "    X    Y    Dist. Fr Origin" << endl;
		cout <<"-------------------------------------------------" << endl;
		for (auto i = point2D.begin(); i != point2D.end(); i++)
		{
			cout << (*i);
		}
	}
	else if (currentFilter == "Point3D")
	{
		cout << "    X    Y    Z    Dist. Fr Origin" << endl;
		cout <<"-------------------------------------------------" << endl;
		for (auto i = point3D.begin(); i != point3D.end(); i++)
		{
			cout << (*i);
		}
	}
	else if(currentFilter == "Line2D")
	{
		cout << " P1-X  P1-Y   P2-X  P2-Y    Length" << endl;
		cout <<"-------------------------------------------------" << endl;
		for (auto i = line2D.begin(); i != line2D.end(); i++)
		{
			cout << (*i);
		}
	}
	else if(currentFilter == "Line3D")
	{
		cout << " P1-X  P1-Y  P1-Z   P2-X  P2-Y  P2-Z  Length" << endl;
		cout <<"-------------------------------------------------" << endl;
		for (auto i = line3D.begin(); i != line3D.end(); i++)
		{
			cout << (*i);
		}
	}
}

//view data after sorting
void option5()
{
	//check if file have been configured
	if (aFile.empty())
	{
		cout << "File have not been configured yet!" << endl;
		cout << endl;
		return;
	}
	
    cout << "[View data...]" << endl;
    cout << "filtering criteria : " << currentFilter << endl;
    cout << "sorting criteria : " << currentSort << endl;
    cout << "sorting order : " << currentOrder << endl;
    cout << endl;
	
	//sorting for point2D class data
	if (currentFilter == "Point2D")
	{
		if (currentSort == "x-ordinate")
		{
			if (currentOrder == "ASC")
			{
				sort(point2D.begin(), point2D.end(), [](Point2D &pt1, Point2D &pt2)
				{
					return (pt1.getX() == pt2.getX() && pt1.getY() < pt2.getY() || pt1.getX() < pt2.getX());
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(point2D.begin(), point2D.end(), [](Point2D &pt1, Point2D &pt2)
				{
					return (pt1.getX() == pt2.getX() && pt1.getY() > pt2.getY() || pt1.getX() > pt2.getX());
				});
			}
		}
		else if (currentSort == "y-ordinate")
		{
			if (currentOrder == "ASC")
			{
				sort(point2D.begin(), point2D.end(), [](Point2D &pt1, Point2D &pt2)
				{
					return (pt1.getY() == pt2.getY() && pt1.getX() < pt2.getX() || pt1.getY() < pt2.getY());
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(point2D.begin(), point2D.end(), [](Point2D &pt1, Point2D &pt2)
				{
					return (pt1.getY() == pt2.getY() && pt1.getX() > pt2.getX() || pt1.getY() > pt2.getY());
				});
			}
		}
		else if (currentSort == "Dist. Fr Origin")
		{
			if (currentOrder == "ASC")
			{
				sort(point2D.begin(), point2D.end(), [](Point2D &pt1, Point2D &pt2)
				{
					return (pt1.getScalarValue() < pt2.getScalarValue());
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(point2D.begin(), point2D.end(), [](Point2D &pt1, Point2D &pt2)
				{
					return (pt1.getScalarValue() > pt2.getScalarValue());
				});
			}
		}
	}
	//sorting for point3D class data
	else if (currentFilter == "Point3D")
	{
		if (currentSort == "x-ordinate")
		{
			if (currentOrder == "ASC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return ((pt1.getX() == pt2.getX() && pt1.getY() == pt2.getY() && pt1.getZ() < pt2.getZ()) ||
							(pt1.getX() == pt2.getX() && pt1.getY() < pt2.getY()) ||
							(pt1.getX() < pt2.getX()));
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return ((pt1.getX() == pt2.getX() && pt1.getY() == pt2.getY() && pt1.getZ() > pt2.getZ()) ||
							(pt1.getX() == pt2.getX() && pt1.getY() > pt2.getY()) ||
							(pt1.getX() > pt2.getX()));
				});
			}
		}
		else if (currentSort == "y-ordinate")
		{
			if (currentOrder == "ASC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return ((pt1.getY() == pt2.getY() && pt1.getX() == pt2.getX() && pt1.getZ() < pt2.getZ()) ||
							(pt1.getY() == pt2.getY() && pt1.getX() < pt2.getX()) ||
							(pt1.getY() < pt2.getY()));
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return ((pt1.getY() == pt2.getY() && pt1.getX() == pt2.getX() && pt1.getZ() > pt2.getZ()) ||
							(pt1.getY() == pt2.getY() && pt1.getX() > pt2.getX()) ||
							(pt1.getY() > pt2.getY()));
				});
			}
		}
		else if (currentSort == "z-ordinate")
		{
			if (currentOrder == "ASC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return ((pt1.getZ() == pt2.getZ() && pt1.getX() == pt2.getX() && pt1.getY() < pt2.getY()) ||
							(pt1.getZ() == pt2.getZ() && pt1.getX() < pt2.getX()) ||
							(pt1.getZ() < pt2.getZ()));
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return ((pt1.getZ() == pt2.getZ() && pt1.getX() == pt2.getX() && pt1.getY() > pt2.getY()) ||
							(pt1.getZ() == pt2.getZ() && pt1.getX() > pt2.getX()) ||
							(pt1.getZ() > pt2.getZ()));
				});
			}
		}
		else if (currentSort == "Dist. Fr Origin")
		{
			if (currentOrder == "ASC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return (pt1.getScalarValue() < pt2.getScalarValue());
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(point3D.begin(), point3D.end(), [](Point3D &pt1, Point3D &pt2)
				{
					return (pt1.getScalarValue() > pt2.getScalarValue());
				});
			}
		}
	}
	//sorting for Line2D class data
	else if (currentFilter == "Line2D")
	{
		if (currentSort == "Pt. 1")
		{
			if (currentOrder == "ASC")
			{
				sort(line2D.begin(), line2D.end(), [](Line2D &ln1, Line2D &ln2)
				{
					return ((ln1.getPt1().getX() == ln2.getPt1().getX() && ln1.getPt1().getY() < ln2.getPt1().getY()) ||
							(ln1.getPt1().getX() < ln2.getPt1().getX()));
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(line2D.begin(), line2D.end(), [](Line2D &ln1, Line2D &ln2)
				{
					return ((ln1.getPt1().getX() == ln2.getPt1().getX() && ln1.getPt1().getY() > ln2.getPt1().getY()) ||
							(ln1.getPt1().getX() > ln2.getPt1().getX()));
				});
			}
		}
		else if (currentSort == "Pt. 2")
		{
			if (currentOrder == "ASC")
			{
				sort(line2D.begin(), line2D.end(), [](Line2D &ln1, Line2D &ln2)
				{
					return ((ln1.getPt2().getX() == ln2.getPt2().getX() && ln1.getPt2().getY() < ln2.getPt2().getY()) ||
							(ln1.getPt2().getX() < ln2.getPt2().getX()));
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(line2D.begin(), line2D.end(), [](Line2D &ln1, Line2D &ln2)
				{
					return ((ln1.getPt2().getX() == ln2.getPt2().getX() && ln1.getPt2().getY() > ln2.getPt2().getY()) ||
							(ln1.getPt2().getX() > ln2.getPt2().getX()));
				});
			}
		}
		else if (currentSort == "Length")
		{
			if (currentOrder == "ASC")
			{
				sort(line2D.begin(), line2D.end(), [](Line2D &ln1, Line2D &ln2)
				{
					return (ln1.getScalarValue() < ln2.getScalarValue());
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(line2D.begin(), line2D.end(), [](Line2D &ln1, Line2D &ln2)
				{
					return (ln1.getScalarValue() > ln2.getScalarValue());
				});
			}
		}
	}
	//sorting for line3D class data
	else if (currentFilter == "Line3D")
	{
		if (currentSort == "Pt. 1")
		{
			if (currentOrder == "ASC")
			{
				sort(line3D.begin(), line3D.end(), [](Line3D &ln1, Line3D &ln2)
				{
					return ((ln1.getPt1().getX() == ln2.getPt1().getX() && ln1.getPt1().getY() == ln2.getPt1().getY() && ln1.getPt1().getZ() < ln2.getPt1().getZ()) ||
							(ln1.getPt1().getX() == ln2.getPt1().getX() && ln1.getPt1().getY() < ln2.getPt1().getY()) ||
							(ln1.getPt1().getX() < ln2.getPt1().getX()));
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(line3D.begin(), line3D.end(), [](Line3D &ln1, Line3D &ln2)
				{
					return ((ln1.getPt1().getX() == ln2.getPt1().getX() && ln1.getPt1().getY() == ln2.getPt1().getY() && ln1.getPt1().getZ() > ln2.getPt1().getZ()) ||
							(ln1.getPt1().getX() == ln2.getPt1().getX() && ln1.getPt1().getY() > ln2.getPt1().getY()) ||
							(ln1.getPt1().getX() > ln2.getPt1().getX()));
				});
			}
		}
		else if (currentSort == "Pt. 2")
		{
			if (currentOrder == "ASC")
			{
				sort(line3D.begin(), line3D.end(), [](Line3D &ln1, Line3D &ln2)
				{
					return ((ln1.getPt2().getX() == ln2.getPt2().getX() && ln1.getPt2().getY() == ln2.getPt2().getY() && ln1.getPt2().getZ() < ln2.getPt2().getZ()) ||
							(ln1.getPt2().getX() == ln2.getPt2().getX() && ln1.getPt2().getY() < ln2.getPt2().getY()) ||
							(ln1.getPt2().getX() < ln2.getPt2().getX()));
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(line3D.begin(), line3D.end(), [](Line3D &ln1, Line3D &ln2)
				{
					return ((ln1.getPt2().getX() == ln2.getPt2().getX() && ln1.getPt2().getY() == ln2.getPt2().getY() && ln1.getPt2().getZ() > ln2.getPt2().getZ()) ||
							(ln1.getPt2().getX() == ln2.getPt2().getX() && ln1.getPt2().getY() > ln2.getPt2().getY()) ||
							(ln1.getPt2().getX() > ln2.getPt2().getX()));
				});
			}
		}
		else if (currentSort == "Length")
		{
			if (currentOrder == "ASC")
			{
				sort(line3D.begin(), line3D.end(), [](Line3D &ln1, Line3D &ln2)
				{
					return (ln1.getScalarValue() < ln2.getScalarValue());
				});
			}
			else if (currentOrder == "DSC")
			{
				sort(line3D.begin(), line3D.end(), [](Line3D &ln1, Line3D &ln2)
				{
					return (ln1.getScalarValue() > ln2.getScalarValue());
				});
			}
		}
	}
	
	//display the output
	displayData();
	cout << endl;
}

//a small function for option 5
void pressKey()
{
	cin.ignore();
	cout << "Press <enter> to go back to main menu...";
	cin.get();
	cout << endl;
}

//output data to file
void option6()
{
	string name;
	cout<< "Please enter filename : ";
	cin >> name;
	cout << endl;
	
	ofstream outFile;
	int counter = 0;
	
	outFile.open(name);
	
	//output based on class ostream format
	if (currentFilter == "Point2D")
	{
		outFile << "    X    Y    Dist. Fr Origin" << endl;
		outFile <<"-------------------------------------------------" << endl;
		for (auto i = point2D.begin(); i != point2D.end(); i++)
		{
			outFile << (*i);
			counter ++;
		}
	}
	else if (currentFilter == "Point3D")
	{
		outFile << "    X    Y    Z    Dist. Fr Origin" << endl;
		outFile <<"-------------------------------------------------" << endl;
		for (auto i = point3D.begin(); i != point3D.end(); i++)
		{
			outFile << (*i);
			counter ++;
		}
	}
	else if(currentFilter == "Line2D")
	{
		outFile << " P1-X  P1-Y   P2-X  P2-Y    Length" << endl;
		outFile <<"-------------------------------------------------" << endl;
		for (auto i = line2D.begin(); i != line2D.end(); i++)
		{
			outFile << (*i);
			counter ++;
		}
	}
	else if(currentFilter == "Line3D")
	{
		outFile << " P1-X  P1-Y  P1-Z   P2-X  P2-Y  P2-Z  Length" << endl;
		outFile <<"-------------------------------------------------" << endl;
		for (auto i = line3D.begin(); i != line3D.end(); i++)
		{
			outFile << (*i);
			counter ++;
		}
	}
	outFile.close();
	
	cout << counter <<" records output successfully!" << endl;
	cout << endl;
	cout << "Going back to main menu..." << endl;
	cout << endl;
}

//menu function
void displayMenu () 
{
	cout << "--------------------------------------------------" << endl;
	cout << "Welcome to Assn3 program!" << endl;
	cout << endl;
	cout << "1)\tRead in data" << endl;
	cout << "2)\tSpecify filtering criteria (current : " << currentFilter << ")]" << endl;
	cout << "3)\tSpecify sorting criteria (current : " << currentSort << ")]" << endl;
	cout << "4)\tSpecify sorting order (current : " << currentOrder << ")]" << endl;
	cout << "5)\tView data" << endl;
	cout << "6)\tStore data" << endl;
	cout << "7)\tQuit" << endl;
	cout << endl;
	cout << "Please enter your choice: ";
}

//main function
int main () 
{
	int choice = 0;
	
	//while loop 
	while (choice != 7)
	{
		//calling the menu and getting an input
		displayMenu();
		cin >> choice;
		cout << endl;
		
		//if input is bad/wrong, loop till a correct input
		while (!cin.good() || choice >7 || choice < 1)
		{
			cout <<"Invalid choice!" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			displayMenu();
			cin >> choice;
			cout << endl;	
		}
		
		//cases based on the choice input
		if (choice == 1) 
		{
			option1();
		}
		else if (choice == 2)
		{
			option2();
		}
		else if (choice == 3)
		{
			option3();
		}
		else if (choice == 4)
		{
			option4();
		}
		else if (choice == 5)
		{
			option5();
			pressKey();
		}
		else if (choice == 6)
		{
			option6();
		}
		else if (choice == 7)
		{
			cout <<"Goobye!" << endl;
		}	
	}
}