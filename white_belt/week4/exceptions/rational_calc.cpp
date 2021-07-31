#include <iostream>
#include <string>
#include <sstream>
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


Rational operator*(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.Numerator() * rhs.Numerator();
    int new_denom = lhs.Denominator() * rhs.Denominator();
    return Rational(new_num, new_denom);
}


Rational operator/(const Rational& lhs, const Rational& rhs) {    
    int new_num = lhs.Numerator() * rhs.Denominator();
    int new_denom = lhs.Denominator() * rhs.Numerator();
    if (new_denom == 0) {
        throw domain_error("Division by zero");
    }
    return Rational(new_num, new_denom);
}

istream& operator>>(istream& stream, Rational& r) {
    int new_num;
    int new_denom;
    char division;
    stream >> new_num;
    stream >> division;
    stream >> new_denom;
    if (stream && division == '/') {
        r = Rational(new_num, new_denom);
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& r) {
    stream << r.Numerator() << '/' << r.Denominator();
    return stream;
}


int main() {
   Rational r1, r2;
   char operand;
   try{
      cin >> r1;
      cin >> operand;
      cin >> r2;

      if (operand == '+') 
      {
         cout << r1 + r2 << endl;
      } else if (operand == '-') 
      {
         cout << r1 - r2 << endl;
      } else if (operand == '*') 
      {
         cout << r1 * r2 << endl;
      } else if (operand == '/')
      {
         cout << r1 / r2 << endl;
      }
   } catch (invalid_argument& err) {
      cout << err.what() << endl;
   }  catch (domain_error& div) {
      cout << div.what() << endl;
   }
   return 0;
}