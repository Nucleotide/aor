#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<string> sanat;
int sanoja;
string sana;

int main() {
  cin >> sanoja;
  for (int i = 0; i < sanoja; i++) {
    cin >> sana;
    sort(sana.begin(),sana.end());
    sanat.insert(sana);
  }

  cout << sanat.size() << "\n";
}
