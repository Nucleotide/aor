#include <iostream>
using namespace std;
int n;
int siirtoja = 0;
string lista;


int main() {
  cin >> n;
  cin >> lista;
  int taulukko[n];
  int raja = lista.size();
  for (int i = 0; i < raja; i++) {
    taulukko[i] = int(lista[i]);
  }

  
  cout << siirtoja << "\n";
}
