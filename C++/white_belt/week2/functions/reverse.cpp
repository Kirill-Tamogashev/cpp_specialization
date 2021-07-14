#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v){
   const int size = v.size();
   for (int i = size - 2; i >=0; --i) {
      v.push_back(v[i]);
      v.erase(v.begin() + i);
   }
}

// int main(){
//    vector<int> nums = {1, 2, 3, 4, 5};
//    Reverse(nums);
//    for (auto n : nums) {
//       cout << n << " ";
//    }
// }