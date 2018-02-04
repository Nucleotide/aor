#include <iostream>
#include <map>
using namespace std;
string kirjainjono;
int jonon_pituus;
int parittomia = 0;
int taulukko_paikka = 0;


int main() {
  cin >> kirjainjono;
  std::map<char, int > char_count_map;
  jonon_pituus = kirjainjono.size();
  char uusi_sana[jonon_pituus];
  for (int i = 0; i < jonon_pituus; i++) {
    if(char_count_map.find(kirjainjono[i]) == char_count_map.end()) {
      char_count_map[kirjainjono[i]] = 1;
    } else {
      char_count_map[kirjainjono[i]] = char_count_map.find(kirjainjono[i])->second + 1;
    }
  }
  map<char, int>::iterator it;
  for ( it = char_count_map.begin(); it != char_count_map.end(); it++ ) {
    char merkki = it->first;
    int maara = it->second;
    int y = 1;
    if (maara % 2 != 0) {
      parittomia++;
      uusi_sana[jonon_pituus / 2] = merkki;
    }
    while (y < maara) {
      uusi_sana[taulukko_paikka] = merkki;
      uusi_sana[jonon_pituus - taulukko_paikka - 1] = merkki;
      taulukko_paikka++;
      y = y + 2;
    }
  }


  if (parittomia > 1) {
    cout << "NO SOLUTION\n";
  } else if (parittomia == 1 && jonon_pituus % 2 == 0) {
    cout << "NO SOLUTION\n";
  } else {
    for (int j = 0; j < jonon_pituus; j++) {
      cout << uusi_sana[j];
    }
  }
}
