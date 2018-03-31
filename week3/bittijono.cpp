#include <iostream>
#include <map>

using namespace std;

int pisin, muutoksia, muuttuva, np;
string jono;
map<int, int> pituudet;

int main() {
  cin >> jono;
  cin >> muutoksia;
  char taulu[jono.size()+1];
  int i = 1;
  while (i <= jono.size()) {
    char m = jono[i-1];
    taulu[i] = m;
    if (i == 1) {
      np = 1;
      if (jono.size() == 1) {
        pituudet[np] += 1;
      }
    } else {
      if (m == taulu[i-1]) {
        np += 1;
        if (i+1 > jono.size()) {
          pituudet[np] += 1;
        }
      } else {
        pituudet[np] += 1;
        np = 1;
        if (i+1 > jono.size()) {
          pituudet[np] += 1;
        }
      }
    }
    i++;
  }

  for (int k = 1; k <= muutoksia; k++) {
    cin >> muuttuva;
    char uusi_merkki;
    char muokattava = taulu[muuttuva];
    if (muokattava == '1') {
      uusi_merkki = '0';
    } else {
      uusi_merkki = '1';
    }
    int sp = 0;

    // Editing first
    if (muuttuva == 1) {
      if (taulu[2] == muokattava) {
        sp = 2;
        for (int h = 3; h <= jono.size(); h++) {
          if (taulu[h] == muokattava) {
            sp++;
          } else {
            h = jono.size() + 1;
          }
        }
        int p = pituudet[sp];
        if (p==1) {
          pituudet.erase(sp);
        } else {
          pituudet[sp] = p - 1;
        }
        pituudet[1]++;
        pituudet[sp-1]++;
      } else {
        sp = 1;
        for (int h = 3; h <= jono.size(); h++) {
          if (taulu[h] != muokattava) {
            sp++;
          } else {
            h = jono.size() + 1;
          }
        }
        int p = pituudet[sp];
        if (p==1) {
          pituudet.erase(sp);
        } else {
          pituudet[sp] = p - 1;
        }
        int ip = pituudet[1];
        if (ip==1) {
          pituudet.erase(ip);
        } else {
          pituudet[1] = ip - 1;
        }
        pituudet[sp+1]++;
      }

      taulu[1] = uusi_merkki;
      pisin = pituudet.rbegin()->first;

    // Editing last
    } else if (muuttuva == jono.size()) {
      if (taulu[muuttuva-1] == muokattava) {
        sp = 2;
        for (int h = muuttuva - 2; h > 0; h--) {
          if (taulu[h] == muokattava) {
            sp++;
          } else {
            h = 0;
          }
        }
        int p = pituudet[sp];
        if (p==1) {
          pituudet.erase(sp);
        } else {
          pituudet[sp] = p - 1;
        }
        pituudet[1]++;
        pituudet[sp-1]++;
      } else {
        sp = 1;
        for (int h = muuttuva - 2; h > 0; h--) {
          if (taulu[h] != muokattava) {
            sp++;
          } else {
            h = 0;
          }
        }
        int p = pituudet[sp];
        if (p==1) {
          pituudet.erase(sp);
        } else {
          pituudet[sp] = p - 1;
        }
        int ip = pituudet[1];
        if (ip==1) {
          pituudet.erase(ip);
        } else {
          pituudet[1] = ip - 1;
        }
        pituudet[sp+1]++;
      }

      taulu[muuttuva] = uusi_merkki;
      pisin = pituudet.rbegin()->first;

    // Editing middle
    } else {
      // Middle is different
      if (muokattava != taulu[muuttuva-1] && muokattava != taulu[muuttuva+1]) {
        int left_diff = 1;
        int right_diff = 1;
        for (int h = muuttuva - 2; h > 0; h--) {
          if (taulu[h] != muokattava) {
            left_diff++;
          } else {
            h = 0;
          }
        }
        for (int h = muuttuva + 2; h <= jono.size(); h++) {
          if (taulu[h] != muokattava) {
            right_diff++;
          } else {
            h = jono.size() + 1;
          }
        }
        int p = pituudet[left_diff];
        if (p==1) {
          pituudet.erase(left_diff);
        } else {
          pituudet[left_diff] = p - 1;
        }

        int pp = pituudet[right_diff];
        if (pp==1) {
          pituudet.erase(right_diff);
        } else {
          pituudet[right_diff] = pp - 1;
        }

        int ip = pituudet[1];
        if (ip==1) {
          pituudet.erase(ip);
        } else {
          pituudet[1] = ip - 1;
        }
        pituudet[right_diff + left_diff + 1]++;

      // Left is different
      } else if (muokattava != taulu[muuttuva-1]) {
        int left_diff = 1;
        int right_same = 1;
        for (int h = muuttuva - 2; h > 0; h--) {
          if (taulu[h] != muokattava) {
            left_diff++;
          } else {
            h = 0;
          }
        }
        for (int h = muuttuva + 2; h <= jono.size(); h++) {
          if (taulu[h] == muokattava) {
            right_same++;
          } else {
            h = jono.size() + 1;
          }
        }
        int p = pituudet[left_diff];
        if (p==1) {
          pituudet.erase(left_diff);
        } else {
          pituudet[left_diff] = p - 1;
        }

        int pp = pituudet[right_same+1];
        if (pp==1) {
          pituudet.erase(right_same+1);
        } else {
          pituudet[right_same+1] = pp - 1;
        }

        pituudet[right_same]++;
        pituudet[left_diff + 1]++;

      // Right is different
      } else if (muokattava != taulu[muuttuva+1]) {
        int left_same = 1;
        int right_diff = 1;
        for (int h = muuttuva - 2; h > 0; h--) {
          if (taulu[h] == muokattava) {
            left_same++;
          } else {
            h = 0;
          }
        }
        for (int h = muuttuva + 2; h <= jono.size(); h++) {
          if (taulu[h] != muokattava) {
            right_diff++;
          } else {
            h = jono.size() + 1;
          }
        }
        int p = pituudet[left_same + 1];
        if (p==1) {
          pituudet.erase(left_same + 1);
        } else {
          pituudet[left_same + 1] = p - 1;
        }

        int pp = pituudet[right_diff];
        if (pp==1) {
          pituudet.erase(right_diff);
        } else {
          pituudet[right_diff] = pp - 1;
        }

        pituudet[left_same]++;
        pituudet[right_diff+1]++;

      // Middle is same with both sides
      } else {
        int left_same = 1;
        int right_same = 1;
        for (int h = muuttuva - 2; h > 0; h--) {
          if (taulu[h] == muokattava) {
            left_same++;
          } else {
            h = 0;
          }
        }
        for (int h = muuttuva + 2; h <= jono.size(); h++) {
          if (taulu[h] == muokattava) {
            right_same++;
          } else {
            h = jono.size() + 1;
          }
        }

        int summa = left_same + right_same + 1;
        int p = pituudet[summa];
        if (p==1) {
          pituudet.erase(summa);
        } else {
          pituudet[summa] = p - 1;
        }
        pituudet[1]++;
        pituudet[left_same]++;
        pituudet[right_same]++;
      }

      taulu[muuttuva] = uusi_merkki;
      pisin = pituudet.rbegin()->first;
    }

    cout << pisin << " ";
  }
  cout << "\n";
}
