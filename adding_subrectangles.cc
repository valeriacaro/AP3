// INCLUDES
#include <iostream>
#include <vector>
using namespace std;

// VARIABLES GLOBALS
vector<vector<int>> M;

void write(){
  for (int i = 0; i < M.size(); ++i){
    for (int j = 0; j < M[0].size(); ++j){
      if (j > 0) cout << " ";
      cout << M[i][j];
    }
    cout << endl;
  }
}

int valor(char c){
  int n = c - 'A' + 1;
  return n*(n+1)/2;
}

int pie(int i, int j){
  if (i == 0 and j == 0) return 0;
  if (i == 0) return M[i][j-1];
  if (j == 0) return M[i-1][j];
  else return M[i][j-1] + M[i-1][j] - M[i-1][j-1];
}

int main(){
  vector<vector<char>> entrada;
  string fila;
  while (cin >> fila){
    entrada.push_back({});
    for (char c : fila) entrada.back().push_back(c);
  }
  M = vector<vector<int>> (entrada.size(), vector<int> (entrada[0].size()));
  for (int i = 0; i < M.size(); ++i){
    for (int j = 0; j < M[0].size(); ++j){
      M[i][j] = valor(entrada[i][j]) + pie(i, j);
    }
  }
  write();
}
