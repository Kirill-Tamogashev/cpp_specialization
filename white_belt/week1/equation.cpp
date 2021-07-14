#include <iostream>
#include <cmath>
using namespace std;

int main(){
   double a, b, c;
   double D;
   double x1, x2;
   cin >> a >> b >> c;
   if (a == 0) {
      if (b == 0){
         cout << " " << endl;
      } else {
      cout << - c / b << endl;
      }
   } else {
      D = b * b - 4 * a * c;
      if (D < 0) {
         cout << " " << endl;
      } else {
         x1 = (- b - sqrt(D)) / (2 * a);
         x2 = (- b + sqrt(D)) / (2 * a);
         if (x1 == x2) {
            cout  << x2 << endl;
         } else {
         cout << x1 << " " << x2 << endl;
         }
      }
   }
   return 0;
}