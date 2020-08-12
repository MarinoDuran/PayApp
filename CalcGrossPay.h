/*
  CalcGrossPay.h
  Pay Table Estimator

  Created by Marino Duran.
  Copyright (c) 2020 All rights reserved to author.

*/

#pragma once

class CalcGrossPay
{
private: 
    double rate;
    double hourly;
    double daily;
    double weekly;
    double biWeekly;
    double monthly;
    double annual;
    double tax;
    string IRS;
    bool use; //Limits example data to be limited
    int order; //Used to calculate how much more annual income from median US income is

    void processPay(char Rate);
    void calculateTable(double hour);
    void printPayTable();
    void proccess_taxes();
    void beGrateful();
    void setOrder(double annualSal);
public:
    CalcGrossPay(double pay_rate, string pay_period, double tax_rate, bool use);

};

