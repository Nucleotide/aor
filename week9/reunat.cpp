#include <iostream>
using namespace std;

typedef long long ll;

int n;
string merkkijono;
ll A, B;

int main() {
  cin >> merkkijono;
  n = merkkijono.size();
  ll p[n+1];
  ll h[n+1];
  h[0] = 0;
  p[0] = 1;
  A = 70394;
  B = 9654321;

  for (int a = 0; a < n; a++) {
    char merkki = merkkijono[a];
    h[a+1] = (h[a] * A + int(merkki)) % B;
    p[a+1] = (p[a] * A) % B;
  }

  if (merkkijono[0] == merkkijono[n-1]) {
    cout << 1 << " ";
  }
  for (int j = 2; j < n; j++) {
    int a = 1;
    int b = j;
    int c = n-j+1;
    int d = n;
    ll alku = (h[b] - h[a-1] * p[b-a+1]) % B;
    ll loppu = (h[d] - h[c-1] * p[d-c+1]) % B;
    if (loppu < 0) {
      loppu = loppu + B;
    }
    if (alku == loppu) {
      cout << j << " ";
    }
  }
  cout << "\n";
}
