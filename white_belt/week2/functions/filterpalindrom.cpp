#include <iostream>
#include <string>
#include <vector>
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


vector<string> PalindromFilter(vector<string> words, int minLength) {
   vector<string> good_words;
   for (auto w : words) {
      if (IsPalindrom(w) && w.length() >= minLength) {
         good_words.push_back(w);
      }
   }
   return good_words;
}