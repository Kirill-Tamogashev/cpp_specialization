#include <algorithm>
#include <vector>
using namespace std;


class FunctionPart {
public:
   FunctionPart(char new_operand, double new_value) {
      operand = new_operand;
      value = new_value;
   }
   double Apply(double source) const {
      if (operand == '+') {
         return source + value;
      } else if (operand == '-'){
         return source - value;
      } else if (operand == '*') {
         return source * value;
      } else {
         return source / value;
      }
   }
   void Invert() {
      if (operand == '+') {
         operand = '-';
      } else if (operand == '-'){
         operand = '+';
      } else if (operand == '*') {
         operand = '/';
      } else {
         operand = '*';
      }
   }
private:
   char operand;
   double value;
};


class Function {
public:
   void AddPart(char new_operand, double value) {
      parts.push_back({new_operand, value});
   }
   double Apply(double value) const {
      for (const FunctionPart& part : parts) {
         value = part.Apply(value);
      }
      return value;
   }
   void Invert() {
      for (FunctionPart& part : parts) {
         part.Invert();
      }
      reverse(begin(parts), end(parts));
   }
private:
   vector<FunctionPart> parts;
};

