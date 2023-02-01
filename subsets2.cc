// INCLUDES
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// VARIABLES GLOBALS
int subsetSize, wordsSize;

// FUNCIONS I ACCIONS
void write(const vector<string>& subset){
  if (subsetSize == 0) cout <<"{}" << endl;
  if (subsetSize > 0){
    cout << "{" << subset[0];
    for (int i = 1; i < subsetSize; ++i) cout << ", " << subset[i];
    cout << "}" << endl;
  }
}

void genera(vector<string>& words, vector<string>& subset, int index, int count){
  if (count == subsetSize) write(subset);
  else if (wordsSize - (index - count) >= subsetSize){
    genera(words, subset, index+1, count);
    subset[count] = words[index];
    genera(words, subset, index+1, count+1);
  }
}

// COS PRINCIPAL
int main(){
  cin >> subsetSize >> wordsSize;
  vector<string> words(wordsSize);
  vector<string> subset(subsetSize);
  for (int i = 0; i < wordsSize; ++i) cin >> words[i];
  if (wordsSize == subsetSize) write(words);
  else genera(words, subset, 0, 0);
}
