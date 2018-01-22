#include <iostream>
using namespace std;
int n;
int siirtoja = 0;
int to_compare;
int luku;
int table_index;


int main() {
  cin >> n;
  cin.ignore();
  string lukujono;
  int taulukko[n];
  string lista;
  getline(cin,lista);
  table_index = 0;
  for (int i = 0; i < lista.size(); i++) {
    if (isspace(lista[i])) {

    } else {
      lukujono += lista[i];
    }

    if (isspace(lista[(i+1)]) || lista.size() == (i + 1) ) {
      taulukko[table_index] = stoi(lukujono);
      lukujono = "";
      table_index++;
    }
  }

  for (int j = 0; j < n; j++) {
    luku = taulukko[j];
    if (j == 0) {
      to_compare = luku;
    } else {
      if (luku < to_compare) {
        siirtoja++;
      } else {
        if (to_compare + 1 != luku) {
          siirtoja++;
        }
        to_compare = luku;
      }
    }
  }
  cout << siirtoja << "\n";
}
