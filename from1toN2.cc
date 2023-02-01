// INCLUDES
#include <iostream>
#include <vector>
using namespace std;

// VARIABLES GLOBALS
int n;

// FUNCIONS I ACCIONS
void write(const vector<int>& permutacio){
  cout << "(";
  if (n > 0){
    cout << permutacio[0]+1;
    for (int i = 1; i < n; ++i){
      cout << "," << permutacio[i]+1;
    }
  }
  cout << ")" << endl;
}

void genera(int posToFill, vector<bool>& posats, vector<int>& permutacio, int count){
  // Base case:
  if (count == n-1){
    permutacio[posToFill] = 0;
    write(permutacio);
  }
  // Recursive case:
  else{
    for (int nombre = 0; nombre < n; ++nombre){
      if (posToFill != nombre and not posats[nombre]){
        posats[nombre] = true;
        permutacio[posToFill] = nombre;
        genera(nombre, posats, permutacio, count+1);
        posats[nombre] = false;
      }
    }
  }
}

// COS PRINCIPAL
int main(){
  cin >> n;
  vector<int> permutacio(n);
  vector<bool> posats(n, false);
  posats[0] = true;
  genera(0, posats, permutacio, 0);
}
