#include <iostream>
using namespace std;
#define M 1000000007

int n, m, massa, raja, tulos;

int main() {
  cin >> n;
  massa = 0;
  int dp[1000001];
  int luvut[n];
  tulos = 0;
  for (int h = 0; h < n; h++) {
    cin >> m;
    massa += m;
    luvut[h] = m;
  }

  if (massa % 2 == 0) {
    raja = massa / 2;

    for (int y = 0; y < 1000001; y++) {
      dp[y] = 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      int luku = luvut[i];
      for (int j = raja-luku; j >= 0; j--) {
        dp[j+luvut[i]] += dp[j];
        dp[j+luvut[i]] %= M;
      }
      tulos = dp[raja];
    }
  }

  cout << tulos << "\n";
}
