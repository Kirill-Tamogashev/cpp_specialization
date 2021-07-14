#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

int main() {
   map<set<string>, int> stops2num;
   int num_counter = 1;
   int n;
   cin >> n; // number of queries;

   for (int i = 0; i < n; ++i) {
      int l;
      set<string> stops;
      cin >> l;
      for (int j = 0; j < l; j++) {
         string stop;
         cin >> stop;
         stops.insert(stop);
      }
      if (stops2num.count(stops) == 1) {
         cout << "Already exists for " << stops2num[stops] << endl;
      } else {
         stops2num[stops] = num_counter;
         cout << "New bus " << num_counter << endl;
         num_counter++;
      }
   }

   return 0;
}