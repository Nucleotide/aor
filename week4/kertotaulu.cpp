#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll lukuja, ruudun_arvo, n, keskimmainen;

bool ok(ll vrt) {
  ll raja = lukuja / 2;
  ll p = 0;
  ll suurempia, jako;

  for (ll i = n; i > 0; i--) {
    jako = vrt / i;
    suurempia = n - jako;
    p = p + suurempia;
    if (p > raja) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n;
  lukuja = n * n;

  keskimmainen = 0;
  for (ll b = lukuja; b >= 1; b /= 2) {
    while (!ok(keskimmainen+b)) {
      keskimmainen += b;
    }
  }

  cout << keskimmainen + 1 << "\n";
}
