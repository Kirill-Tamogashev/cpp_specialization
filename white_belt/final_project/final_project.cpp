// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class Date
{
public:
    Date()
    {
        year = 0001;
        month = 01;
        day = 01;
    }
    Date(int new_year, int new_month, int new_day)
    {

        if (new_month < 1 || new_month > 12)
        {

            throw logic_error("Month value is invalid: " + to_string(new_month));
        }
        else if (new_day < 1 || new_day > 31)
        {

            throw logic_error("Day value is invalid: " + to_string(new_day));
        }
        else
        {

            year = new_year;
            month = new_month;
            day = new_day;
        }
    }
    int GetYear() const
    {
        return year;
    };
    int GetMonth() const
    {
        return month;
    };
    int GetDay() const
    {
        return day;
    };

private:
    int year;
    int month;
    int day;
};

ostream &operator<<(ostream &out, const Date &date)
{
    out << date.GetYear() << '-' << date.GetMonth() << '-' << date.GetDay();
    return out;
}

void EnsureNextSymbolEndSkip(istream &stream)
{
    cout << (stream.peek() != '-' ) << endl;
    if (stream.peek() != '-')
    {
        throw runtime_error("");
    }
    stream.ignore(1);
}

istream &operator>>(istream &in, Date &date)
{
    string input;
    in >> input;
    stringstream stream(input);
    int y;
    int m;
    int d;
    char ch;

    try
    {
        // * working with year
        if (stream.peek() == -1) {
            throw runtime_error("");
        }
        stream >> y;
        stream >> ch;
        if (ch != '-')
        {
            throw runtime_error("");
        }

        // * working with month
        if (stream.peek() == -1) {
            throw runtime_error("");
        }
        stream >> m;
        stream >> ch;
        if (ch != '-')
        {
            throw runtime_error("");
        }

        // * working with day
        if (stream.peek() == -1) {
            throw runtime_error("");
        }
        stream >> d;
        if (stream.peek() != -1)  
        {
            throw runtime_error("");
        }
    }
    catch (runtime_error &re)
    {
        throw runtime_error("Wrong date format: " + input);
    }
    date = Date(y, m, d);

    return in;
}

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() == rhs.GetMonth())
        {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

class Database
{
public:
    void AddEvent(const Date &date, const string &event)
    {
        if (databaza.count(date) > 0)
        {
            databaza[date].insert(event);
        }
        else
        {
            set<string> events;
            events.insert(event);
            databaza[date] = events;
        }
    }

    bool DeleteEvent(const Date &date, const string &event)
    {
        if (databaza[date].count(event))
        {
            databaza[date].erase(event);
            return true;
        }
        return false;
    }

    int DeleteDate(const Date &date)
    {
        if (databaza.count(date) == 0)
        {
            return 0;
        }
        else
        {
            const int n_events = databaza[date].size();
            databaza.erase(date);
            return n_events;
        }
    }

    void Find(const Date &date) const
    {
        try
        {
            set<string> s = databaza.at(date);
            for (const auto &item : s)
            {
                cout << item << endl;
            }
        }
        catch (out_of_range &)
        {
        }
    }

    void Print() const
    {
        for (const auto &pair : databaza)
        {
            for (const auto &event : pair.second)
            {
                cout << setw(4) << setfill('0') << pair.first.GetYear() << '-';
                cout << setw(2) << setfill('0') << pair.first.GetMonth() << '-';
                cout << setw(2) << setfill('0') << pair.first.GetDay();
                cout << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> databaza;
};


int main()
{
    try
    {
        Database db;
        string command_str;

        while (getline(cin, command_str))
        {
            // Считайте команды с потока ввода и обработайте каждую
            stringstream input(command_str);
            string command;
            input >> command;

            if (command == "Add")
            {
                input.ignore(1);
                Date date;
                try {
                    input >> date;
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                    break;
                }
                input.ignore(1);
                string event;
                input >> event;
                db.AddEvent(date, event);
            }
            else if (command == "Del")
            {
                input.ignore(1);
                Date date;
                try {
                    input >> date;
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                    break;
                }
                if (input.peek() != -1){
                    input.ignore(1);
                    string event;
                    input >> event;
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                } else {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
            }
            else if (command == "Find")
            {
                input.ignore(1);
                Date date;
                try {
                    input >> date;
                } catch (exception& ex) {
                    cout << ex.what() << endl;
                    break;
                }
                db.Find(date);
            }
            else if (command == "Print")
            {
                db.Print();
            }
            else if (command.empty())
            {
            }
            else
            {
                throw logic_error("Unknown command: " + command);
            }
        }
    }
    catch (const exception &error)
    {
        cout << error.what() << endl;
    }
    return 0;
}