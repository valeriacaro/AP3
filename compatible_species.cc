#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k;
vector<char> species;
map<char, int> relations;
using Graf = vector<vector<bool>>;

Graf incompatibilities;

// COS PRINCIPAL
void write(const vector<int>& combinacions){
  for (int i = 0; i < n; ++i) cout << species[combinacions[i]];
  cout << endl;
}

void permuta(vector<int>& combinacions, vector<bool>& used, int index){
  if (index == n) write(combinacions);
  else{
    for (int i = 0; i < n; ++i){
      if (not used[i]){
        if (index == 0 or not incompatibilities[combinacions[index-1]][i]){
          used[i] = true;
          combinacions[index] = i;
          permuta(combinacions, used, index + 1);
          used[i] = false;
        }
      }
    }
  }
}

int main(){
  cin >> n;
  species = vector<char> (n);
  char specie;
  incompatibilities = Graf (n, vector<bool> (n, false));
  for (int i = 0; i < n; ++i){
    cin >> specie;
    relations.insert({specie, i});
    species[i] = specie;
  }
  char s1, s2;
  cin >> k;
  for (int i = 0; i < k; ++i){
    cin >> s1 >> s2;
    incompatibilities[relations[s1]][relations[s2]] = true;
    incompatibilities[relations[s2]][relations[s1]] = true;
  }
  vector<bool> used(n, false);
  vector<int> combinacions (n);
  permuta(combinacions, used, 0);
}
