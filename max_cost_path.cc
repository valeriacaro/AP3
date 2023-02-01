#include <iostream>
#include <vector>
using namespace std;

int n;
using Graf = vector<vector<int>>;
int best = 0;
Graf camins;

void optimitza(vector<bool>& used, int prev, int cost){
  if (cost > best) best = cost;
  for (int i = 0; i < n; ++i){
    if (not used[i]){
      used[i] = true;
      optimitza(used, i, cost + camins[prev][i]);
      used[i] = false;
    }
  }
}

int main(){
  cin >> n;
  if (n != 0){
    camins = Graf(n, vector<int> (n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> camins[i][j];
    int x;
    cin >> x;
    vector<bool> used(n, false);
    used[x] = true;
    optimitza(used, x, 0);
    cout << best << endl;
  }
}
