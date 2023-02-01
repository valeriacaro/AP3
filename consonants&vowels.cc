// P49889 - Consonants and vowels

// INCLUDES
#include <iostream>
#include <vector>
using namespace std;

// FUNCTIONS AND ACTIONS

/* write: writes letter by letter the whole word once it has been completed */
void write(const vector<char>& word){
  for (char letter : word) cout << letter;
  cout << endl;
}

/* generate_words: Generates all possible words taking into account all
   consonants and vowels. Every word begins with a consonant and after a
   consonant goes a vowel.
   Preconditions: same number of consonants and vowels */
void generate_words(int k, vector<char>& word, vector<char>& consonants, vector<char>& vowels, vector<bool>& mcons, vector<bool>& mvow){
  int n = consonants.size(); // = vowels.size()
  // Base case: if the word has been completed, we can write it
  if (k == 2*n) write(word);
  else{
    for (int i = 0; i < n ; ++i){
      if (k % 2 == 0 and not mcons[i]){ // If k is even, it's turn for a consonant
        mcons[i] = true; // Avoids repeated consonant in the future
        word[k] = consonants[i];
        generate_words(k + 1, word, consonants, vowels, mcons, mvow);
        mcons[i] = false;
    } else if (k % 2 == 1 and not mvow[i]){ // Turn for a vowel otherwise
        mvow[i] = true; // Avoids repeated vowel in the future
        word[k] = vowels[i];
        generate_words(k + 1, word, consonants, vowels, mcons, mvow);
        mvow[i] = false;
      }
    }
  }
}

// MAIN BODY

int main(){
  int n; // Number of consonants and vowels
  cin >> n;
  vector<char> consonants(n); // Contains consonants
  vector<char> vowels(n); // Contains vowels
  vector<char> word(2*n);
  vector<bool> mcons(n, false); // Will save if a consonant has been used or not
  vector<bool> mvow(n, false); // Will save if a vowel has been used or not
  // Read letters
  for (int i = 0; i < n; ++i) cin >> consonants[i];
  for (int j = 0; j < n; ++j) cin >> vowels[j];
  // Generate words
  generate_words(0, word, consonants, vowels, mcons, mvow);
}
