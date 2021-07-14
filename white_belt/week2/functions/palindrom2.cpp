#include <iostream>
#include <string>
using namespace std;


bool IsPalindrom(string word) {
   if (word.length() == 0){
      return true;
   }
   int word_length = word.length();
   for (int i = word_length - 1; i >= 0; i--){
      if (word[i] != word[word_length - 1 - i]){
         return false;
      }
   }
   return true;
}


int main(){
   string word;
   cin >> word;
   cout << IsPalindrom(word) << endl;
   return 0;
}