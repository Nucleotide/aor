#include <iostream>
using namespace std;
#include<math.h>
int lukuja;

bool isPrime(int number) {
  int vertailu = floor(sqrt(number));
  if (number == 1 || number == 2 || number == 3) {
    return true;
  } else {
    for (int i = 2; i <= vertailu; i++) {
      if (number % i == 0) {
        return false;
      }
    }
    return true;
  }
}

int main() {
  cin >> lukuja;
  int rivi_toka[lukuja];
  for (int j = 0; j < lukuja; j++) {
    rivi_toka[j] = 0;
  }

  if (isPrime(lukuja + 1)) {
    for (int i = 0; i < lukuja; i++) {
      cout << i + 1 << " ";
      rivi_toka[i] = lukuja - i;
    }
  } else if (isPrime(lukuja + 2)) {
    rivi_toka[0] = 1;
    cout << 1 << " ";
    for (int i = 1; i < lukuja; i++) {
      cout << i + 1 << " ";
      rivi_toka[i] = lukuja + 1 - i;
    }
  } else {
    int n = 3;
    while (!isPrime(lukuja + n)) {
      n++;
    }

    if (n == 8) {
      for (int i = 0; i < n - 1; i++) {
        cout << i + 1 << " ";
        rivi_toka[i] = n - 1 - i;
      }
      rivi_toka[0] = 1;
      rivi_toka[1] = 3;
      rivi_toka[2] = 2;
      rivi_toka[3] = 7;
      rivi_toka[4] = 6;
      rivi_toka[5] = 5;
      rivi_toka[6] = 4;

    } else if (n % 2 != 0) {
      for (int i = 0; i < n - 1; i++) {
        cout << i + 1 << " ";
        rivi_toka[i] = n - 1 - i;
      }
    } else {
      for (int i = 0; i < n - 1; i++) {
        cout << i + 1 << " ";

        if (i == 0) {
          rivi_toka[0] = 1;
        } else {
          rivi_toka[i] = n - i;
        }
      }
    }

    for (int j = n - 1; j < lukuja; j++) {
      cout << j + 1 << " ";
      rivi_toka[j] = lukuja + n - 1 - j;
    }
  }

  cout << "\n";
  for (int j = 0; j < lukuja; j++) {
    cout << rivi_toka[j] << " ";
  }
  cout << "\n";
}
