#include <iostream>
using namespace std;

int ruutuja, pienin;
string rivi;

int main() {
  cin >> ruutuja;
  char grid[ruutuja][ruutuja];
  int count[ruutuja][ruutuja];

  for (int k = 0; k < ruutuja; k++) {
    cin >> rivi;
    for (int j = 0; j < ruutuja; j++) {
      grid[k][j] = rivi[j];
    }
  }

  count[0][0] = 0;
  for (int i = 0; i < ruutuja; i++) {
    for (int n = 0; n < ruutuja; n++) {
      int ev=0;
      int ey=0;
      if (i > 0) {
        ey = count[i-1][n];
        if (grid[i-1][n] == '*') {
          ey++;
        }
      }

      if (n > 0) {
        ev = count[i][n-1];
        if (grid[i][n-1] == '*') {
          ev++;
        }
      }

      if (n>0 && i >0) {
        count[i][n] = min(ey,ev);
      } else {
        count[i][n] = max(ey,ev);
      }
    }
  }

  int e = 0;
  if (grid[ruutuja-1][ruutuja-1] == '*') {
    e++;
  }

  cout << count[ruutuja-1][ruutuja-1] + e << "\n";
}
