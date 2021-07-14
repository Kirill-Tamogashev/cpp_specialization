#include <iostream>
using namespace std;

int main(){
   double N, A, B, X, Y;
   cin >> N >> A >> B >> X >> Y;
   // value N will be returned
   if (N <= A) {
      cout << N << endl;
   }
   // first discount
   if (N > A && N <= B) {
      cout << N * (1 - X / 100) << endl;
   }
   // second discount
   if (N > B) {
      cout << N * (1 - Y / 100) << endl;
   }
   return 0;
}