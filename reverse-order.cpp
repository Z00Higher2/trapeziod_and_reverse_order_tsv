// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 3D
// Write a program reverse-order.cpp which asks the user to input two dates (earlier date then later date). 
// The program should report the West basin elevation for all days in the interval in the reverse chronological order (from the later date to the earlier).


#include <iostream>
#include <fstream> // needed to read the file
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;

int main() 
{
    string earlyDate, laterDate, date; //initializing string variables
    double eastSt, eastEl, westSt, westEl;
    int dateRange = 0;
    string dates[1000]; // array to store dates
    double westElValues[1000]; // array to store westEl values
    int count = 0; // count of dates read

    cout << "Enter earlier date: "; //getting the starting date
    cin >> earlyDate;
    cout << "Enter later date: "; //getting the ending date
    cin >> laterDate;

    ifstream fin("Current_Reservoir_Levels.tsv"); //opening the file
    
    string junk;
    getline(fin, junk);
 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) //reading the file
    {
        fin.ignore(INT_MAX, '\n'); //ignoring the rest of the lines

        if(date == earlyDate)
        {
            dateRange = 1; //Once the date is found, set the dateRange variable to 1 at that time.
        }
        if(date > laterDate)
        {
            dateRange = 0; //Once the date is found, set the dateRange variable to 0 at that time.
        }

        if(dateRange == 1) //This code only executes if the dateRange variable is set to 1 for those dates in the interval.
        { 
            dates[count] = date; // store date in the array
            westElValues[count] = westEl; // store westEl value in the array
            count++; // increment count
        }
    }
    fin.close(); //close the file

    // print the dates and westEl values in reverse order
    for(int i = count - 1; i >= 0; i--)
    {
        cout << dates[i] << " " << westElValues[i] << " ft" << endl;
    }

    return 0;
}