#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    vec.push_back(s);
    SortVec();
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
    return vec;
  }
private:
  // приватные поля
  void SortVec() {
     sort(begin(vec), end(vec));
  }
  vector<string> vec;
};


// void PrintSortedStrings(SortedStrings& strings) {
//   for (const string& s : strings.GetSortedStrings()) {
//     cout << s << " ";
//   }
//   cout << endl;
// }

// int main() {
//   SortedStrings strings;
  
//   strings.AddString("first");
//   strings.AddString("third");
//   strings.AddString("second");
//   PrintSortedStrings(strings);
  
//   strings.AddString("second");
//   PrintSortedStrings(strings);
  
//   return 0;
// }

