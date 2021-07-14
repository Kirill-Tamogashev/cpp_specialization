#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void PrintMap(const map<string, string>& m) {
   if (m.size() == 0) {
      cout << "There are no countries in the world" << endl;
   } else {
      for (auto item : m) {
         cout << item.first << '/' << item.second << ' ';
      }
      cout << endl;
   }

}

int main() {
   int n;
   cin >> n;
   map<string, string> country2capital;


   for (int i = 0; i < n; ++i) {
      string command;
      cin >> command;

      if (command == "DUMP") {
         PrintMap(country2capital);
      }

      if (command == "ABOUT") {
         string country;
         cin >> country;
         if (country2capital.count(country) == 0) {
            cout << "Country " << country << " doesn't exist" << endl;
         } else {
            cout << "Country " <<  country << " has capital " << country2capital[country]  << endl;
         }

      }

      if (command == "CHANGE_CAPITAL") {
         string country, new_capital;
         cin >> country >> new_capital;
         if (country2capital.count(country) == 0) {
            cout << "Introduce new country " <<  country << " with capital " << new_capital << endl;
            country2capital[country] = new_capital;

         } else if (country2capital[country] == new_capital) {
            cout << "Country " << country << " hasn't changed its capital" << endl;

         } else {
            cout << "Country " << country << " has changed its capital from ";
            cout << country2capital[country] << " to " << new_capital << endl;
            country2capital[country] = new_capital;
         }

      }

      if (command == "RENAME") {
         string old_country_name, new_country_name;
         cin >> old_country_name >> new_country_name;

         if (old_country_name == new_country_name || country2capital.count(old_country_name) == 0 || country2capital.count(new_country_name) == 1) {
            cout << "Incorrect rename, skip" << endl;
         } else {
            string cap = country2capital[old_country_name];
            cout << "Country " <<  old_country_name;
            cout << " with capital " << cap;
            cout << " has been renamed to " << new_country_name << endl;
            country2capital[new_country_name] = cap;
            country2capital.erase(old_country_name);
         }
      }
   }

   return 0;
}