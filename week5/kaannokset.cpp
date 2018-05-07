#include <iostream>
using namespace std;

int ruutuja, pienin;
string rivi;

int main() {
  cin >> ruutuja;
  char grid[ruutuja][ruutuja];
  int count[ruutuja][ruutuja];
  int pienisuunta[ruutuja][ruutuja];

  for (int k = 0; k < ruutuja; k++) {
    cin >> rivi;
    for (int j = 0; j < ruutuja; j++) {
      grid[k][j] = rivi[j];
    }
  }

  count[0][0] = 0;
  for (int i = 0; i < ruutuja; i++) {
    for (int n = 0; n < ruutuja; n++) {
      int ev=-1;
      int ey=-1;

      if (i==0 && n ==0) {
        continue;
      } else if (grid[i][n] == '*') {
        count[i][n] = -1;
      } else {
        if (i > 0) {
          ey = count[i-1][n];
          if (ey != -1) {
            if (i == 1 && n != 0) {
              ey++;
            } else if (i > 1) {
              if (grid[i-2][n] == '*' || count[i-2][n] == -1 || pienisuunta[i-1][n] == 2) {
                ey++;
              }
            }
          }
        }

        if (n > 0) {
          ev = count[i][n-1];
          if (ev != -1) {
            if (n == 1 && i != 0) {
              ev++;
            } else if (n > 1) {
              if (grid[i][n-2] == '*' || count[i][n-2] == -1 || pienisuunta[i][n-1] == 1) {
                ev++;
              }
            }
          }
        }

        if (ev >= 0 && ey >= 0) {
          if (ey < ev) {
            count[i][n] = ey;
            pienisuunta[i][n] = 1;
          } else if (ey == ev) {
            count[i][n] = ey;
            pienisuunta[i][n] = 3;
          } else {
            count[i][n] = ev;
            pienisuunta[i][n] = 2;
          }
        } else {
          if (ey > ev) {
            count[i][n] = ey;
            pienisuunta[i][n] = 1;
          } else if (ey == ev) {
            count[i][n] = ey;
            pienisuunta[i][n] = 3;
          } else {
            count[i][n] = ev;
            pienisuunta[i][n] = 2;
          }
        }
      }
    }
  }

  int tulos = count[ruutuja-1][ruutuja-1];

  if (grid[ruutuja-1][ruutuja-1] == '*') {
    tulos = -1;
  }

  cout << tulos << "\n";
}
