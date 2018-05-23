#include <iostream>
using namespace std;

typedef long long ll;

int hotelleja, ryhmia, alku;
ll vapaita, rkoko, koko;

int main() {
  cin >> hotelleja >> ryhmia;
  koko = 2;
  while (koko < hotelleja) {
    koko = koko * 2;
  }

  ll puutaulu[koko * 2];
  ll tulostaulu[ryhmia];

  for (int j = 0; j < koko*2; j++) {
    puutaulu[j] = 0;
  }

  for (int i = 0; i < hotelleja; i++) {
    cin >> vapaita;
    puutaulu[i+koko] = vapaita;
  }

  //fill in first values
  for (int i = koko; i < koko * 2 - 1; i++) {
    int eka = puutaulu[i];
    int toka = puutaulu[i+1];
    puutaulu[i/2] = max(eka, toka);
    i++;
  }

  //fill rest of the tree
  for (int y = koko/2 - 1; y > 0; y--) {
    puutaulu[y] = max(puutaulu[y*2], puutaulu[y*2+1]);
  }

  for (int o = 0; o < ryhmia; o++) {
    cin >> rkoko;
    alku = koko;
    alku /= 2;
    ll arvo = puutaulu[alku];
    while (arvo < rkoko && alku > 1) {
      alku /= 2;
      arvo = puutaulu[alku];
    }

    if (arvo < rkoko) {
      tulostaulu[o] = -1;
    } else {
      while(alku * 2 < koko) {
        //haetaan node josta sitten valitaan taulukon lopullinen kohta
        if (puutaulu[alku * 2] >= rkoko) {
          alku *= 2;
        } else {
          alku = alku * 2 + 1;
        }
      }

      // valitaan left vai right child
      if (puutaulu[alku*2] >= rkoko) {
        alku = alku *2;
      } else {
        alku = alku*2+1;
      }

      tulostaulu[o] = alku - koko + 1;
      puutaulu[alku] -= rkoko;

      for (int y = alku/2; y >= 1; y/=2) {
        int vanha = puutaulu[y];
        puutaulu[y] = max(puutaulu[y*2], puutaulu[y*2+1]);
      }
    }
  }

  for (int u = 0; u < ryhmia; u++) {
    cout << tulostaulu[u] << " ";
  }
  cout << "\n";
}
