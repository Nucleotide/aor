#include <iostream>
#include <map>

using namespace std;

int kolikoita;
int arvo;
int pienin = 1;

int main() {
  cin >> kolikoita;
  for (int i = 0; i < kolikoita; i++) {
    cin >> arvo;
    if (arvo == pienin) {
      pienin++;
    }
  }
  cout << pienin << "\n";
}
