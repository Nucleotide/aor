#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int huoneita;
int asiakkaita;
long huonekoko;
long vaatimus;
multiset<long> huoneet;
string sana;

int main() {
  for (int i = 0; i < 2; i++) {
    if ( i == 0 ) {
      cin >> huoneita;
    } else {
      cin >> asiakkaita;
    }
  }

  for (int j = 0; j < huoneita; j++) {
    cin >> huonekoko;
    huoneet.insert(huonekoko);
  }

  for (int k = 0; k < asiakkaita; k++) {
    cin >> vaatimus;
    auto it = huoneet.lower_bound(vaatimus);
    if ( it == huoneet.end() ) {
      cout << -1 << " ";
    } else {
      cout << *it << " ";
      huoneet.erase(it);
    }
  }

  cout << "\n";
}
