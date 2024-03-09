//all the necessary includes
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//global variables
int x1;
int x2;
int y1;
int y2;
int cityX;
int cityY;
int cityNum;
int cloudX;
int cloudY;
int cloudIndex;
int pressureX;
int pressureY;
int pressureIndex;

//vector to store the text file names
vector<string> txtFiles;

//vector pair to store the city number and city name
vector<pair<int, string >> cityInfo;

//2D array for the map
int ** array2D = nullptr;

//2D array for cloud
int ** cloudArray = nullptr;
//2D array for pressure
int ** pressureArray = nullptr;

//declares
void init2DArray (int, int);
void populate2DArray (int, int);
void displayMap(int, int);
void deMemory(int, int);
int calIndex(int & num);
void initCloud(int, int);
void initPressure(int, int);
void populateCloud(int, int);
void populatePressure(int, int);
void deMemoryCloud(int, int);
void deMemoryPressure(int, int);
void choice7(int, int);

//read in and process file function
void choice1() 
{
	fstream file;
	string fileName;
	string aLine;
	char const * skip {"-"};
	
	//prompt user to enter a file name
	cout << "[Read in and process a configuration file]" << endl;
	cout << "Please enter config filename :";
	cin >> fileName;
	cout << endl;
	
	//if file not found, then prompt error
	file.open(fileName);
	if (!file)
	{
		cerr <<"File: <"<< fileName << "> not found, returning to menu!" << endl;
		cout << endl;
		return;
	}
	
	//if file is found and open
	if (file.good())
	{
		while (getline (file, aLine))
		{
			//find gridX
			size_t pos = aLine.find("GridX_IdxRange");
			if (pos !=string::npos)
			{
				//store the line in a new var with only the range
				string line = aLine.erase(0, 15);
				//string x and y axies
				string X1;
				string X2;
				//find the positiong of '-' char
				int skip2 = line.find_first_of(skip);
				
				for (int i = 0; i < skip2; i++) 
				{
					//the purpose of this is so that we can take in
					//multiple int values, for example, 12, 13
					X1 += line[i];
				}
				
				//do for the next x value
				line = aLine.erase(0, skip2 + 1);
				
				for (int i = 0; i < line.length(); i++) 
				{
					X2 += line[i];
				}
				
				//use stoi to int the string 
				x1 = stoi(X1);
				x2 = stoi(X2);
			}
			
			//doing the same thing for Y value
			size_t pos2 = aLine.find("GridY_IdxRange");
			if (pos2 !=string::npos)
			{
				string line = aLine.erase(0, 15);
				string Y1;
				string Y2;
				int skip2 = line.find_first_of(skip);
				
				for (int i = 0; i < skip2; i++) 
				{
					Y1 += line[i];
				}
				
				line = aLine.erase(0, skip2 + 1);
				
				for (int i = 0; i < line.length(); i++) 
				{
					Y2 += line[i];
				}
				
				y1 = stoi(Y1);
				y2 = stoi(Y2);
			}
			
			//find all the other txt files, and store the file name in vector
			size_t pos3 = aLine.find(".txt");
			if (pos3 != string::npos)
			{
				//push filename into vector
				txtFiles.push_back(aLine);
			}
		}
		cout << "Reading in GridX_IdxRange :" << x1 << "-" << x2 << "... done!"<< endl;
		cout << "Reading in GridY_IdxRange :" << y1 << "-" << y2 << "... done!"<< endl;
		cout << endl;
		cout << "Storing data from input file :" << endl;
		
		//using for loop to print out all the filenames
		for (int i = 0; i < txtFiles.size(); i++)
		{
			cout << txtFiles[i] << "...done!"<< endl;
		}
		cout << endl;
		cout << "All records successfuly stored. Going back to main menu..."<< endl;
		cout << endl;
		
	//close the file
	file.close();
	}
}

