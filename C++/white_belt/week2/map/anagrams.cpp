#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool CompareStrings(const string& str1, const string& str2) {
   map<char, int> m1, m2;
   for (auto c : str1) {
      m1[c]++;
   }
   for (auto c : str2) {
      m2[c]++;
   }
   if (m1 == m2) {
      return 1;
   } else {
      return 0;
   }
}

int main() {
   vector<bool> isAnagram;
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i) {
      string str1, str2;
      cin >> str1 >> str2;
      isAnagram.push_back(CompareStrings(str1, str2));
   }
   for (const bool& s: isAnagram) {
      if (s == 1) {
         cout << "YES" << endl;
      } else {
         cout << "NO" << endl;
      }
   }
   return 0;
}
