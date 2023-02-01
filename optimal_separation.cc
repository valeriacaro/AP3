#include <iostream>
#include <vector>

using namespace std;

vector<int> x;
int optimal_sep;
int n;

// Returns the optimal value of the separation of the elements of x,
// which minimizes the absolute value of the difference between the sums of the elements of the 2 sets
void optimal_separation(int pos, int current_optimal_sep, int sum_elems_left)
{
    if (pos == n) {
        optimal_sep = min(optimal_sep, abs(current_optimal_sep));
        return;
    }
    if (abs(current_optimal_sep) > sum_elems_left) {
        // in this case, in order to minimize abs(current_optimal_sep), we must add or substract current_optimal_sep by sum_elems_left
        // otherwise, we won't minimize it
        if (abs(current_optimal_sep - sum_elems_left) > optimal_sep and abs(current_optimal_sep + sum_elems_left) > optimal_sep)
            return;
    }
    // we either add the element or substract it
    optimal_separation(pos + 1, current_optimal_sep - x[pos], sum_elems_left - x[pos]);
    optimal_separation(pos + 1, current_optimal_sep + x[pos], sum_elems_left - x[pos]);
}

int main()
{
    while (cin >> n) {
        int total = 0;
        x = vector<int>(n);
        for (int& x_i : x) {
            cin >> x_i;
            total += x_i;
        }
        optimal_sep = total;
        optimal_separation(0, 0, total);
        cout << optimal_sep << endl;
    }
}
