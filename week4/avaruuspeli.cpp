#include <iostream>
#include <vector>
using namespace std;

long sailio;
int planeettoja;
long kultaa;
long rosvousta = 0;
long totaalisumma = 0;
vector<long> kultalista;

bool maaliin(long koko) {
  long saldo = 0;
  for (int k = 0; k < kultalista.size(); k++) {
    saldo = saldo + kultalista[k];
    if (saldo > koko) {
      saldo = koko;
    } else if (saldo < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> planeettoja;
  for (int i = 0; i < planeettoja; i++) {
    cin >> kultaa;
    kultalista.push_back(kultaa);
    totaalisumma = totaalisumma + kultaa;
    if (kultaa < 0) {
      rosvousta = rosvousta + kultaa;
    }
  }

  if ( totaalisumma < 0 ) {
    sailio = -1;
  } else if (kultalista[0] < 0) {
    sailio = -1;
  } else if (rosvousta == 0 ) {
    sailio = 0;
  } else {
    sailio = 0;
    for (long b = abs(rosvousta); b >= 1; b /= 2) {
      while (!maaliin(sailio+b)) {
        sailio += b;
      }
    }
    sailio = sailio + 1;
  }

  cout << sailio << "\n";
}
