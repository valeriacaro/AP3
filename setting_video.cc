#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> parell;
typedef priority_queue<parell> cua;

int n;
cua episodis;

int count_max_eps() {
    int eps_chosen = 0;
    while (not episodis.empty()) {
        // Choose episode to record
        parell chosen = episodis.top();
        episodis.pop();
        ++eps_chosen;

        // Discard the ones that begin before it ends
        while (not episodis.empty()
                and episodis.top().second <= -chosen.first) {
            episodis.pop();
        }
    }
    return eps_chosen;
}

int main() {
    while (cin >> n) {
        episodis = cua();
        for (int i = 0; i < n; ++i) {
            int inici, final;
            cin >> inici >> final;
            episodis.push({-final, inici});
        }

        int episodis = count_max_eps();
        cout << episodis << endl;
    }
}
