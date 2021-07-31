#include <iostream>
#include <exception>
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
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
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

Rational operator/(const Rational& lhs, const Rational& rhs) {    
    int new_num = lhs.Numerator() * rhs.Denominator();
    int new_denom = lhs.Denominator() * rhs.Numerator();
    if (new_denom == 0) {
        throw domain_error("domain_error");
    }
    return Rational(new_num, new_denom);
}



int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
