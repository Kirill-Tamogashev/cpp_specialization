#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;


class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    year2Fname[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    year2Lname[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    int year_fn = -1;
    for (auto y : year2Fname) {
       if (y.first > year) {
          break;
       } else {
          year_fn = y.first;
       }
    }
    int year_ln = -1;
    for (auto y : year2Lname) {
       if (y.first > year) {
          break;
       } else {
          year_ln = y.first;
       }
    }
    if (year_ln == -1 && year_fn == -1) {
       return  "Incognito";
    } else if (year_fn == -1) {
       return  year2Lname[year_ln] + " with unknown first name";
    } else if (year_ln == -1) {
       return year2Fname[year_fn] + " with unknown last name";
    } else {
       return year2Fname[year_fn] + " " +  year2Lname[year_ln];
    }
  }
private:
  // приватные поля
  map<int, string> year2Fname;
  map<int, string> year2Lname;
};


// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullName(year) << endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }
  
//   return 0;
// }
