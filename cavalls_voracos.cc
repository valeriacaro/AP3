#include <iostream>
#include <vector>

using namespace std;
using Grid_int = vector<vector<int>>;
using Grid_bool = vector<vector<bool>>;

// # monedes de la millor solució que hem provat fins ara
int best_so_far;

vector<pair<int, int>> candidates = { { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };

// creates a new grid with n rows and m columns.
// Each position has a certain number of coins, given by G[i][j] (row i, column j).
Grid_int create_grid(int n, int m)
{
    Grid_int G(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> G[i][j];
    }
    return G;
}

bool legal_pos(int i, int j, const Grid_bool& is_knight)
{
    return (0 <= i and i < is_knight.size() and 0 <= j and j < is_knight[0].size());
}
// tells if the position (i, j) is threatened by the knights currently present in the board
bool threatened(int i, int j, const Grid_bool& is_knight)
{
    int n = is_knight.size();
    int m = is_knight[0].size();

    int move_i, move_j;

    for (auto move : candidates) {
        move_i = i + move.first;
        move_j = j + move.second;
        if (legal_pos(move_i, move_j, is_knight) and is_knight[move_i][move_j])
            return true;
    }

    return false;
}

// Given a partially filled grid with knights and the number of current coins, returns the maximum number of coins we can get
// by extending the partial solution to a possible solution by starting in the position (current_i, current_j).
// The knights we put on the board cannot threaten each other.
// The total number of coins we get is the sum of all the coins available in the positions filled by knights. (the positions they threaten don't count)
void max_coins_knights_rec(int current_i, int current_j, int current_coins, Grid_bool& is_knight, Grid_int& coins)
{
    int max_coins = current_coins;

    if (current_j == is_knight[0].size()) {
        current_j = 0;
        current_i++;
    }
    if (current_i == is_knight.size()) {
        best_so_far = max(best_so_far, current_coins);
        return;
    }

    // if the position (i, j) is not occupied by a knight or atainable by one
    if (not threatened(current_i, current_j, is_knight)) {
        is_knight[current_i][current_j] = true;
        max_coins_knights_rec(current_i, current_j + 1, current_coins + coins[current_i][current_j], is_knight, coins);
        is_knight[current_i][current_j] = false;
    }
    max_coins_knights_rec(current_i, current_j + 1, current_coins, is_knight, coins);
}

// returns the maximum number of coins atainable by knights so that they don't threaten each other.
void max_coins_knights(Grid_int& coins)
{
    Grid_bool is_knight(coins.size(), vector<bool>(coins[0].size(), false));
    max_coins_knights_rec(0, 0, 0, is_knight, coins);
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        best_so_far = 0;
        Grid_int coins = create_grid(n, m);
        max_coins_knights(coins);
        cout << best_so_far << endl;
    }
}
