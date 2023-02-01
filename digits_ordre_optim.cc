#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int m, n;
int best = 0;
using Graf = vector<vector<int>>;
Graf premis;

void optimitza(int& nombre, vector<bool>& used, int index, int cost, int prev){
  if (index > 0 and nombre%m == 0) return;
  if (index == n){
    if (cost > best) best = cost;
  }
  else{
    for (int i = 1; i <= n; ++i){
      if (not used[i]){
        nombre = nombre*10 + i;
        used[i] = true;
        if (prev > 0) cost += premis[prev-1][i-1];
        optimitza(nombre, used, index+1, cost, i);
        if (prev > 0) cost -= premis[prev-1][i-1];
        used[i] = false;
        nombre =  nombre - i;
        nombre /= 10;
      }
    }
  }
}

int main(){
  while (cin >> m >> n){
    premis = Graf (n, vector<int> (n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> premis[i][j];
    int nombre = 0;
    vector<bool> used(n+1, false);
    optimitza(nombre, used, 0, 0, 0);
    cout << best << endl;
    best = 0;
  }
}
