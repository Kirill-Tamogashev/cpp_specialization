#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void Print(const vector<string>& v){
   for (const auto& i : v) {
      cout << i << ' ';
   }
   cout << endl;
}


int main() {
   vector<string> vec;
   int n;
   cin >> n;

   for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      vec.push_back(s);
   }

   sort(
      begin(vec), 
      end(vec), 
      [](const string& a, const string& b){
         // lower vertion of sting `a`
         string l_a;
         for (auto i : a) {
            l_a.push_back(tolower(i));
         }
         // lower vertion of sting `b`
         string l_b;
         for (auto i : b) {
            l_b.push_back(tolower(i));
         }
         // comparing `a` and `b`
         if (l_a < l_b) {
            return true;
         }
         return false;
      }
   );
   Print(vec);
   return 0;
}