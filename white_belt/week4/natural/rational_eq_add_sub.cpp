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

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator() ;
    int new_denom = lhs.Denominator() * rhs.Denominator();
    return Rational(new_num, new_denom);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator() ;
    int new_denom = lhs.Denominator() * rhs.Denominator();
    return Rational(new_num, new_denom);
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
