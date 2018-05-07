#include <iostream>
#include <vector>
using namespace std;

int n, luku;
long long m, em, lukuja;
vector<long long> prt;

int main() {
  cin >> n;
  lukuja = 0;
  m = 100*1000;
  bool f[m+1];
  f[0] = true;
  for (int i = 1; i <= n; i++) {
    cin >> luku;
    em = em + luku;
    for (int j = m - luku; j >= 0; j--) {
      if (f[j]) {
        f[j+luku] = true;
      }
    }
  }

  for (int j = 1; j <= em; j++) {
    if (f[j]) {
      lukuja ++;
      prt.push_back(j);
    }
  }
  cout << prt.size() << "\n";
  for (int k = 0; k < prt.size(); k++) {
    cout << prt[k] << " ";
  }
}
