#include <iostream>
#include <string>
using namespace std;

int main() {
   string s;
   cin >> s;
   int count = 0;
   for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'f') {
         count++;
      }
      if (count == 2) {
         cout << i << endl;
         break;
      }
   }
   if (count == 0){
      cout << -2 << endl;
      }
   if (count == 1){
      cout << -1 << endl;
      }
   return 0;
}