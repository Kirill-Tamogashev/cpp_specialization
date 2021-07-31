#include <iostream>
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


bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

// Реализуйте для класса Rational операторы * и /
Rational operator*(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.Numerator() * rhs.Numerator();
    int new_denom = lhs.Denominator() * rhs.Denominator();
    return Rational(new_num, new_denom);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.Numerator() * rhs.Denominator();
    int new_denom = lhs.Denominator() * rhs.Numerator();
    return Rational(new_num, new_denom);
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