//load the city data 
void loadCityFile (int **& city)
{
	fstream cityFile;
	string aLine;
	string fName;
	char const * skip_0 {"-"};
	char const * skip_1 {","};
	char const * skip_2 {"]"};
	
	//check if file exist
	if (!txtFiles[0].empty())
	{
		//open file
		cityFile.open(txtFiles[0]);
		if (cityFile.good())
		{
			while (getline(cityFile, aLine))
			{
				if (!aLine.empty())
				{
					string cityx;
					string cityy;
					string cityName2;
					string cityNum2;
					string line = aLine.erase(0,1);
					int skip_3 = line.find_first_of(skip_1);
				
					//extract x 
					for (int i = 0; i < skip_3; i++) 
					{
						cityx += line[i];
					}
					cityX = stoi(cityx);
				
					string line2 = line.erase(0, skip_3+2);
					int skip_4 = line2.find_first_of(skip_2);
				
					//extract y
					for (int i = 0; i < skip_4; i++)
					{
						cityy += line2[i];
					}
					cityY = stoi(cityy);
				
					string line3 = line2.erase(0,skip_4+2);
					int skip_5 = line3.find_first_of(skip_0);
				
					//extract the city number
					for (int i = 0; i < skip_5; i++)
					{
						cityNum2 += line3[i];
					}
					cityNum = stoi(cityNum2);
				
					//extract the city name
					string line4 = line3.erase(0, skip_5 + 1);
					for (int i = 0; i < line4.length(); i++)
					{
						cityName2+= line4[i];
					}
				
					//pushes the city number and name pair into pair vector
					cityInfo.push_back(make_pair(cityNum, cityName2));
				
					//pushes in the corresponding city number
					city[cityX][cityY] = cityNum;
				}
			}
		}
		//close file
		cityFile.close();
	}	
}

//allocate memory for 2DArray
void init2DArray(int col, int row)
{
	array2D = new int * [row +1];
	
	for (int i =0; i < row + 1; i++)
	{
		array2D[i] = new int [col + 1];
	}
}

//allocate memory for cloud array
void initCloud (int col, int row)
{
	cloudArray = new int * [row +1];
	
	for (int i =0; i < row + 1; i++)
	{
		cloudArray[i] = new int [col + 1];
	}
}

//allocate memory for pressure array
void initPressure(int col, int row)
{
	pressureArray = new int * [row +1];
	
	for (int i =0; i < row + 1; i++)
	{
		pressureArray[i] = new int [col + 1];
	}
}

//populate the array
void populate2DArray(int col, int row)
{
	for (int i = 0; i < row +1; i++)
	{
		for (int j = 0; j < col +1; j++)
		{
			//populate it with -1 as "empty"
			array2D[i][j] = -1;
		}
	}
}

//populate the cloud array
void populateCloud(int col, int row)
{
	for (int i = 0; i < row +1; i++)
	{
		for (int j = 0; j < col +1; j++)
		{
			//populate it with -1 as "empty"
			cloudArray[i][j] = -1;
		}
	}
}

//populate the pressure array
void populatePressure(int col, int row)
{
	for (int i = 0; i < row +1; i++)
	{
		for (int j = 0; j < col +1; j++)
		{
			//populate it with -1 as "empty"
			pressureArray[i][j] = -1;
		}
	}
}

//display the city map
void displayMap(int col, int row)
{
	printf("%4s", "#");
	
	for (int i = 0; i < col; i++)
	{
		printf("%2s", "#");
	}
	
	printf("%2s%2s\n", "#", "#");
	
	//print indexes
	for (int k = row; k >= 0; k--)
	{
		printf("%2d%2s", k, "#");
		for (int m = 0; m < col + 1; m++)
		{
			if (array2D[m][k] < 0) {
				printf("%2s", " ");
			}
			else 
			{
				printf("%2d", array2D[m][k]);
			}
		}
		printf("%2s\n", "#");
	}
	
	printf("%4s", "#");
	
	for (int i = 0; i < col; i++)
	{
		printf("%2s", "#");
	}
	
	printf("%2s%2s\n","#","#");
	printf("%4s", " ");
	
	for (int i = 0; i < col +1; i++) 
	{
		printf("%2d", i);
	}
	cout<< endl;
}

