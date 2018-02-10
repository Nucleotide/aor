#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kolikoita;
long arvo;
vector<long> arvot;
vector<long> summat;

int main() {
  cin >> kolikoita;
  for (int i = 0; i < kolikoita; i++) {
    cin >> arvo;
    arvot.push_back(arvo);
  }
  sort(arvot.begin(), arvot.end());

  if (arvot[0] != 1) {
    cout << 1 << "\n";
  } else {
    summat.push_back(1);
    for (int j = 1; j < kolikoita; j++) {
      if (arvot[j] > (summat.back() + 1)) {
        break;
      } else {
        summat.push_back(summat.back()+arvot[j]);
      }
    }
    cout << summat.back() + 1 << "\n";
  }
}
