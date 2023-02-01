#include <iostream>
#include <vector>
using namespace std;

using Matriu = vector<vector<char>>;
using Matrix = vector<vector<int>>;

Matriu laberint;
Matrix camins;

int resultat(int i, int j){
  if (i < 0 or j < 0) return 0;
  if (camins[i][j] != -1) return camins[i][j];
  if (laberint[i][j] == 'X') return camins[i][j] = 0;
  if (i == 0 and j == 0) return camins[i][j] = 1;
  camins[i][j] = resultat(i - 1, j) + resultat(i, j - 1);
  if (camins[i][j] >= 1e6) camins[i][j] = 1e7;
  return camins[i][j];
}

int main(){
  int n, m;
  while(cin >> n >> m and n+m > 0){
    laberint = Matriu(n, vector<char> (m));
    camins = Matrix(n, vector<int> (m, -1));
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < m; ++j){
        cin >> laberint[i][j];
      }
    }
    int res = resultat(n-1, m-1);
    if (res > 1e6) cout << "!!!" << endl;
    else cout << res << endl;
  }
}
