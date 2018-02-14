#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long n;
set<long> luvut;
set<long> ph;
long jaettu;
long tuloste;

int main() {
  cin >> n;
  ph.insert(2);
  ph.insert(3);
  ph.insert(5);

  while (luvut.size() < n) {
    auto it = ph.begin();
    jaettu = *it;
    ph.erase(it);
    luvut.insert(jaettu);
    ph.insert(jaettu*2);
    ph.insert(jaettu*3);
    ph.insert(jaettu*5);
  }
  auto iter = luvut.end();
  iter--;
  tuloste = *iter;

  cout << tuloste << "\n";
}
