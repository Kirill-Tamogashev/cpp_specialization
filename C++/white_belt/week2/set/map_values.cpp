#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;


set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> map_values;
  for (auto item : m) {
     map_values.insert(item.second);
  }
  return map_values;
}