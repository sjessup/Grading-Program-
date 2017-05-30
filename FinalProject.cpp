//FinalProject.cpp - create a program that allows you to enter assignment and test score 
//and stores them and displays a grade for you class.  You can also delete score.  
//It will also cacualte what score you need to recives what letter grade for your assignment.
//Created/revised by Swazey on 5-24-17 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

//Function prototypes 
int getChoice();
void addScore();
void displayTotal();
void deleteTotal();
void getGrade();
void showScores();

int main()

{
	int choice = 0;
	
	do 
	{
		//get user's menu choice 
		choice = getChoice();
		if(choice == 1)
		{
			addScore();
		}else if(choice == 2)
		{
			displayTotal();
		}else if(choice == 3)
		{
			deleteTotal();
		}else if(choice == 4)
		{
			getGrade();
		}else if(choice == 5)
		{
			showScores();
		}//end if 
	}while(choice != 6);
	
	return 0; 
}//end of main function 

int getChoice()
{
	//displays menu and returns choice
	
	int menuChoice = 0; 
	cout << endl << "Menu Options" << endl; 
	cout << "1 Add Assignment Scores" << endl; 
	cout << "2 See your current grade" << endl; 
	cout << "3 Delete your assignment scores" << endl; 
	cout << "4 See what grade you need on your next assignment to recieve each letter grade" << endl;
	cout << "5 See your assignments and grades" << endl;
	cout << "6 Exit the program" << endl; 
	cin >> menuChoice;
	cin.ignore(100, '\n');
	cout << endl; 
	return menuChoice;  
}// end of getChoice Function 

void addScore()
{
	//saves test scores to a sequential access file 
	string name = "";
	double score = 0.0;
	double outOf = 0.0;
	ofstream outFile;
	
	//open file for append 
	outFile.open("FinalProject.txt", ios::app);
	
	if(outFile.is_open())
	{
		cout << "Enter your score (Enter -1 to stop): ";
		cin >> score; 
		cin.ignore(100, '\n');
		
		while(score != -1)
		{
			cout << "Enter how much your assignment is out of: ";
			cin >> outOf;
			cin.ignore(100, '\n');
			
			cout << "Enter the Assignment's Name: ";
			getline(cin, name);
			
			outFile << name << '#' << score << '#' << outOf << endl ;
			
			cout << "Enter your score (Enter -1 to stop): ";
			cin >> score; 
			cin.ignore(100, '\n');
			
		}//end while 
		//close the file 
		outFile.close();
	}else 
	{
		cout << "File could not be opened." << endl;
	}//end if 
}//end of addScore Function 

