#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int GCD(int a, int b) {
   while (a > 0  && b > 0){
      if  (a > b) {
         a = a % b;
      } else {
         b = b % a;
      }
   }
   return a + b;
}


class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        int gcd = GCD(numerator, denominator);
        if (numerator == 0) {
            num = 0;
            denom = 1;
        } else if (numerator < 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
            int gcd = GCD(numerator, denominator);
            num = numerator / gcd;
            denom = denominator / gcd;
        } else if (numerator < 0) {
            int gcd = GCD(numerator * (-1), denominator);
            num = numerator / gcd;
            denom = denominator / gcd;
        } else if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
            int gcd = GCD(numerator * (-1) , denominator);
            num = numerator / gcd;
            denom = denominator / gcd;
        } else {
            int gcd = GCD(numerator, denominator);
            num = numerator / gcd;
            denom = denominator / gcd;
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

private:
    int num;
    int denom;
};

// Вставьте сюда реализацию operator == для класса Rational из второй части
bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator<(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
