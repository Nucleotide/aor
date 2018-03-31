#include <iostream>
using namespace std;

typedef long long ll;

int paivia, kyselyja, alku, loppu;
ll arvo, suurin;

int main() {
  cin >> paivia >> kyselyja;
  ll arvot[paivia];
  ll tulostukset[kyselyja];
  for (int i = 0; i < paivia; i++) {
    cin >> arvo;
    arvot[i] = arvo;
  }

  for (int j = 1; j <= kyselyja; j++) {
    suurin = 0;
    cin >> alku >> loppu;
    alku = alku - 1;
    for (int k = alku; k < loppu; k++) {
      if (arvot[k] > suurin) {
        suurin = arvot[k];
      }
    }
    tulostukset[j - 1] = suurin;
  }

  for (int h = 0; h < kyselyja; h++) {
    cout << tulostukset[h] << "\n";
  }
}
