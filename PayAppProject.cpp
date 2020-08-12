/*
  PayAppProject.cpp
  Pay Table Estimator 

  Created by Marino Duran.
  Copyright (c) 2020 All rights reserved to author.

*/

#include "pch.h"
#include "CalcGrossPay.h"

void instructions()
{
	cout << "___________________________Instructions___________________________" << '\n' <<
		"******************************************************************" << '\n' <<
		"*                                                                *" << '\n' <<
		"* This program takes in a pay rate, pay period and an estimated  *" << '\n' <<
		"* tax percentage. Returning a table of your compensation broken  *" << '\n' <<
		"* down by Hour, Day, Week, Bi-Week, Month, and Year. Both pre &  *" << '\n' <<
		"* post taxes.                                                    *" << '\n' <<
		"*                                                                *" << '\n' <<
		"******************************************************************" << '\n' << endl;
}

struct {
	double pay_rate{};
	string pay_period{};
	double tax_rate{};
} user, example_data;

void example()
{
	//Output real example data. This allows when changes to the class 
	//are made they are also refelcted in the example 
	cout << "EXAMPLE: " << endl;
	example_data.pay_period = "Hour";
	example_data.pay_rate = 15;
	example_data.tax_rate = 22;
	cout << "	Pay Period: " << example_data.pay_period << '\n' <<
			"	Pay Rate: " << example_data.pay_rate << '\n' <<
			" 	Estimated Tax: " << example_data.tax_rate << endl;
	//Creat example Object of type CalcGrossPay
	CalcGrossPay* Ex = new CalcGrossPay(example_data.pay_rate, example_data.pay_period, example_data.tax_rate, 0);
	cout << "\n\n******************************************************************" << '\n' << endl;
	//Delete Object of type CalcGrossPay from heap
	delete Ex;
}

void input_info() {

	//Display input & output example
	example();

	//Prompt user to input data and store data for calculations
	cout << "\nFrom the list below type in your pay period and press enter: " << endl;
	cout << "\n          Hour - Day - Week - Bi-Week - Month - Year\n" << endl;
	cin >> user.pay_period;
	cout << "Enter your pay rate for this period and press enter: " << endl;
	cin >> user.pay_rate;
	cout << "Enter your estimated tax percentage without sybols and press enter: " << endl;
	cin >> user.tax_rate;
}

void printAuthorInfo()
{
	cout << "\n\nPay Table Estimator\n\nCreated by Marino Duran.\nCopyright(c) 2020 All rights reserved to author.\n";
}

int main()
{
	//Program instruction output
	instructions();

	//Prompt user for information
	input_info();

	//Create pointer of type CalcGrossPay and pass user input to constructor 
	CalcGrossPay * P = new CalcGrossPay(user.pay_rate,user.pay_period,user.tax_rate, 1); 

	//Object automatically prints object's data by calling the print function in its constructor 

	//Delete heap memory allocated to object P of type CalcGrossPay
	delete P;

	//Print copyright stuff
	printAuthorInfo();

	//Sleep to avoid command prompt to display path after calculations 
	Sleep(100000);


	//EXIT_SUCCESSFULLY
	return 0;

}

