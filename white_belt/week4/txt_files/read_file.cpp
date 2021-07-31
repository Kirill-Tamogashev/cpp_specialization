#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
   fstream input("input.txt");
   string line;
   if (input) {      
      while (getline(input, line)) {
         cout << line << '\n';
      }
   }
   return 0;
}