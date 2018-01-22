#include <iostream>
#include <map>
using namespace std;
string kirjainjono;
int merkkitaulu[30];
int jonon_pituus;
string uusi_sana;
int parittomia = 0;


int main() {
  cin >> kirjainjono;
  std::map<char, int > char_count_map;
  jonon_pituus = kirjainjono.size();
  for (int i = 0; i < jonon_pituus; i++) {
    if(char_count_map.find(kirjainjono[i]) == char_count_map.end()) {
      char_count_map[kirjainjono[i]] = 1;
    } else {
      char_count_map[kirjainjono[i]] = char_count_map.find(kirjainjono[i])->second + 1;
    }
  }
  for (std::map<char,int>::iterator it=char_count_map.begin(); it!=char_count_map.end(); ++it)
    if (it->second % 2 != 0) {
      parittomia++;
    }

  if (parittomia > 1) {
    cout << "NO SOLUTION\n";
  } else if (parittomia == 1 && jonon_pituus % 2 == 0) {
    cout << "NO SOLUTION\n";
  } else {
    cout << "TEE SANA\n";
  }
}
