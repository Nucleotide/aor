#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//Tavoite on saada pienin mahdollinen erotus aina kun jaetaan ryhmiin a ja b

long laudan_pituus;
int haluttuja_lautoja;
long haluttu_patka;
int lautoja;
map<long, int> lautakasa;
long kustannus = 0;

int main() {
  cin >> laudan_pituus >> haluttuja_lautoja;
  for (int i = 0; i < haluttuja_lautoja; i++) {
    cin >> haluttu_patka;
    lautoja = lautakasa[haluttu_patka];
    lautoja++;
    lautakasa[haluttu_patka] = lautoja;
  }

  if (haluttuja_lautoja == 2) {
    kustannus = laudan_pituus;
  } else if (haluttu_patka != laudan_pituus) {
    auto it = lautakasa.rbegin();
    while (it != lautakasa.rend()) {
      haluttu_patka = it->first;
      lautoja = it->second;
      long tulo = haluttu_patka*lautoja;
      laudan_pituus = laudan_pituus - tulo;
      kustannus = kustannus + tulo + laudan_pituus;
      cout << kustannus << "\n";
      if (lautoja != 1) {
        if (lautoja % 2 == 0) {
          kustannus = kustannus + (lautoja * haluttu_patka);
        } else {
          kustannus = kustannus + tulo;
          lautoja = lautoja - 1;
          kustannus = kustannus + (lautoja * haluttu_patka);
        }
      }
      it++;
    }
  }
  cout << kustannus << "\n";
}
