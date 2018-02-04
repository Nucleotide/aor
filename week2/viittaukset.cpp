#include <iostream>
#include <map>

using namespace std;

int n;
int x[1000001];
int suurin = 0;

int main() {
  std::map<int, int > viittaus_n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) {
    int arvo = x[i];
    if(viittaus_n.find(arvo) == viittaus_n.end()) {
      viittaus_n[arvo] = 1;
    } else {
      viittaus_n[arvo] = viittaus_n.find(arvo)->second + 1;
    }
  }

  map<int, int>::reverse_iterator it;

  for ( it = viittaus_n.rbegin(); it != viittaus_n.rend(); it++ ) {
    int n = it->first;
    int maara = it->second;
    if (maara >= n) {
      if (n > suurin) {
        suurin = n;
      }
    } else if (n > suurin) {
      if ((suurin + maara) > n) {
        suurin = n;
      } else {
        suurin = suurin + maara;
      }
    }
  }
  cout << suurin << "\n";
}
