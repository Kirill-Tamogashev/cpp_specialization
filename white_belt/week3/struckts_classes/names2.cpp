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
  string GetFullNameWithHistory(int year) {
      // получить все имена и фамилии по состоянию на конец года year
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
  map<int, string> year2Fname;
  map<int, string> year2Lname;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}