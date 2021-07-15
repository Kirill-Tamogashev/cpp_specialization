#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void Print(const vector<int>& v){
   for (const auto& i : v) {
      cout << i << ' ';
   }
   cout << endl;
}

int main() {
   vector<int> nums;
   int n;
   cin >> n;

   for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      nums.push_back(num);
   }

   sort(
      begin(nums), end(nums), [](int& x, int& y){
         if (abs(x) < abs(y)) {
            return true;
         }
         return false;
      }
      );
   Print(nums);
   return 0;
}