//safely deallocate memory
void deMemory(int col, int row)
{
	if (col <= 0)
	{
		return;
	}
	
	for (int i = 0; i < row +1; i ++)
	{
		delete[] array2D[i];
	}
	delete [] array2D;
}

//safely deallocate memory for cloud array
void deMemoryCloud(int col, int row)
{
	if (col <= 0)
	{
		return;
	}
	
	for (int i = 0; i < row +1; i ++)
	{
		delete[] cloudArray[i];
	}
	delete [] cloudArray;
}

//safely deallocate memory for pressure array
void deMemoryPressure(int col, int row)
{
	if (col <= 0)
	{
		return;
	}
	
	for (int i = 0; i < row +1; i ++)
	{
		delete[] pressureArray[i];
	}
	delete [] pressureArray;
}

void choice2() 
{
	//if file found, then perform all these functions
	if (!txtFiles.empty())
	{
		init2DArray(y2, x2);
		populate2DArray(y2, x2);
		loadCityFile(array2D);
		displayMap(x2, y2);
		deMemory(y2, x2);
		cout << endl;
	}
	else
	{
		//if file empty prompt error message
		cout << "File not configured, please configure first! " << endl;
		cout << endl;
		return;
	}	
}

//load the cloud index data
void loadCloudFile (int **& cloud)
{
	fstream cloudFile;
	string aLine;
	string fName;
	
	char const * skip_0 {"-"};
	char const * skip_1 {","};
	char const * skip_2 {"]"};
	
	if (!txtFiles[1].empty())
	{
		//open file and get line by line
		cloudFile.open(txtFiles[1]);
		if (cloudFile.good())
		{
			while (getline(cloudFile, aLine))
			{
				if (!aLine.empty())
				{
					string cloudx;
					string cloudy;
					string cloudIndex2;
				
					string line = aLine.erase(0,1);
					int skip_3 = line.find_first_of(skip_1);
				
					//extact x
					for (int i = 0; i < skip_3; i++)
					{
						cloudx += line[i];
					}
					cloudX = stoi(cloudx);
				
					string line2 = line.erase(0, skip_3 +2);
					int skip_4 = line2.find_first_of(skip_2);
					
					//extract y
					for (int i = 0; i < skip_4; i++)
					{
						cloudy += line2[i];
					}
					cloudY = stoi(cloudy);
				
					string line3 = line2.erase(0, skip_4+2);
				
					//extra index
					for (int i = 0; i < line3.length(); i++)
					{
						cloudIndex2 += line3[i];
					}
					cloudIndex = stoi(cloudIndex2);
				
					//punches data into the array
					cloud[cloudX][cloudY] = calIndex(cloudIndex);
					//calIndex function will calculate the index
				}
			}
		}
		cloudFile.close();
	}
	
	
}

//calculate the index
int calIndex(int & num)
{
	int index;
	
	if (num < 10)
	{
		index = 0;
	}
	else if (num < 20)
	{
		index = 1;
	}
	else if (num < 30)
	{
		index = 2;
	}
	else if (num < 40)
	{
		index = 3;
	}
	else if (num < 50)
	{
		index = 4;
	}
	else if (num < 60)
	{
		index = 5;
	}
	else if (num < 70)
	{
		index = 6;
	}
	else if (num < 80)
	{
		index = 7;
	}
	else if (num < 90)
	{
		index = 8;
	}
	else if (num < 100)
	{
		index = 9;
	}
	
	//return the calculated index
	return index;
}

void choice3 ()
{
	//if file found, then perform all these functions
	if (!txtFiles.empty())
	{
		init2DArray(y2, x2);
		populate2DArray(y2, x2);
		loadCloudFile(array2D);
		displayMap(x2,y2);
		deMemory(y2, x2);
		cout << endl;
	}
	else
	{
		//else if file not found, prompt message
		cout << "File not configured, please configure first!" << endl;
		cout << endl;
		return;
	}	
}

