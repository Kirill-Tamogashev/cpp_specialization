#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


string Vec2Str (const vector<string>& vec) {
  string str = "";
  for (int i = vec.size() - 1; i >= 0; --i) {
    str += vec[i];
    if (vec.size() == 1) {
      return str;
    } else if (i == vec.size() - 1) {
      str += " (";
    } else if (i == 0) {
      str += ")";
    } else {
      str += ", ";
    }
  }
  return str;
}


class Person {
public:
  Person (
     const string& first_name, 
     const string& last_name, 
     const int& birth_year
     ) {
        b_year = birth_year;
        year2Fname[b_year] = first_name;
        year2Lname[b_year] = last_name;
     }
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    if (year >= b_year) {
       year2Fname[year] = first_name;
       }
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if (year >= b_year) {
       year2Lname[year] = last_name;
       }
  }
  string GetFullName(int year) const {
    // получить имя и фамилию по состоянию на конец года year
    if (year < b_year) {
      return "No person";
    }
    string fname = "";
    for (auto y : year2Fname) {
       if (y.first <= year) {
         fname = y.second;
       }
    }
    string lname = "";
    for (auto y : year2Lname) {
       if (y.first <= year) {
         lname = y.second;
       }
    }
    return fname + " " +  lname;
   }
  string GetFullNameWithHistory(int year) const {
      // получить все имена и фамилии по состоянию на конец года year
      if (year < b_year) {
         return "No person";
      }
      string last = "";

      vector<string> fnames;
      for (auto item : year2Fname) {
        if (item.first <= year && item.second != last) {
          fnames.push_back(item.second);
          last = item.second;
        }
      }
      vector<string> lnames;
      for (auto item : year2Lname) {
        if (item.first <= year && item.second != last) {
          lnames.push_back(item.second);
          last = item.second;
        }
      }
      if (fnames.size() == 0 && lnames.size() == 0) {
        return  "Incognito";
      } else if (fnames.size() == 0 ) {
        string ln_story = Vec2Str(lnames);
        return  ln_story + " with unknown first name";
      } else if (lnames.size() == 0) {
        string fn_story = Vec2Str(fnames);
        return fn_story + " with unknown last name";
      } else {
        string fn_story = Vec2Str(fnames);
        string ln_story = Vec2Str(lnames);
        return fn_story + " " + ln_story; 
      }
  }
private:
  // приватные поля
  int b_year;
  map<int, string> year2Fname;
  map<int, string> year2Lname;
};


int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
   for (int year : {1965, 1967}) {
    cout << person.GetFullName(year) << endl;
  }
  return 0;
}
