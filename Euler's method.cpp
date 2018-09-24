//
//  Euler's method.cpp
//  
//
//  Created by Naman Mehra on 4/26/18.
//

#include "Euler's method.hpp"
//Eulers Method to solve a differential equation
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double df(double x, double y)            //function for defining dy/dx
{
    double a=x+y;                //dy/dx=x+y
    return a;
}
int main()
{
    int n;
    double x0,y0,x,y,h;            //for initial values, width, etc.
    cout.precision(5);            //for precision
    cout.setf(ios::fixed);
    cout<<"\nEnter the initial values of x and y respectively:\n";        //Initial values
    cin>>x0>>y0;
    cout<<"\nFor what value of x do you want to find the value of y\n";
    cin>>x;
    cout<<"\nEnter the width of the sub-interval:\n";            //input width
    cin>>h;
    cout<<"x"<<setw(19)<<"y"<<setw(19)<<"dy/dx"<<setw(16)<<"y_new\n";
    cout<<"----------------------------------------------------------\n";
    while(fabs(x-x0)>0.0000001)        //I couldn't just write "while(x0<x)" as they both are floating point nos. It is dangerous to compare two floating point nos. as they are not the same in binary as they are in decimal. For instance, a computer cannot exactly represent 0.1 or 0.7 in binary just like decimal can't represent 1/3 exactly without recurring digits.
    {
        y=y0+(h*df(x0,y0));            //calculate new y, which is y0+h*dy/dx
        cout<<x0<<setw(16)<<y0<<setw(16)<<df(x0,y0)<<setw(16)<<y<<endl;
        y0=y;                    //pass this new y as y0 in the next iteration.
        x0=x0+h;                //calculate new x.
    }
    cout<<x0<<setw(16)<<y<<endl;
    cout<<"The approximate value of y at x=0 is "<<y<<endl;        //print the solution.
    return 0;
}


