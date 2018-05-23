#include <iostream>
using namespace std;

typedef long long ll;

int paivia, kyselyja, alku, loppu, koko;
ll arvo, suurin;

int main() {
  cin >> paivia >> kyselyja;
  koko = 2;
  suurin = 0;
  while (koko < paivia) {
    koko = koko * 2;
  }

  ll puutaulu[koko * 2];
  ll tulostaulu[kyselyja];

  for (int j = 0; j < koko*2; j++) {
    puutaulu[j] = 0;
  }

  for (int i = 0; i < paivia; i++) {
    cin >> arvo;
    puutaulu[i+koko] = arvo;
  }
  puutaulu[0] = 0;

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

  //print tree to check it's good
  //for (int h = 0; h < koko * 2; h++) {
  //  cout << puutaulu[h] << " ";
  //}
  //cout << "\n\n";

  for (int o = 0; o < kyselyja; o++) {
    cin >> alku >> loppu;
    alku += koko -1;
    loppu += koko - 1;
    suurin = 0;
    if (alku == loppu) {
      suurin = puutaulu[alku];
    } else {
      while (alku <= loppu) {
        if (alku%2 == 1) {
          suurin = max(suurin, puutaulu[alku++]);
        }
        if (loppu%2 == 0) {
          suurin = max(puutaulu[loppu--], suurin);
        }
        alku /= 2;
        loppu /= 2;
      }
    }
    tulostaulu[o] = suurin;
  }

  for (int u = 0; u < kyselyja; u++) {
    cout << tulostaulu[u] << "\n";
  }
}
