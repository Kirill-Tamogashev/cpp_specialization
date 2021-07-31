#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
   ifstream input("input.txt");
   string rows;
   string cols;
   if (input) {
      getline(input, rows, ' ');
      getline(input, cols);
      double n_rows = stod(rows);
      double n_cols = stod(cols);
      cout << setfill(' ');

      for (int i = 0; i < n_rows; ++i) {
         for (int j = 0; j < n_cols - 1; ++j) {
            int num;
            input >> num;
            input.ignore(1);
            cout << setw(10) << num << ' ';
         }
         int num;
         input >> num;
         cout << setw(10) << num;
         if (i != n_rows - 1)  {
            cout << endl;
         }
      }
   }
   return 0;
}