#include <iostream>
#include <vector>
using namespace std;

int n;
vector<double> numbers; // guardem els números
vector<vector<double>> resultat;

const double UNDEF = -1.0;

double max(int ini, int fin){
  double& res = resultat[ini][fin];
  if (res == UNDEF){
    if (ini == fin) return res = numbers[ini];
    else{
      res = -100000000000;
      for(int k = ini + 1; k <= fin; ++k){
        res = max(res, max(ini, k-1)+max(k, fin));
        res = max(res, max(ini, k-1)*max(k, fin));
      }
    }
  }
  return res;
}

int main(){
  cout.setf(ios::fixed);
  cout.precision(4);
  while (cin >> n){
    numbers = vector<double> (n+1);
    for (int i = 0; i < n; ++i) cin >> numbers[i];
    resultat = vector<vector<double>>(n+1, vector<double>(n+1, UNDEF));
    cout << max(0, n-1) << endl;
  }
}
