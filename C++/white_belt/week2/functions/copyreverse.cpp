#include <vector>
#include <iostream>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
   vector<int> new_v;
   for (int i = v.size() - 1; i >= 0; --i) {
      new_v.push_back(v[i]);
   }
   return new_v;
}

int main() {
   vector<int> v = {1, 3, 5, 2, 4};
   vector<int> new_v;
   new_v = Reversed(v);
   for (auto s: new_v){
      cout << s << ' ';
   }
}