// INCLUDES
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// VARIABLES GLOBALS
int n;
using Graf = vector<vector<int>>;
int best = std::numeric_limits<int>::max();
Graf costos;

void genera(int posToFill, vector<bool>& posats, vector<int>& permutacio, int actual){
  // Base case:
  int prev = permutacio[posToFill-1];
  if (actual < best){
    if (posToFill == n and actual + costos[prev][0] < best) best = actual + costos[prev][0];
    // Recursive case:
    else{
      for (int nombre = 1; nombre < n; ++nombre){
        if (not posats[nombre]){
          posats[nombre] = true;
          permutacio[posToFill] = nombre;
          genera(posToFill+1, posats, permutacio, actual + costos[prev][nombre]);
          posats[nombre] = false;
        }
      }
    }
  }
}

// COS PRINCIPAL
int main(){
  while (cin >> n){
    if (n > 1){
      costos = Graf(n, vector<int> (n));
      for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
          cin >> costos[i][j];
        }
      }
      vector<int> permutacio(n);
      vector<bool> posats(n, false);
      posats[0] = true;
      permutacio[0] = 0;
      genera(1, posats, permutacio, 0);
      if (best == std::numeric_limits<int>::max()) cout << 0 << endl;
      else cout << best << endl;
      best = std::numeric_limits<int>::max();
    } else if (n == 1) cout << costos[0][0] << endl;
    else cout << endl;
  }
}
