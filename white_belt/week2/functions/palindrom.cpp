#include <iostream>
#include <string>
using namespace std;


bool IsPalindrom(string word) {
   if (word.length() == 0){
      return true;
   }
   string new_word;
   for (int i = word.length() - 1; i >= 0; i--){
      new_word.push_back(word[i]);
   }
   if (word == new_word) {
      return true;
   }
   return false;
}


int main(){
   string word;
   cin >> word;
   cout << IsPalindrom(word) << endl;
   return 0;
}