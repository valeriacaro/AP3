#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

using M = vector < vector <int> >;

int omplirLCS (M &LCS, string a, string b) {
    int max = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                LCS[i][j] = 1;
                if (i - 1 >= 0 and j - 1 >= 0) {
                    LCS[i][j] += LCS[i-1][j-1];
                }
            } else {
                LCS[i][j] = 0;
            }
            if (max < LCS[i][j]) max = LCS[i][j];
        }
    }
    return max;
}

string paraulesCandidates (const M &LCS, int max, string a) {

    string min_word;
    bool first = true;

    for (int i = 0; i < LCS.size(); i++) {
        for (int j = 0; j < LCS[i].size(); j++) {
            if (LCS[i][j] == max) {
                string word = "";
                for (int c = i - max + 1; c <= i; c++) {
                    word.push_back(a[c]);
                }
                if (first or word < min_word) {
                    min_word = word;
                }
                first = false;
            }
        }
    }
    return min_word;
}

int main () {
    string a;
    string b;

    while (cin >> a >> b) {
        M LCS (a.size(), vector <int> (b.size()));
        int max = omplirLCS(LCS, a, b);

        /* for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                cout << LCS[i][j] << " ";
            }
            cout << endl;
        } */

        string paraula = paraulesCandidates(LCS, max, a);

        cout << paraula << endl;
    }
}
