#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int koneita, ed;
long tuotteita;
long ta, va, aloitusaika, hyppy, edaika;
long aika, koko;
bool valmis = false;
vector<long> tuotantoajat;

long monta_tehtiin(long aikaa) {
  long teemme = 0;
  long it = 0;
  while (it < koko) {
    if (tuotantoajat[it] > aikaa) {
      it = koko;
    } else if (teemme > tuotteita) {
      it = koko;
    } else {
      teemme = teemme + (aikaa / tuotantoajat[it]);
      it++;
    }
  }
  return teemme;
}

int main() {
  cin >> koneita >> tuotteita;
  for (int i = 0; i < koneita; i++) {
    cin >> ta;
    tuotantoajat.push_back(ta);
  }

  sort(tuotantoajat.begin(), tuotantoajat.end());
  koko = tuotantoajat.size();

  aloitusaika = tuotantoajat[0] * tuotteita;
  hyppy = aloitusaika / 2;


  while (!valmis) {
    va = monta_tehtiin(aloitusaika);
    if (va < tuotteita) {
      if (ed == 1 && abs(edaika - aloitusaika) == 1) {
        valmis = true;
        aika = aloitusaika + 1;
      }
      ed = -1;
      edaika = aloitusaika;
      aloitusaika = aloitusaika + hyppy;
      if (hyppy < 2) {
        hyppy = 1;
      } else {
        hyppy = hyppy / 2;
      }
    } else {
      if (ed == -1 && abs(edaika - aloitusaika) == 1) {
        valmis = true;
        aika = aloitusaika;
      }
      edaika = aloitusaika;
      aloitusaika = aloitusaika - hyppy;
      if (hyppy < 2) {
        hyppy = 1;
      } else {
        hyppy = hyppy / 2;
      }
      ed = 1;
    }
  }

  cout << aika << "\n";
}
