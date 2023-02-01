#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int oferta(const vector<int>& preus){
  int sum = 0;
  for (int i = 0; i < int(preus.size()); i+=3) sum += preus[i] + preus[i+1];
  return sum;
}

bool ordena_gran(int& a, int& b){
  return a > b;
}

void ordena(vector<int>& preus){
  sort(preus.begin(), preus.end(), ordena_gran);
}

int main(){
  int n;
  while (cin >> n){
    if (n == 0) cout << 0 << endl;
    else{
      vector<int> preus(3*n);
      for (int i = 0; i < 3*n; ++i) cin >> preus[i];
      ordena(preus);
      cout << oferta(preus) << endl;
    }
  }
}
