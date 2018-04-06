#include <iostream>
using namespace std;

int lapsia, saa_k, ohituksia, lopulla;

int main() {
  cin >> lapsia;
  int jono[lapsia+1];

  for (int k = 1; k <= lapsia; k++) {
    cin >> ohituksia;
    jono[k] = ohituksia;
  }
    if (k==1) {
      saa_k++;
      if (ohituksia >= lapsia -1) {
        k = lapsia + 1;
      }
      lopulla = ohituksia;
    } else if (ohituksia >= lapsia -1) {
      saa_k++;
      k = lapsia + 1;
    } else {
      if ()
    }
  }

  cout << lapsia - saa_k << "\n";
}
