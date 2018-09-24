#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

#include "trapMethod.h"
#include "matlabPlot.h"

double f(double t, double y) { return 4*t-2*y; }

//double f2(double t, double y) { return t/(1+y*y); }

int main() {
  double a,b,y0;
  int n;
  cout << "Enter a,b,y0,n: ";
  cin >> a >> b >> y0 >> n;
  vector<double> x(n+2);
  vector<double> y(n+2);

//  trapMethod(f, y, y0, a, b);
  trapMethod(f, x, y, y0, a, b);

  string fileName;
  cout << "Enter output file name: ";
  cin >> fileName;
  ofstream fout(fileName.c_str());
  if(!fout) {
    cerr << "ERROR: Opening file" << endl;
    return 1;
  }
//  matlabPlot(fout,y);
  matlabPlot(fout,x,y);

  return 0;
}
  
