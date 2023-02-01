#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> lights;
int best;

void opposite(char& a) { a = a == '.' ? '*' : '.'; }

void switchLight(int i, int j) {
    opposite(lights[i][j]);
    if(j > 0)
        opposite(lights[i][j-1]);
    if(j < m-1)
        opposite(lights[i][j+1]);
    if(i > 0) {
        opposite(lights[i-1][j]);
        if(j > 0)
            opposite(lights[i-1][j-1]);
        if(j < m-1)
            opposite(lights[i-1][j+1]);
    }
    if(i < n-1){
        opposite(lights[i+1][j]);
        if(j > 0)
            opposite(lights[i+1][j-1]);
        if(j < m-1)
            opposite(lights[i+1][j+1]);
    }
}

void exh(int i, int j, int changes, int tab) {
    if(i == n) {
        for(string& s: lights)
            for(char c: s)
                if(c != '.')
                    return;
        best = min(best, changes);
    } else if(i == 0 or j == 0) {
        exh(i+(j+1)/m, (j+1)%m, changes, tab+1);

        switchLight(i, j);
        exh(i+(j+1)/m, (j+1)%m, changes+1, tab+1);
        switchLight(i, j);
    } else {
        bool change = lights[i-1][j-1] != '.';
        if(change)
            switchLight(i, j);
        exh(i+(j+1)/m, (j+1)%m, changes + (change ? 1 : 0), tab+1);
        if(change)
            switchLight(i, j);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m) {
        lights = vector<string>(n);
        for(string& s: lights)
            cin >> s;
        best = 1e9;
        exh(0, 0, 0, 0);
        if(best == 1e9)
            cout << "no" << endl;
        else
            cout << best << endl;
    }
}
