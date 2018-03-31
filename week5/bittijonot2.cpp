#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll laskepituudet(int l, int pj, int bytes, int raja, ll m, int haluttu) {
  if (bytes == raja) {
    return m;
  } else {
    if (l == 1) {
      if (pj >= haluttu) {
        m = laskepituudet(1, pj + 1, bytes + 1, raja, 1, haluttu) + laskepituudet(0, pj + 1, bytes + 1, raja, 1, haluttu);
      } else {
        m = laskepituudet(1, pj + 1, bytes + 1, raja, m, haluttu) + laskepituudet(0, 1, bytes + 1, raja, m, haluttu);
      }
    } else {
      if (pj == haluttu) {
        m = laskepituudet(1, pj + 1, bytes + 1, raja, 1, haluttu) + laskepituudet(0, pj + 1, bytes + 1, raja, 1, haluttu);
      } else {
        m = laskepituudet(1, 1, bytes + 1, raja, m, haluttu) + laskepituudet(0, pj + 1, bytes + 1, raja, m, haluttu);
      }
    }
  }
  return m;
}

int bitteja, pituus;

int main() {
  cin >> bitteja >> pituus;

  if (bitteja < pituus) {
    cout << 0 << "\n";
  } else if (bitteja == pituus) {
    cout << 2 << "\n";
  } else {
    cout << laskepituudet(1, 1, 0, bitteja, 0, pituus) << "\n";
  }
}
