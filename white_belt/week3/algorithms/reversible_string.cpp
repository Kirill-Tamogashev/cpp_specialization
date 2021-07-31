#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ReversibleString {
   public:
   // TODO:
      ReversibleString () {}
      ReversibleString (const string& str) {
      self_str = str;
      }
      void Reverse () {
         reverse(begin(self_str), end(self_str));
      }
      string ToString () const {
         return self_str;
      }
   private:
   // TODO:
      string self_str;
};


// int main() {
//   ReversibleString s("live");
//   s.Reverse();
//   cout << s.ToString() << endl;
  
//   s.Reverse();
//   const ReversibleString& s_ref = s;
//   string tmp = s_ref.ToString();
//   cout << tmp << endl;
  
//   ReversibleString empty;
//   cout << '"' << empty.ToString() << '"' << endl;
  
//   return 0;
// }

