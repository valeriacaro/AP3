#include <iostream>
#include <vector>
using namespace std;

int n, m;

using Graf = vector<vector<int>>;

vector<int> n_precedences;
Graf order;
// FUNCIONS I ACCIONS
Graf read_precedences(){
  order = Graf(n);
  int v, u;
  for (int i = 0; i < m; ++i){
    cin >> v >> u;
    order[v].push_back(u);
    ++ n_precedences[u]; // quants abans que ell em cal posar
  }
  return order;
}

void write(vector<int>& combinacions){
  cout << combinacions[0];
  for (int i = 1; i < n; ++i) cout << " " << combinacions[i];
  cout << endl;
}

void compute(vector<int>& combinacions, int index){
  if (index == n){
    write(combinacions);
  }
  else{
    for (int i = 0; i < n; ++i){
      if (n_precedences[i] == 0){
        -- n_precedences[i]; // equals to -1, indica q lhe posat
        combinacions[index] = i;
        for (int j : order[i]) --n_precedences[j];
        compute(combinacions, index+1);
        for (int j : order[i]) ++n_precedences[j];
        ++ n_precedences[i];
      }
    }
  }
}

// COS PRINCIPAL
int main(){
  cin >> n >> m;
  vector<int> combinacions(n);
  n_precedences = vector<int> (n, 0);
  read_precedences();
  compute(combinacions, 0);
}
