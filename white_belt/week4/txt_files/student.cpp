#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


struct Student 
{
public:
   Student(string new_name, string new_surname, 
            int new_bday, int new_bmonht, int new_byear) {
               name = new_name;
               surname = new_surname;
               bday = new_bday;
               bmonth = new_bmonht;
               byear = new_byear;
            }
   string name;
   string surname;
   int bday;
   int bmonth;
   int byear;
};


int main() {
   int counter;
   cin >> counter;

   string name;
   string surname;
   int bday;
   int bmonth;
   int byear;

   vector<Student> data;
   for (int i = 0; i < counter; ++i) {
      cin >> name >> surname;
      cin >> bday >> bmonth >> byear;
      data.push_back({name, surname, bday, bmonth, byear});
   }
   int m;
   cin >> m;
   for (int j = 0; j < m; ++j) {
      string request;
      int idx;
      cin >> request >> idx;
      --idx;

      if (request == "name" && idx >= 0 && idx < counter) {
         cout  << data[idx].name << ' ' 
               << data[idx].surname << endl;
      } else if (request == "date" && idx >= 0 && idx < counter) {
         cout << data[idx].bday << '.' 
              << data[idx].bmonth << '.' 
              << data[idx].byear << endl;
      } else {
         cout << "bad request" << endl;
      }
   }
   return 0;
}