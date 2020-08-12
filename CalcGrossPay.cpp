/*
  CalcGrossPay.cpp
  Pay Table Estimator

  Created by Marino Duran.
  Copyright (c) 2020 All rights reserved to author.

*/

#include "pch.h"
#include "CalcGrossPay.h"

CalcGrossPay::CalcGrossPay(double pay_rate, string pay_period, double tax_rate, bool use_)
{
    rate = pay_rate;
    tax = tax_rate;
    use = use_;
    IRS = "before"; //set pre post taxes state
    processPay(toupper(pay_period.at(0))); //calcualte table members
    setOrder(annual); //Calculate and store int order variable
    printPayTable(); //print class members
}


void CalcGrossPay::processPay(char Rate)
{
    switch (Rate) {
    case 'H': calculateTable(rate);
        break;
    case 'D': calculateTable(rate / 8);
        break;
    case 'W': calculateTable(rate / 40);
        break;
    case 'B': calculateTable(rate / 80);
        break;
    case 'M': calculateTable(rate / 160);
        break;
    case 'Y': calculateTable(rate / 2080);
        break;
    case 'A': calculateTable(rate / 2080);
    }
}

void CalcGrossPay::calculateTable(double hour)
 {
    hourly = hour;
    daily = hour * 8;
    weekly = hour * 40;
    biWeekly = hour * 80;
    monthly = hour * 160;
    annual = (hour * 40) * 52;
 }

void CalcGrossPay::setOrder(double annualSal) {
    order = int(annualSal / 9733);
}
void CalcGrossPay::printPayTable()
{
    cout << "\nYour compesnation " << IRS << " taxes is: " << endl;
    cout << "Hourly:    " << hourly << '\n' <<
            "Daily:     " << daily << '\n' <<
            "Weekly:    " << weekly << '\n' <<
            "Bi-Weekly: " << biWeekly << '\n' <<
            "Monthly:   " << monthly << '\n' <<
            "Annual:    " << annual << '\n' << endl;

    if (IRS.at(0) == 'b' && use != 0)
    {
        if (annual > 10000) {
            beGrateful();
        }
        proccess_taxes();
        printPayTable();
    }
   
}

void CalcGrossPay::proccess_taxes()
{
    calculateTable(hourly * (1 - (tax / 100)));
    IRS = "after";
}

void CalcGrossPay::beGrateful()
{
    
    cout << "\n\nAccording to a Gallup News poll: The median annual household income worldwide is $9,733." << '\n'
        << "You make "<< order << " times more than that and have much to be grateful for." << '\n' << endl;
}
