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

// TODO: finish class Database
class Database {
public:
  void AddEvent(const Date& date, const string& event) {
    databaza[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
    databaza[date].erase(event);
  }
  int  DeleteDate(const Date& date){
    databaza.erase(date);
  }

  void Find(const Date& date) { // !!!there was constant mwthod here
    for (auto ev :databaza[date]) {
      cout << ev << endl;
    }
  }
  // TODO print
  void Print() const;

private:
  map<Date, set<string>> databaza;
};


// TODO: add preprocessing of all commands, necessary conditions and exceptions
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
      // TODO: add date and event ot dataset

    } else if (command == "Del") {
      Date date;
      string event = "no_event";
      cin >> date >> event;
      if (event == "no_event") {
        // ! delete all events for the day
      } else {
        // ! delete specific event
      }
    } else if (command == "Find") {
      Date date;
      cin >> date;

    } else if (command == "Print") {

    } else {
      cout << "Unknown command: " <<  command << endl;
    }
  }
  return 0;
}