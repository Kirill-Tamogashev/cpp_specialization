// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;


class Date {
public:
  Date();
  Date(int year, int month, int day) {
    // all necessary checks for date
    if (month < 1 || month > 12) {
      throw "Month value is invalid: " + to_string(month);
    } else if (day < 1 || day > 31) {
      throw "Day value is invalid: " + to_string(day);
    } else {

      _year = year;
      _month = month;
      _day = day;
    }
  }
  int GetYear() const{
    return _year;
  };
  int GetMonth() const {
    return _month;
  };
  int GetDay() const {
    return _day;
  };

private:
  int _year;
  int _month;
  int _day;
};


istream& operator>>(istream& stream, Date& date) {
  int year, month, day;
  char div1, div2;
  stream >> year >> div1;
  stream >> month >> div2 >> day;
  if (stream && div1 == '-' && div2 == '-') {
    date = Date(year, month, day);
  }
  return stream;
}

ostream& operator<<(ostream& stream, const Date& date) {
  stream << date.GetYear() << '-';
  stream << date.GetMonth() << ' ';
  stream << date.GetDay() << endl;
  return stream;
}


bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() < rhs.GetYear()) {
    if (lhs.GetMonth() < rhs.GetMonth()) {
      return lhs.GetDay() < rhs.GetDay();
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

class Database {
public:

  void AddEvent(const Date& date, const string& event) {
    databaza[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    if (databaza[date].count(event) == 1) {
    databaza[date].erase(event);
    return true;
    }
    return false;
  }

  int  DeleteDate(const Date& date){
    int len = databaza[date].size();
    databaza.erase(date);
    return len;
  }

  void Find(const Date& date) { 
    for (const auto ev : databaza[date]) {
      cout << ev << endl;
    }
  }

  // TODO print
  void Print() const {
    for (const auto elem : databaza) {
      for (const auto ev : elem.second) {
        cout << elem.first << " " << ev << endl;
      }
    }
  }

private:
  map<Date, set<string>> databaza;
};


// TODO: add exceptions
int main() {
  Database db;
  string command;

  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
    cin >> command;
    if (command == "Add") {
      Date date;
      string event;
      cin >> date >> event;
      db.AddEvent(date, event);

    } else if (command == "Del") {
      Date date;
      string event = "no_event";
      cin >> date >> event;

      if (event == "no_event") {

        int res = db.DeleteDate(date);
        cout  << "Deleted " << res << " events" << endl;
      } else {
        bool res = db.DeleteEvent(date, event);
        if (res) {
          cout << "Deleted successfully" << endl;
        } else {
          cout << "Event not found" << endl;
        }
      }

    } else if (command == "Find") {
      Date date;
      cin >> date;
      db.Find(date);

    } else if (command == "Print") {
      db.Print();

    } else {
      cout << "Unknown command: " <<  command << endl;
    }
  }

  return 0;
}