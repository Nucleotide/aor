#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int koko;
long tavoite;
long arvo;
int taulukoita = 0;
multiset<long> arvot;

int main() {
  for (int i = 0; i < 2; i++) {
    if ( i == 0 ) {
      cin >> koko;
    } else {
      cin >> tavoite;
    }
  }

  for (int j = 0; j < koko; j++) {
    cin >> arvo;
    arvot.insert(arvo);
  }

  for (int k = 0; k < koko; k++) {
    long summa = 0;
    int indeksi = k;
    auto it = arvot.begin();
    advance(it, k);
    summa = *it;
    if (summa == tavoite) {
      taulukoita++;
    } else {
      while (summa < tavoite) {
        if (indeksi + 1 < koko) {
          advance(it, 1);
          summa = summa + *it;
          if (summa == tavoite) {
            taulukoita++;
          }
          indeksi++;
        } else {
          summa = tavoite + 2;
        }
      }
    }
  }

  cout << taulukoita << "\n";
}
