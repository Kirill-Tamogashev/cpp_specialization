#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


int main() {
   map<string, vector<string>> bus2stops;
   map<string, vector<string>> stop2buses;
   int n;
   cin >> n;

   for (int i = 0; i < n; ++i) {
      string command;
      cin >> command;

      if (command == "NEW_BUS") {
         string bus;
         int stop_count;
         cin >> bus >> stop_count;
         for (int j = 0; j < stop_count; ++j) {
            string stop;
            cin >> stop;
            bus2stops[bus].push_back(stop);
            stop2buses[stop].push_back(bus);
         }
      }

      if (command == "BUSES_FOR_STOP") {
         string stop;
         cin >> stop;

         if (stop2buses.count(stop) == 0) {
            cout << "No stop" << endl;
         } else {
            for (auto item : stop2buses[stop]) {
               cout << item << ' ';
            }
            cout << endl;
         }
      }

      if (command == "STOPS_FOR_BUS") {
         string bus;
         cin >> bus;
         if (bus2stops.count(bus) == 0) {
            cout << "No bus" << endl;
            continue;
         }

         for (auto stop : bus2stops[bus]){
            cout << "Stop " << stop << ": ";
            if (stop2buses[stop].size() == 1) {
               cout << "no interchange" << endl;
            } else {
               for (auto b : stop2buses[stop]) {
                  if (b != bus) {
                     cout << b << " ";
                  }
               }
               cout << endl;
            }
         }
      }

      if (command == "ALL_BUSES") {
         if (bus2stops.size() == 0) {
            cout << "No buses" << endl;
         } else {
            for (auto item : bus2stops) {
            cout << "Bus " << item.first << ":";
               for (auto q : bus2stops[item.first]) {
                  cout << " " << q;
               }
               cout << endl;
            }
         }
      }
   }
   return 0;
}
