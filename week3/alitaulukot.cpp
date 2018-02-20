#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int koko;
long tavoite;
long arvo;
long taulukoita = 0;
long juokseva_summa = 0;
unordered_map<long, long> luvut;

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
    juokseva_summa = juokseva_summa + arvo;
    long lisaa = tavoite - arvo + juokseva_summa;
    long vanha_n = luvut[lisaa];
    luvut[lisaa] = vanha_n + 1;
    long haluttuja = luvut[juokseva_summa];
    taulukoita = taulukoita + haluttuja;
  }

  cout << taulukoita << "\n";
}