//load cloud data in original index
void loadCloudFileLMH (int **& cloud)
{
	fstream cloudFile;
	string aLine;
	string fName;
	
	char const * skip_0 {"-"};
	char const * skip_1 {","};
	char const * skip_2 {"]"};
		
	if (!txtFiles[1].empty())
	{
		//open file and get line by line
		cloudFile.open(txtFiles[1]);
		if (cloudFile.good())
		{
			while (getline(cloudFile, aLine))
			{
				if (!aLine.empty())
				{
					string cloudx;
					string cloudy;
					string cloudIndex2;
				
					string line = aLine.erase(0,1);
					int skip_3 = line.find_first_of(skip_1);
				
					//extact x
					for (int i = 0; i < skip_3; i++)
					{
						cloudx += line[i];
					}
					cloudX = stoi(cloudx);
				
					string line2 = line.erase(0, skip_3 +2);
					int skip_4 = line2.find_first_of(skip_2);
				
					//extract y
					for (int i = 0; i < skip_4; i++)
					{
						cloudy += line2[i];
					}
					cloudY = stoi(cloudy);
				
					string line3 = line2.erase(0, skip_4+2);
				
					//extra index
					for (int i = 0; i < line3.length(); i++)
					{
						cloudIndex2 += line3[i];
					}
					cloudIndex = stoi(cloudIndex2);
				
					//punches in the original index
					cloud[cloudX][cloudY] = cloudIndex;
				}
			}
		}
		cloudFile.close();
	}
}

//display for LMH
void displayLMH(int col, int row)
{
	printf("%4s", "#");
	
	for (int i = 0; i < col; i++)
	{
		printf("%2s", "#");
	}
	
	printf("%2s%2s\n", "#", "#");
	
	//print based on LMH 
	for (int k = row; k >= 0; k--)
	{
		printf("%2d%2s", k, "#");
		for (int m = 0; m < col + 1; m++)
		{
			if (array2D[m][k] <0) 
			{
				printf("%2s", " ");
			}
			else if (array2D[m][k] < 35) 
			{
				printf("%2s", "L");
			}
			else if (array2D[m][k] < 65)
			{
				printf("%2s", "M");
			}
			else if (array2D[m][k] < 100)
			{
				printf("%2s", "H");
			}
		}
		printf("%2s\n", "#");
	}
	
	printf("%4s", "#");
	
	for (int i = 0; i < col; i++)
	{
		printf("%2s", "#");
	}
	
	printf("%2s%2s\n","#","#");
	
	printf("%4s", " ");
	
	for (int i = 0; i < col +1; i++) 
	{
		printf("%2d", i);
	}
	cout<< endl;
}

void choice4 ()
{
	//if file found, then perform all these functions
	if (!txtFiles.empty())
	{
		init2DArray(y2, x2);
		populate2DArray(y2, x2);
		loadCloudFileLMH(array2D);
		displayLMH(x2,y2);
		deMemory(y2, x2);
	}
	else
	{
		//else if file not found, prompt message
		cout << "File not configured, please configure first!" << endl;
		cout << endl;
		return;
	}
}

//load the pressure index 
void loadPressure (int **& pressure)
{
	fstream pressureFile;
	string aLine;
	string fName;
	
	char const * skip_0 {"-"};
	char const * skip_1 {","};
	char const * skip_2 {"]"};
	
	if (!txtFiles[2].empty())
	{
		//open file and get line by line
		pressureFile.open(txtFiles[2]);
		if (pressureFile.good())
		{
			while (getline(pressureFile, aLine))
			{
				if (!aLine.empty())
				{
					string pressurex;
					string pressurey;
					string pressureIndex2;
				
					string line = aLine.erase(0,1);
					int skip_3 = line.find_first_of(skip_1);
				
					//extact x
					for (int i = 0; i < skip_3; i++)
					{
						pressurex += line[i];
					}
					pressureX = stoi(pressurex);
				
					string line2 = line.erase(0, skip_3 +2);
					int skip_4 = line2.find_first_of(skip_2);
				
					//extract y
					for (int i = 0; i < skip_4; i++)
					{
						pressurey += line2[i];
					}
					pressureY = stoi(pressurey);
				
					string line3 = line2.erase(0, skip_4+2);
				
					//extra index
					for (int i = 0; i < line3.length(); i++)
					{
						pressureIndex2 += line3[i];
					}
					pressureIndex = stoi(pressureIndex2);
				
					//punches the calculated pressure index
					pressure[pressureX][pressureY] = calIndex(pressureIndex);
				}
			}
		}
		pressureFile.close();
	}
}

