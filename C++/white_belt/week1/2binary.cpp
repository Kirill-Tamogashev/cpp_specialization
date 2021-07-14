#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n, dig;
   vector<int> binary;
   cin >> n;

   while (n != 0) {
      dig = n % 2;
      binary.push_back(dig);
      n = n / 2;
   }
   for (int i = binary.size() ; i != 0; i--) {
      cout << binary[i-1];
   }
   cout << endl;
   return 0;
}