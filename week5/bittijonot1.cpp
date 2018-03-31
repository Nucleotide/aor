#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll laskepituudet(int l, int pj, int bytes, int raja, ll m) {
  if (bytes == raja) {
    return m;
  } else {
    bytes = bytes + 1;
    if (l == 1) {
      if (pj == 0) {
        m = laskepituudet(0, raja - 1, bytes, raja, 1);
      } else {
        pj = pj - 1;
        m = laskepituudet(1, pj, bytes, raja, 1) + laskepituudet(0, raja - 1, bytes, raja, 1);
      }
    } else {
      if (pj == 0) {
        m = laskepituudet(1, raja - 1, bytes, raja, 1);
      } else {
        pj = pj - 1;
        m = laskepituudet(0, pj, bytes, raja, 1) + laskepituudet(1, raja - 1, bytes, raja, 1);
      }
    }
  }
  return m;
}

int bitteja, pituus;
ll n = 0;

int main() {
  cin >> bitteja >> pituus;
  ll f[bitteja+1];
  ll m = pow(10, 9) + 7;

  if (pituus == 1 || bitteja == 1) {
    f[bitteja] = 2;
  } else {
    f[0] = 1;
    f[1] = 2;
    f[2] = 4;
    for (int j = 3; j <= pituus; j++) {
      f[j] = laskepituudet(1, pituus - 1, 1, j, 2) * 2;
    }

    for (int i = pituus + 1; i <= bitteja; i++) {
      f[i] = 0;
      for (int k = 1; k <= pituus; k++) {
        f[i] = f[i] + f[i-k];
      }
      f[i] %= m;
    }
  }
  cout << f[bitteja] << "\n";
}
