#include <iostream>
#include <set>
using namespace std;

long asiakas = -1;
int asiakkaita;
long tp, lp;
set<long> varaukset;

int main() {
  cin >> asiakkaita;

  for (int i = 0; i < asiakkaita; i++) {
    cin >> tp >> lp;
    if (asiakas == - 1) {
      auto loppu = varaukset.upper_bound(tp);
      if (loppu == varaukset.end()) {
        varaukset.insert(lp);
      } else if (*loppu > lp) {
        varaukset.insert(lp);
      } else {
        asiakas = i + 1;
      }

      if (tp != lp) {
        auto alku = varaukset.lower_bound(tp);
        if (*alku == tp) {
          asiakas = i + 1;
        } else {
          varaukset.insert(tp);
        }
      }
    }
  }

  cout << asiakas << "\n";
}
