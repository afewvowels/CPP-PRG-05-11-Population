//
//  main.cpp
//  PRG-5-11-Population
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that will predict the size of a population of organisms. The program
//  should ask the user for the starting number of organisms, their average daily population
//  increase (as a percentage), and the number of days they will multiply. A loop
//  should display the size of the population for each day.
//
//  Input Validation: Do not accept a number less than 2 for the starting size of the population.
//  Do not accept a negative number for average daily population increase. Do not
//  accept a number less than 1 for the days they will multiply.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int intDays,
        intOrganisms; // Can't have fractional number of organisms
                      // remainder of operation will be discarded, not rounded.
    
    float fltPercentageIncrease;
    
    cout << "Please enter a starting number of organisms:\n";
    cin >> intOrganisms;
    
    while(!cin || intOrganisms < 2 || intOrganisms > 1000000)
    {
        cout << "Please select a starting population with a size of 2 or greater:\n";
        cin.clear();
        cin.ignore();
        cin >> intOrganisms;
    }
    
    cout << "Please enter a whole number percentage for the population to increase daily:\n";
    cin >> fltPercentageIncrease;
    
    while(!cin || fltPercentageIncrease < 0 || fltPercentageIncrease > 500)
    {
        cout << "Please select a percentage from 0 to 100:\n";
        cin.clear();
        cin.ignore();
        cin >> fltPercentageIncrease;
    }
    
    cout << "Please enter a total number of days for the organisms to multiply:\n";
    cin >> intDays;
    
    while(!cin || intDays < 1 || intDays > 100)
    {
        cout << "Please select a number of days greater than 1 and less than 100:\n";
        cin.clear();
        cin.ignore();
        cin >> intDays;
    }
    
    //Convert whole number percentage to decimal and add 100%
    //This will prevent having to add the percentage to the total number
    //of organisms and will allow for a single operation.
    fltPercentageIncrease = fltPercentageIncrease / 100.0f;
    fltPercentageIncrease += 1.0f;
    
    for(int i = 0 ; i < intDays ; i++)
    {
        intOrganisms *= fltPercentageIncrease;
        cout << endl << "Day " << i << endl
             << intOrganisms << " organisms.\n";
    }
    
    return 0;
}


