#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

int main() {
   map<string, set<string>> syn_vocab;
   int q;
   cin >> q;

   for (int i = 0; i < q; ++i) {
      string command;
      cin >> command;

      if (command == "ADD") {
         string word1, word2;
         cin >> word1 >> word2;
         syn_vocab[word1].insert(word2);
         syn_vocab[word2].insert(word1);
      }

      if (command == "COUNT") {
         string word;
         cin >> word;
         cout << syn_vocab[word].size() << endl;
      }

      if (command == "CHECK") {
         string word1, word2;
         cin >> word1 >> word2;
         if (syn_vocab[word1].count(word2) == 1 || syn_vocab[word2].count(word1) == 1) {
            cout << "YES" << endl;
         } else {
            cout << "NO" << endl;
         }
      }

   }
}