#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int intervals(const vector<int>& valors, int k){
  int intervals = 0;
  int primer = valors[0];
  for (int i = 1; i < int(valors.size()); ++i){
    if (primer - valors[i] > k){
      intervals += 1;
      primer = valors[i];
    }
  }
  return intervals + 1;
}

int main(){
  int k, n;
  while (cin >> k >> n){
    vector<int> valors(n);
    for (int i = 0; i < n; ++i) cin >> valors[i];
    sort(valors.begin(), valors.end(), greater<>());
    cout << intervals(valors, k) << endl;
  }
}
