#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int taulukon_koko, alitaulukon_koko;
long arvo, valiarvo, ph, eka, toka;
int loppuindeksi, alkuindeksi = 0;
map<long, int> esiintymat;
pair<long, long> esiintyja = {0,0};
vector<long> arvot;

int main() {
  cin >> taulukon_koko >> alitaulukon_koko;

  while (loppuindeksi < alitaulukon_koko) {
    cin >> arvo;
    arvot.push_back(arvo);
    valiarvo = esiintymat[arvo];
    valiarvo++;
    if (valiarvo > esiintyja.second) {
      esiintyja = {arvo, valiarvo};
    } else if (valiarvo == esiintyja.second && arvo < esiintyja.first) {
      esiintyja = {arvo, valiarvo};
    }
    esiintymat[arvo] = valiarvo;
    loppuindeksi++;
  }

  cout << esiintyja.first << " ";

  while (loppuindeksi < taulukon_koko) {
    cin >> arvo;
    arvot.push_back(arvo);

    ph = arvot[alkuindeksi];
    valiarvo = esiintymat[ph];
    valiarvo = valiarvo - 1;
    esiintymat[ph] = valiarvo;

    valiarvo = esiintymat[arvo];
    valiarvo = valiarvo + 1;
    esiintymat[arvo] = valiarvo;

    if (esiintyja.first == ph) {
      eka = esiintyja.first;
      toka = esiintyja.second;
      toka = toka - 1;
      esiintyja = {eka, toka};
      if (valiarvo > (toka + 1)) {
        esiintyja = {arvo, valiarvo};
      } else {
        auto it=esiintymat.begin();
        while (it != esiintymat.end()) {
          if (it->second > esiintyja.second) {
            eka = it->first;
            toka = it->second;
            esiintyja = {eka, toka};
            it = esiintymat.end();
          } else if (esiintyja.second == it->second && it->first < esiintyja.first) {
            eka = it->first;
            toka = it->second;
            esiintyja = {eka, toka};
          }
          it++;
        }
      }
    } else if (valiarvo > esiintyja.second) {
      esiintyja = {arvo, valiarvo};
    } else if (valiarvo == esiintyja.second && arvo < esiintyja.first) {
      esiintyja = {arvo, valiarvo};
    }

    cout << esiintyja.first << " ";

    alkuindeksi++;
    loppuindeksi++;
  }

  cout << "\n";
}
