#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, D, n;
int stops = 0;

void how_many_stops(const vector<int>& where, int Following, int WhereAmINow, int stops, int Acumulated){
  if (Following == n+1) cout << stops << endl;
  else{
    if (where[Following] - where[WhereAmINow] + Acumulated > x) how_many_stops(where, Following, WhereAmINow, stops + 1, 0);
    else how_many_stops(where, Following + 1, Following, stops, where[Following] - where[WhereAmINow] + Acumulated);
  }
}

int main(){
  while(cin >> x >> D){
    cin >> n;
    vector<int> where(n+1);
    for (int i = 0; i < n; ++i) cin >> where[i];
    where[n] = D;
    sort(where.begin(), where.end());
    how_many_stops(where, 1, 0, 0, where[0]);
  }
}
