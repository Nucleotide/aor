#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lautoja;
long arvo;
long keski;
long muutoksia = 0;
long ero;
vector<long> pienet;

int main() {
  cin >> lautoja;
  for (int i = 0; i < lautoja; i++) {
    cin >> arvo;
    pienet.push_back(arvo);
  }
  sort(pienet.begin(), pienet.end());
  if (lautoja % 2 == 0) {
    keski = pienet[lautoja / 2];
  } else {
    keski = pienet[lautoja / 2 + 1];
  }

  for (int j=0; j < lautoja; j++) {
    if (keski != pienet[j]) {
      ero = abs(pienet[j] - keski);
      muutoksia = muutoksia + ero;
    }
  }
  cout << muutoksia << "\n";
}
