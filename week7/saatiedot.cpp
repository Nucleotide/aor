#include <iostream>
using namespace std;

typedef long long ll;

int paivia, kyselyja, alku, haluttuja, koko, arvo, pituus;

int main() {
  cin >> paivia >> kyselyja;
  koko = 2;
  while (koko < paivia) {
    koko = koko * 2;
  }

  int puutaulu[koko * 2];
  int tulostaulu[kyselyja];

  for (int j = 0; j < koko*2; j++) {
    puutaulu[j] = 0;
  }

  for (int i = 0; i < paivia; i++) {
    cin >> arvo;
    puutaulu[i+koko] = arvo;
  }

  //fill in first values
  for (int i = koko; i < koko * 2 - 1; i++) {
    int eka = puutaulu[i];
    int toka = puutaulu[i+1];
    puutaulu[i/2] = eka + toka;
    i++;
  }

  //fill rest of the tree
  for (int y = koko/2 - 1; y > 0; y--) {
    puutaulu[y] = puutaulu[y*2] + puutaulu[y*2+1];
  }

  for (int o = 0; o < kyselyja; o++) {
    cin >> alku >> haluttuja;
    alku += koko -1;
    int a = alku;
    pituus=puutaulu[alku];
    int kertyma = pituus;

    while (pituus < haluttuja && pituus != -1) {
      int parent = alku / 2;
      kertyma = pituus;
      // if we go up from left child we can include right child nodes to possible sum.
      if (alku % 2 == 0) {
        pituus += puutaulu[parent*2+1];
      }
      if (parent == 1 && pituus < haluttuja) {
        pituus = -1;
        tulostaulu[o] = pituus;
      }
      alku /= 2;
    }

    if (pituus != -1) {
      if (kertyma == haluttuja) {
        tulostaulu[o] = kertyma;
      } else {
      //  cout << "KERTYMÄ VASEMMALTA JA ALOITUSPAIKKA " << kertyma << " " << alku << "\n";
        //move to first right child
        if (alku * 2 < koko) {
          alku = alku * 2 + 1;
        }
        int puuttuvia = haluttuja - kertyma;
        //cout << "PUUTTUVIA ON SEKÄ SOLUN ARVO " << puuttuvia << " " << puutaulu[alku] << "\n";
        while (puuttuvia > 0) {
          if (alku * 2 >= koko) {
            //ollaan puun viimeisellä rivillä.
            if (puuttuvia == 2) {
              alku = alku * 2 + 1;
              puuttuvia = 0;
            } else {
              if (puutaulu[alku * 2] == 1 && (alku*2 != a)) {
                alku = alku * 2;
              } else {
                alku = alku * 2 + 1;
              }
              puuttuvia = 0;
            }
            tulostaulu[o] = alku - a + 1;
          } else {
            int left_child_count = puutaulu[alku*2];
            if (left_child_count < puuttuvia) {
              puuttuvia = puuttuvia - left_child_count;
              alku = alku * 2 + 1;
            } else {
              alku = alku * 2;
            }
          }
        }
      }
    }
  }

  for (int u = 0; u < kyselyja; u++) {
    cout << tulostaulu[u] << "\n";
  }
}
