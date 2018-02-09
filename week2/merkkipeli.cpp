#include <iostream>
#include <vector>
using namespace std;

string sana;
vector<char> kirjaimet;
int koko;
char edellinen;

int main() {
  cin >> sana;
  for (int i = 0; i < sana.length(); i++) {
    koko = kirjaimet.size();
    if (koko == 0) {
      kirjaimet.push_back(sana[i]);
    } else {
      edellinen = kirjaimet[koko-1];
      if (edellinen != sana[i]) {
        kirjaimet.push_back(sana[i]);
      } else {
        kirjaimet.pop_back();
      }
    }
  }

  cout << kirjaimet.size() << "\n";
}
