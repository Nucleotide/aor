#include <iostream>
using namespace std;
int n;

int main() {
  cin >> n;
  if (n == 1) {
    cout << "1";
  } else if (n == 4) {
    cout << "2 4 1 3";
  } else if (n < 5) {
    cout << "NO SOLUTION\n";
  } else {
    int i = 1;
    int table[n];
    int index = 0;
    int index_two = 1;

    while (i <= n) {
      if (index < n) {
        table[index] = i;
        index = index + 2;
        i++;
      } else {
        break;
      }
    }

    while (i <= n) {
      if (index_two < n) {
        table[index_two] = i;
        index_two = index_two + 2;
        i++;
      }
    }
    for (int j = 0; j < n; j++) {
      cout << table[j] << " ";
    }
  }
}