void displayTotal()
{
	//calcualtes and displays grade 
	
	string name = ""; 
	double score = 0.0;
	double outOf = 0.0;
	double total = 0.0;
	double totalOutOf = 0.0;
	double grade = 0.0;
	ifstream inFile;
	
	//Open file for input 
	inFile.open("FinalProject.txt");
	
	if(inFile.is_open())
	{
		getline(inFile, name, '#');
		inFile >> score; 
		inFile.ignore(1);
		inFile >> outOf;
		inFile.ignore();
		
		while(!inFile.eof())
		{
			total += score;
			totalOutOf += outOf;
			
			getline(inFile, name, '#');
			inFile >> score;
			inFile.ignore(1);
			inFile >> outOf; 
			inFile.ignore();
		}//end while 
		//close the file 
		inFile.close();
		grade = (total / totalOutOf)*100; 
		if(grade >= 90)
		{
			cout << "You are getting an A+." << grade << "%" << endl;
			 
		}else if(grade >= 85 && grade <= 89)
		{
			cout << "You are getting an A." << grade << "%" << endl; 
			
		}else if(grade >= 80 && grade <= 84)
		{
			cout << "You are getting an A-." << grade << "%" <<  endl; 
			 
		}else if(grade >= 76 && grade <= 79)
		{
			cout << "You are getting a B+." << grade << "%" << endl;
			
		}else if(grade >= 73 && grade <= 75)
		{
			cout << "You are getting a B." << grade << "%" << endl; 
			
		}else if(grade >= 70 && grade <= 72)
		{
			cout << "You are getting a B-." << grade << "%" << endl;
			
		}else if(grade >= 67 && grade <= 69)
		{
			cout << "You are getting a C+." << grade << "%" << endl; 
			
		}else if(grade >= 64 && grade <= 66)
		{
			cout << "You are getting a C." << grade << "%" << endl;
			
		}else if(grade >= 60 && grade <= 63)
		{
			cout << "You are getting a C-." << grade << "%" << endl; 
						
		}else if(grade >= 55 && grade <= 59)
		{
			cout << "You are getting a D+." << grade << "%" << endl; 
			
		}else if(grade >= 50 && grade <= 54)
		{
			cout << "You are getting a D." << grade << "%" << endl;
			
		}else if(grade >= 0 && grade <= 49)
		{
			cout << "You are getting a F." << grade << "%" << endl;
			
		}//end if 
	}//end while 
	cout << "An A+ is between 90% and 100%. " << endl;
	cout << "An A is between 85% and 89%. " << endl;	
	cout << "An A- is between 80% and 84%. " << endl;
	cout << "A B+ is between 76% and 79%. " << endl;
	cout << "A B is between 73% and 75%. " << endl;
	cout << "A B- is between 70% and 72%. " << endl;
	cout << "A C+ is between 67% and 69%. " << endl;
	cout << "A C is between 64% and 66%. " << endl;
	cout << "A C- is between 60% and 63%. " << endl;		
	cout << "A D+ is between 55% and 59%. " << endl;
	cout << "A D is between 50% and 54%. " << endl;
	cout << "A F is between 0% and 49%. " << endl;		
	
	}//end of displayTotal Function 

void deleteTotal()
{
	string name = ""; 
	string a = "";
	string score = "";
	string outOf = "";
	ifstream inFile; 
	inFile.open("FinalProject.txt");
	ofstream outFile; 
	outFile.open("FinalProject2.txt");
	
	cout << "Enter the Assignments name that you would like to delete. (Type it exactly how it is shown in the File.) ";
	getline(cin, a);
	//cin.ignore(100, '\n');
	
	if(inFile.is_open())
	{if(outFile.is_open())
	{
		while(!inFile.eof())
		{
			getline(inFile, name, '#');
			getline(inFile, score, '#');
			getline(inFile, outOf);
			if(name != a && name != "")
			{
				outFile << name << "#" << score << "#" << outOf << endl; 
			}
		
		}
	}else 
	{
		cout << "Out File could not be opened. " << endl;
	}
	}else 
	{
		cout << "In File could not be opened. " << endl; 
	}
		inFile.close();
		outFile.close();

	rename("FinalProject2.txt", "FinalProject.txt");

	
	
}//end of deleteTotal Function 

