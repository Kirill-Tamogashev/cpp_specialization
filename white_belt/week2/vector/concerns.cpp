#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
   int month2be = 1; // must be % 12 in order to avoid exceeding 12
   vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   vector<string> concerns(31); // daily conserns
   vector<int> N_concerns(31, 0); // number of daily conserns

   vector<string> dump_c;
   vector<int> dump_n;
   // number of queries
   int q;
   cin >> q;
   // input of queries
   for ( int i = 0; i < q; ++i) {
      string command;
      cin >> command;
      // processing `NEXT` command
      if (command == "NEXT") {
         int days2be = days[month2be % 12];
         int daysNow = days[month2be % 12 - 1];
         month2be++;
         string last_day;
         int l_day = 0;

         if (days2be < daysNow) {
            for (int i = days2be; i < daysNow; ++i) {
               last_day += concerns[i];
               l_day += N_concerns[i];
            }
         }
         concerns.resize(days2be);
         concerns[days2be - 1] += last_day;

         N_concerns.resize(days2be);
         N_concerns[days2be - 1] += l_day;
      }
      // processing `DUMP` command
      if (command == "DUMP") {
         int day;
         cin >> day;
         dump_c.push_back(concerns[day - 1]);
         dump_n.push_back(N_concerns[day - 1]);
      }
      // processing `ADD` command
      if (command == "ADD") {
         int day;
         string activity;

         cin >> day >> activity;
         concerns[day - 1] += " ";
         concerns[day - 1] += activity;
         N_concerns[day - 1] += 1;
      }
   }
   for (int i = 0; i < dump_c.size(); i++) {
      cout << dump_n[i] <<  dump_c[i] << endl;
   }
   return 0;
}
