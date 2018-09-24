///////////////////////////////////////////////////////////////////////////////
// OUTPUT FOR MATLAB PLOT FUNCTION
//
// Provide a simple output routine for producing plots using the
// matlab plot function.
//
// Inputs:
//   fout      The output stream
//   n         The number of points to plot
//   x,y       The x and y coordinates (x may be omitted if x = {1,2,...,n}
//   title     The plot title
//   x-label   The x-axis label
//   y-label   The y-axis label
// Outputs:    The plot file.
// Return:     none (void)
///////////////////////////////////////////////////////////////////////////////
#include "matlabPlot.h"
using namespace std;

//#define TEST

static void constructPlot1(ofstream& fout, const string& title,
			  const string& xLabel, const string& yLabel) {
  fout << "plot(y);\n";
  fout << "title('" << title << "');\n";
  fout << "xlabel('" << xLabel << "');\n";
  fout << "ylabel('" << yLabel << "');\n";
}

static void constructPlot2(ofstream& fout, const string& title,
			  const string& xLabel, const string& yLabel) {
  fout << "plot(x,y);\n";
  fout << "title('" << title << "');\n";
  fout << "xlabel('" << xLabel << "');\n";
  fout << "ylabel('" << yLabel << "');\n";
}

void matlabPlot(ofstream& fout, int n, double* y,
		const string& title, const string& xLabel,
		const string& yLabel) {
  // Write y
  fout << "y = [\n";
  for(int i=0; i<n+1; i++) fout << y[i] << "\n";
  fout << "];\n";

  constructPlot1(fout, title, xLabel, yLabel);
}

void matlabPlot(ofstream& fout, int n, double* x, double* y,
		const string& title, const string& xLabel,
		const string& yLabel) {
  // Write x
  fout << "x = [\n";
  for(int i=0; i<n+1; i++) fout << x[i] << "\n";
  fout << "];\n";

  // Write y
  fout << "y = [\n";
  for(int i=0; i<n+1; i++) fout << y[i] << "\n";
  fout << "];\n";

  constructPlot2(fout, title, xLabel, yLabel);
}

void matlabPlot(ofstream& fout, vector<double>& y,
		const string& title, const string& xLabel,
		const string& yLabel) {
  // Write y
  fout << "y = [\n";
  for(int i=0; i<y.size(); i++) fout << y[i] << "\n";
  fout << "];\n";

  constructPlot1(fout, title, xLabel, yLabel);
}

void matlabPlot(ofstream& fout, vector<double>& x, vector<double>& y,
		const string& title, const string& xLabel,
		const string& yLabel) {
  // Write x
  fout << "x = [\n";
  for(int i=0; i<x.size(); i++) fout << x[i] << "\n";
  fout << "];\n";

  // Write y
  fout << "y = [\n";
  for(int i=0; i<y.size(); i++) fout << y[i] << "\n";
  fout << "];\n";

  constructPlot2(fout, title, xLabel, yLabel);
}

#ifdef TEST
void main() {
  const int n=6;
  double x[n] = {1,2,4,5,7,8};
  double y[n] = {0,-1,5,3,9,8};

  string title("Test Plot");

  ofstream fout("testPlot1.m");

  matlabPlot(fout, n, x, y, title, "x values", "y values");
  fout.close();

  fout.open("testPlot2.m");
  matlabPlot(fout, n, y, title, "x values", "y values");
}
#endif
