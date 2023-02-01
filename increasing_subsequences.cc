#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  string word;
  while (cin >> word){
    int n = int(word.size());
    vector<long long int> sequences(n, 0);
    int total = 0;
    for (int i = 1; i < n; ++i){
      for (int j = 0; j < i; ++j){
        if (word[i] > word[j]) sequences[i] += 1 + sequences[j];
      }
      total += sequences[i];
    }
    cout << total << endl;
  }
}
