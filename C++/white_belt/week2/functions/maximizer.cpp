#include <iostream>
using namespace std;

void UpdateIfGreater(int a, int& b) {
   if (a > b) {
      b = a;
   }
}

int main() {
   int x, y;
   cin >> x >> y;
   UpdateIfGreater(x, y);
   cout << y << endl;
   return 0;
}