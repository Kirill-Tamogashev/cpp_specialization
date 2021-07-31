#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main() {
   ifstream input("input.txt");
   string line;
   cout << fixed << setprecision(3);
   if (input) {
      while (getline(input, line)){
         double dig = stod(line);
         cout << dig << endl;
      }
   }
   return 0;
} 