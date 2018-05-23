#include <iostream>
#include <vector>
using namespace std;

int kursseja, riippuvuuksia, esitieto, suoritus;
vector <int>jarjestys;

void dfs(int s, vector<int> graph[], bool visited[]) {
   if (visited[s]) {
     return;
   } else {
     visited[s] = true;
     for (auto u : graph[s]) dfs(u, graph, visited);
     jarjestys.push_back(s);
   }
}


int main() {
  cin >> kursseja >> riippuvuuksia;
  vector<int> graph[kursseja+1];
  bool visited[kursseja+1];

  for (int i = 1; i <= riippuvuuksia; i++) {
    cin >> esitieto >> suoritus;
    graph[esitieto].push_back(suoritus);
  }

  for (int i = 0; i <=kursseja; i++) {
    visited[i] = false;
  }

  for (int k = 1; k <= kursseja; k++) {
    dfs(k, graph, visited);
  }

  auto y = jarjestys.rbegin();

  for ( auto y = jarjestys.rbegin(); y != jarjestys.rend(); y++) {
    cout << *y << " ";
  }

  cout << "\n";
}
