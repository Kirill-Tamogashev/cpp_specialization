#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n;
   int mean = 0;
   cin >> n;
   vector<int> temps;
   // collect all items/ calculate their sum  
   for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      mean += k;
      temps.push_back(k);
   }

   mean /= n; // calculate mean
   vector<int> idx;
   int count = 0;

   for (int i = 0; i < n; ++i) {
      if (temps[i] > mean){
         idx.push_back(i);
         ++count;
      }
   }
   cout << count << endl;
   for (auto id : idx) {
      cout << id <<' ';
   }
   cout << endl;
}