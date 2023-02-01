#include <iostream>
#include <vector>
using namespace std;

typedef long long int lint;
int zeros, ones;

using Matrix = vector<vector<lint>>;

int main(){
  Matrix combinacions = Matrix(91, vector<lint>(92, 0));
  // there is only one possible combination with 0 zeros and 0 ones, 0 zeros and 1 one, 1 zero and 1 one, 1 zero and 4 ones, 0 zeros and 2 ones
  combinacions[0][1] = combinacions[0][2] = combinacions[1][1] = combinacions[0][3] = combinacions[1][5] = 1;
  // there are only two possible combinations with 1 zero and 1 one and 1 zero and 3 ones.
  combinacions[1][2] = combinacions[1][4] = 2;
  // there are only 3 possible combinations with 1 zero and 2 ones
  combinacions[1][3] = 3;
  while (cin >> zeros >> ones){
    ++ ones;
    for (int i = 2; i <= zeros; ++i){
      for (int j = 2; j <= ones; ++j){
        combinacions[i][j] = combinacions[i-1][j-1] + combinacions[i-1][j-2];
      }
    }
    cout << combinacions[zeros][ones] << endl;
  }
}
