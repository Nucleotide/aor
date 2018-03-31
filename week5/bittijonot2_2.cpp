#include <iostream>

using namespace std;

#define M 1000000007

int n, k;

int main() {
  cin >> n >> k;
  int count[1000001];

  if (k == 1) {
    count[0] = 1;
    for(int i = k; i <= n; i++) {
      count[i] = count[i-1] * 2;
      count[i] %= M;
    }
    cout << count[n]<< "\n";
  } else if (k == 2) {
    count[0] = 1;
    count[k] = 2;
    for(int i = k + 1; i <= n; i++) {
      count[i] = count[i-1] * 2 + 2;
      count[i] %= M;
    }
    cout << count[n]<< "\n";
  } else {
    count[0] = 2;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; i-j >= 0; j++) {
        if (j >= k) {
          count[i] += count[i-1];
          count[i] %= M;
        }

      }
    }
    cout << count[n]<< "\n";
  }
}
