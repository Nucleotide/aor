#include <iostream>
using namespace std;
#include <vector>

string rivi;
int pituus, c, a_paikka, b_paikka, cmax;
char merkki;
long long tulos, ed;

int main() {
  tulos = 0;
  cin >> rivi;
  pituus = rivi.size();
  vector<int> at;
  vector<int> bt;
  long long lt[pituus];
  int ct[pituus];
  c = 0;
  ed = 0;
  int ap = 0;

  for (int i = 0; i < pituus; i++) {
    merkki = rivi[i];
    if (merkki == 'A') {
      at.push_back(i);
    } else if (merkki == 'B') {
      bt.push_back(i);
    } else {
      c++;
    }
    ct[i] = c;
  }
  cmax = ct[pituus-1];

  for (int k = bt.size() - 1; k >= 0; k--) {
    b_paikka = bt[k];
    lt[b_paikka] = ed + cmax - ct[b_paikka];
    ed = ed + cmax - ct[b_paikka];
  }

  for (int j = 0; j < at.size(); j++) {
    a_paikka = at[j];
    for (int k = ap; k < bt.size(); k++) {
      if (bt[k] > a_paikka) {
        b_paikka = bt[k];
        tulos = tulos + lt[b_paikka];
        k = bt.size() + 1;
      } else {
        ap++;
      }
    }
  }
  cout << tulos << "\n";
}
