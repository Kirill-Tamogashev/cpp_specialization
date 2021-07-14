#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
   set<string> lines;
   int q;
   cin >> q;

   for (int i = 0; i < q; ++i) {
      string s;
      cin >> s;
      lines.insert(s);
   }
   cout << lines.size() << endl;
   return 0;
}