void getGrade()
{
	string name = ""; 
	double score = 0.0;
	double outOf = 0.0;
	double total = 0.0;
	double totalOutOf = 0.0;
	double grade = 0.0;
	double a = 0.0;
	double b = 0.0; 
	double c = 0.0;
	double d = 0.0;
	ifstream inFile;
	
	//Open file for input 
	inFile.open("FinalProject.txt");
	
	if(inFile.is_open())
	{
		getline(inFile, name, '#');
		inFile >> score; 
		inFile.ignore(1);
		inFile >> outOf;
		inFile.ignore();
		
		while(!inFile.eof())
		{
			total += score;
			totalOutOf += outOf;
			
			getline(inFile, name, '#');
			inFile >> score;
			inFile.ignore(1);
			inFile >> outOf; 
			inFile.ignore();
		}//end while 
		//close the file 
		inFile.close();
		
		cout << "Find out how many points you need to get which letter grade." << endl; 
		cout << "Enter how many points your assignment is out of. ";
		cin >> a;
		
		
		b = totalOutOf + a; 
		
		c = b * .90;
		d = c - total;
		if (d < 0) {
			d = 0;
		}
		
			if(d < a)
			{
				cout << "Score you need to recieve an A+.: " << d << endl; 
			}else  
			{ 
				cout << "Your grade is too low to recive an A+." << endl;
			}
			
		c = 0;
		d = 0; 
		
		c = b * .85; 
		d = c - total;
		if (d < 0) {
			d = 0;
		}
		
			if(d < a)
			{
				cout << "Score you need to receive an A.: " << d << endl;
			} else 
			{
				cout << "Yout grade is too low to receive an A. " << endl; 
			}
			
		c = 0; 
		d = 0; 
		
		c = b * .80;
		d = c - total;
		if (d < 0) {
			d = 0;
		} 
		
			if(d < a) 
			{
				cout << "Score you need to receive an A-.: " << d << endl; 
			}else 
			{
				cout << "Your grade is too low to receive an A-. " << endl; 
			}
			
		c = 0; 
		d = 0; 
		
		c = b * .76; 
		d = c - total;
		if (d < 0) {
			d = 0;
		} 
		
			if(d < a)
			{
				cout << "Score you need to recieve a B+.: " << d << endl; 
			}else 
			{
				cout << "Your grade is too low to receive a B+. " << endl; 
			} 
			
		c = 0; 
		d = 0; 
			
		c = b * .73; 
		d = c - total;
		if (d < 0) {
			d = 0;
		} 
		
			if(d < a)
			{
				cout << "Score you need to recieve a B.: " << d << endl; 
			}else 
			{
				cout << "Your grade is too low to receive a B. " << endl; 
			}
			
		c = 0; 
		d = 0; 
			
		c = b * .70; 
		d = c - total;
		if (d < 0) {
			d = 0;
		} 
		
			if(d < a)
			{
				cout << "Score you need to recieve a B-.: " << d << endl; 
			}else 
			{
				cout << "Your grade is too low to receive a B-. " << endl; 
			}
			
		c = 0; 
		d = 0; 
			
		c = b * .67; 
		d = c - total;
		if (d < 0) {
			d = 0;
		} 
		
			if(d < a)
			{
				cout << "Score you need to recieve a C+.: " << d << endl;
			}else 
			{ 
				cout << "Your grade is too low to receive a C+. " << endl; 
			}
			
		c = 0; 
		d = 0; 
			
		c = b * .64; 
		d = c - total;
		if (d < 0) {
			d = 0;
		} 
		
			if(d < a)
			{
				cout << "Score you need to recieve a C.: " << d << endl;
			}else 
			{
				cout << "Yout grade is too low to receive a C. " << endl; 
			}
			
		c = 0; 
		d = 0; 
			
		c = b * .60; 
		d = c - total; 
		if (d < 0) {
			d = 0;
		}
		
			if(d < a)
			{
				cout << "Score you need to recieve a C-.: " << d << endl; 
			}else 
			{ 
				cout << "Your grade is too low to receive a C-. " << endl; 
			}
			
		c = 0; 
		d = 0; 
			
		c = b * .55; 
		d = c - total; 
		if (d < 0) {
			d = 0;
		}
		
			if(d < a)
			{
				cout << "Score you need to recieve a D+.: " << d << endl;   
			}else 
			{ 
				cout << "Your grade is too low to receive a D+. " << endl; 
			}
			
		c = 0; 
		d = 0; 
			
		c = b * .50; 
		d = c - total; 
		if (d < 0) {
			d = 0;
		}
		
			if(d < a)
			{
				cout << "Score you need to recieve a D.: " << d << endl;
			}else 
			{
				cout << "Your grade is too low to receive a D. " << endl; 
			}
		 
		c = 0; 
		d = 0; 
			
		c = b * .49; 
		d = c - total;
		if (d < 0) {
			d = 0;
		}
		
			if(d < a)
			{
				cout << "Score you need to recieve a F.: " << d << endl;
			} 
			
	}else 
	{
		cout << "File could not be opened. " << endl; 
	}// end if 
}//end of getGrade Function 

void showScores()
{
	string name = ""; 
	string score = "";
	string outOf = "";

	ifstream inFile;
	
	inFile.open("FinalProject.txt");
		
		if(inFile.is_open())
		{
			while(!inFile.eof())
			{
				getline(inFile, name, '#');
				getline(inFile, score, '#');
				getline(inFile, outOf);
				
				if( name != "")
					cout << name << " " << score << "/" << outOf << endl; 
				
			}//end while 
			inFile.close();
		}//end if 
}//end of showScore Function 
