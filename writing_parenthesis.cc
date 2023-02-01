// Paraules de longitud n: p(n) = sumatori_i=2_n(p(i-2)*p(n-i))

// INCLUDES
#include <iostream>
#include <vector>
using namespace std;

const int UNDEF = -1;
vector<long> used(68, UNDEF);

long catalan_number(int& i){

  long& value = used[i];

  if (value != UNDEF) return value;
  if (i == 0) return value = 1;

  value = 0;
  int l2 = 0;
  for (int l1 = 0; l1 <= i-2; ++l1){
    l2 = i - l1 -2;
    value += catalan_number(l1) * catalan_number(l2);
  }

  return value;
}

int main(){
  int n;
  while (cin >> n) cout << catalan_number(n) << endl;
}