//load the original pressure index
void loadPressureLMH (int **& pressure)
{
	fstream pressureFile;
	string aLine;
	string fName;
	
	char const * skip_0 {"-"};
	char const * skip_1 {","};
	char const * skip_2 {"]"};

	if(!txtFiles[2].empty())
	{
		//open file and get line by line
		pressureFile.open(txtFiles[2]);
		if (pressureFile.good())
		{
			while (getline(pressureFile, aLine))
			{
				if (!aLine.empty())
				{
					string pressurex;
					string pressurey;
					string pressureIndex2;
				
					string line = aLine.erase(0,1);
					int skip_3 = line.find_first_of(skip_1);
				
					//extact x
					for (int i = 0; i < skip_3; i++)
					{
						pressurex += line[i];
					}
					pressureX = stoi(pressurex);
				
					string line2 = line.erase(0, skip_3 +2);
					int skip_4 = line2.find_first_of(skip_2);
				
					//extract y
					for (int i = 0; i < skip_4; i++)
					{
						pressurey += line2[i];
					}
					pressureY = stoi(pressurey);
				
					string line3 = line2.erase(0, skip_4+2);
				
					//extra index
					for (int i = 0; i < line3.length(); i++)
					{
						pressureIndex2 += line3[i];
					}
					pressureIndex = stoi(pressureIndex2);
				
					//punches in the original index
					pressure[pressureX][pressureY] = pressureIndex;
				}
			}
		}
		pressureFile.close();
	}
}

void choice5 ()
{
	//if file found, then perform all these functions
	if (!txtFiles.empty())
	{
		init2DArray(y2, x2);
		populate2DArray(y2, x2);
		loadPressure(array2D);
		displayMap(x2,y2);
		deMemory(y2, x2);
		cout << endl;
	}
	else
	{
		//else if file not found, prompt message
		cout << "File not configured, please configure first!" << endl;
		cout << endl;
		return;
	}
}

void choice6 ()
{
	//if file found, then perform all these functions
	if (!txtFiles.empty())
	{
		init2DArray(y2, x2);
		populate2DArray(y2, x2);
		loadPressureLMH(array2D);
		displayLMH(x2,y2);
		deMemory(y2, x2);
		cout << endl;
	}
	else
	{
		//else if file not found, prompt message
		cout << "File not configured, please configure first!" << endl;
		cout << endl;
		return;
	}
}

