#include <iostream>

using namespace std;

#define M 1000000007

int n, k;

int main() {
  cin >> n >> k;
  int count[1000001];
  int maksimi[1000001];
  int tulos[1000001];

  maksimi[0] = 1;
  count[0] = 2;

  for(int i = 1; i <= n; i++) {
    maksimi[i] = maksimi[i-1] * 2;
    maksimi[i] %= M;
    tulos[i] = maksimi[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < k && i-j >= 0; j++) {
      count[i] += count[i-j];
      tulos[i] -= count[i-j];
      count[i] %= M;
      tulos[i] %= M;
    }
  }

  if (tulos[n] < 0) {
    cout << tulos[n] + M << "\n";
  } else {
    cout << tulos[n] << "\n";
  }
}
