#include <iostream>
using namespace std;
#include<math.h>
int lukuja;

bool isPrime(int number) {
  for (int i = 2; i < sqrt(number); i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> lukuja;
  int nextround = 0;
  int rivi_toka[lukuja];
  int use;
  for (int i = 1; i < lukuja+1; i++) {
    cout << i << " ";
    if (lukuja % 2 == 0) {
      use = lukuja - i + 1;
      if (nextround != 0) {
        use = nextround;
      }
      if (isPrime(use)) {
        rivi_toka[i-1] = use;
        nextround = 0;
      } else {
        rivi_toka[i-1] = use - 2;
        nextround = use;
      }
    } else {
      if (i == 1) {
        rivi_toka[i-1] = 1;
      } else {
        rivi_toka[i-1] = lukuja - i + 2;
      }
    }
  }
  cout << "\n";
  for (int j = 0; j < lukuja; j++) {
    cout << rivi_toka[j] << " ";
  }
}