void choice7 (int col, int row)
{
	//local variables for calculations later
	int counter = 0;
	double cloud = 0;
	double pressure = 0;
	double cloudAvg = 0;
	double pressureAvg = 0;
	
	//boolean to stop adding repeated surrounding grip areas
	bool added = false;

	//local vectors for storing data
	vector <double> totalCloud;
	vector <double> totalPressure;
	vector <string> cloudSymbol;
	vector <string> pressureSymbol;
	
	//if files not configured, then prompt error
	if (txtFiles.empty())
	{
		cout << "File not configured, please configure first!" << endl;
		cout << endl;
		return;
	}
	//else if files have been configured, display summary
	else
	{
		cout << "Weather Forecast Summary Report" << endl;
		cout <<"------------------------------------------------" << endl;
		//allocate memories for all the 2D Arrays
		init2DArray(y2, x2);
		initCloud(y2, x2);
		initPressure(y2,x2);
		
		//populate all the 2D Arrays
		populate2DArray(y2, x2);
		populateCloud(y2,x2);
		populatePressure(y2, x2);
		
		//punches all the data into the 2D Arrays
		loadCityFile(array2D);
		loadCloudFileLMH(cloudArray);
		loadPressureLMH(pressureArray);		
		
		//this is to sort the pair vector in descending order
		sort(cityInfo.rbegin(), cityInfo.rend());
		//remove any duplicated pairs
		cityInfo.erase(unique(cityInfo.begin(), cityInfo.end()), cityInfo.end());
		
		//extract the data with the corresponding city number
		for (int i = 0; i < cityInfo.size(); i++)
		{
			for (int k = 0; k < col +1 ; k++)
			{
				for (int m = 0; m < row + 1; m++)
				{
					added = false;
					//check if current index equal to city number
					if (array2D[k][m] == cityInfo[i].first)
					{
						counter ++;
						//because I have set empty arrays as -1
						//this checker will prevent from adding the -1
						if (cloudArray[k][m] >=0)
						{
							cloud += cloudArray[k][m];
						}
						
						if (pressureArray[k][m] >=0)
						{
							pressure += pressureArray[k][m];
						}
					}
					else if (array2D[k][m] != cityInfo[i].first)
					{
						if (k -1 >= 0 && m + 1 <= row) 
						{
							if (array2D[k-1][m+1] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}
						
						if (m + 1 <= row) 
						{
							if (array2D[k][m+1] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}
						
						if (m + 1 <= row && k + 1 <= col) 
						{
							if (array2D[k+1][m+1] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}
						
						if (k-1 >= 0) 
						{
							if (array2D[k-1][m] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}
						
						if (k + 1 <= col) 
						{
							if (array2D[k+1][m] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}
						
						if (k-1 >=0 && m-1 >= 0) 
						{
							if (array2D[k-1][m-1] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}
						
						if (m-1 >=0) 
						{
							if (array2D[k][m-1] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}
						
						if (m-1 >= 0 && k+1 <= col) 
						{
							if (array2D[k+1][m-1] == cityInfo[i].first)
							{
								if (added == false)
								{
									counter ++;
									added = true;
									if (cloudArray[k][m] >=0)
									{
										cloud += cloudArray[k][m];
									}
									if (pressureArray[k][m] >=0)
									{
										pressure += pressureArray[k][m];
									}
								}
							}
						}	
					}
				}
			}
			
			//compute the average for cloud and pressure
			cloudAvg = cloud / counter;
			pressureAvg = pressure / counter;
			//store all the data in vector
			totalCloud.push_back(cloudAvg);
			totalPressure.push_back(pressureAvg);
			
			//variables for LMH
			string cloudLMH;
			string pressureLMH;
			
			//calculation which LMH for cloud
			if (cloudAvg < 35)
			{
				cloudLMH = "L";
			}
			else if (cloudAvg < 65)
			{
				cloudLMH = "M";
			}
			else if (cloudAvg < 100)
			{
				cloudLMH = "H";
			}
			
			//pushes the cloud LMH into vector
			cloudSymbol.push_back(cloudLMH);
			
			//calculate which LMH for pressure
			if (pressureAvg < 35)
			{
				pressureLMH = "L";
			}
			else if (pressureAvg < 65)
			{
				pressureLMH = "M";
			}
			else if (cloudAvg < 100)
			{
				pressureLMH = "H";
			}
			
			//pushes the pressure LMH into vector
			pressureSymbol.push_back(pressureLMH);
			
			//reset all the values back to 0 for next city
			counter = 0;
			cloud = 0;
			pressure = 0;
			cloudAvg = 0;
			pressureAvg = 0;	
		}
		
		//deallocate memories for the arrays
		deMemoryPressure(y2, x2);
		deMemory(y2, x2);
		deMemoryCloud(y2,x2);
		
		//printing out the summary
		for (int i = 0; i < cityInfo.size(); i++)
		{
			cout <<"City Name : " << cityInfo[i].second << endl;
			cout <<"City ID   : " << cityInfo[i].first << endl;
			cout << fixed << setprecision(2) <<"Ave. Cloud Cover (ACC)    : " << totalCloud[i]<<" (" << cloudSymbol[i] << ")" <<endl;
			cout << fixed << setprecision(2) <<"Ave. Pressure    (AP)     : " << totalPressure[i] << " ("<< pressureSymbol[i] << ")" << endl;
			
			if (pressureSymbol[i] == "L" && cloudSymbol[i] == "H")
			{
				cout <<"Probability of Rain (%)   : 90.00" << endl;
				cout << "~~~~" << endl;
				cout << "~~~~~" << endl;
				cout << "\\\\\\\\\\" << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "L" && cloudSymbol[i] == "M")
			{
				cout <<"Probability of Rain (%)   : 80.00" << endl;
				cout << "~~~~" << endl;
				cout << "~~~~~" << endl;
				cout << " \\\\\\\\" << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "L" && cloudSymbol[i] == "L")
			{
				cout <<"Probability of Rain (%)   : 70.00" << endl;
				cout << "~~~~" << endl;
				cout << "~~~~~" << endl;
				cout << "  \\\\\\" << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "M" && cloudSymbol[i] == "H")
			{
				cout <<"Probability of Rain (%)   : 60.00" << endl;
				cout << "~~~~" << endl;
				cout << "~~~~~" << endl;
				cout << "   \\\\" << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "M" && cloudSymbol[i] == "M")
			{
				cout <<"Probability of Rain (%)   : 50.00" << endl;
				cout << "~~~~" << endl;
				cout << "~~~~~" << endl;
				cout << "    \\" << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "M" && cloudSymbol[i] == "L")
			{
				cout <<"Probability of Rain (%)   : 40.00" << endl;
				cout << "~~~~" << endl;
				cout << "~~~~~" << endl;
				cout << " " << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "H" && cloudSymbol[i] == "H")
			{
				cout <<"Probability of Rain (%)   : 30.00" << endl;
				cout << "~~~" << endl;
				cout << "~~~~" << endl;
				cout << " " << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "H" && cloudSymbol[i] == "M")
			{
				cout <<"Probability of Rain (%)   : 20.00" << endl;
				cout << "~~" << endl;
				cout << "~~~" << endl;
				cout << " " << endl;
				cout << endl;
			}
			else if (pressureSymbol[i] == "H" && cloudSymbol[i] == "L")
			{
				cout <<"Probability of Rain (%)   : 10.00" << endl;
				cout << "~" << endl;
				cout << "~~" << endl;
				cout << " " << endl;
				cout << endl;
			}
		}
	}	
}

// press enter to continue function
void pressEnter() 
{
	cin.ignore();
	cout << "Press <enter> to go back to main menu..." << endl;
	cin.get();
}

// menu options
void displayMenu () 
{
	cout << "--------------------------------------------------" << endl;
	cout << "Welcome to Weather Information Processing System! " << endl;
	cout << endl;
	cout << "1)\tRead in and process a configuration file" << endl;
	cout << "2)\tDisplay city map" << endl;
	cout << "3)\tDisplay cloud coverage map (cloudiness index)" << endl;
	cout << "4)\tDisplay cloud coverage map (LMH symbols)" << endl;
	cout << "5)\tDisplay atmospheric pressure map (pressure index)" << endl;
	cout << "6)\tDisplay atmospheric pressure map (LMH symbols)" << endl;
	cout << "7)\tShow weather forecast summary report" << endl;
	cout << "8)\tQuit" << endl;
	cout << endl;
	cout << "Please enter your choice: ";
} 

//main function
int main () 
{
	int choice = 0;
	
	//while loop 
	while (choice != 8)
	{
		//calling the menu and getting an input
		displayMenu();
		cin >> choice;
		cout << endl;
		
		//if input is bad/wrong, loop till a correct input
		while (!cin.good() || choice >8 || choice < 1)
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
			choice1();
		}
		else if (choice == 2)
		{
			choice2();
			pressEnter();
		}
		else if (choice == 3)
		{
			choice3();
			pressEnter();
		}
		else if (choice == 4)
		{
			choice4();
			pressEnter();
		}
		else if (choice == 5)
		{
			choice5();
			pressEnter();
		}
		else if (choice == 6)
		{
			choice6();
			pressEnter();
		}
		else if (choice == 7)
		{
			choice7(x2,y2);
			pressEnter();
		}
		else if (choice == 8)
		{
			cout<< "Goobye!" << endl;
		}	
	}
}