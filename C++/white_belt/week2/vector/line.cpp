#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

   int n;
   cin >> n;
   vector<string> people;
   vector<int> worry_count;

   for (int i = 0; i < n; ++i) {
      int idx;
      string str;
      cin >> str;
      if (str != "WORRY_COUNT") {
         cin >> idx;
      }

      if (str == "WORRY") {
         people[idx] = "WORRY";
      }
      if (str == "QUIET") {
         people[idx] = "QUIET";
      }
      if (str == "COME") {
         people.resize(people.size() + idx);
      }
      if (str == "WORRY_COUNT") {
         int count = 0;
         for (auto person : people) {
            if (person == "WORRY") {
               ++count;
            }
         }
         worry_count.push_back(count);
      }
   }

   for (auto c : worry_count) {
      cout << c << endl;
   }
   return 0;
}
