#include <iostream>
#include <vector>
using namespace std;

void genera(vector<int>& v, int i, int uns_que_queden, int zeros_que_queden, int sum, int& sum_max, const vector<int>& iaies)
{
    int n = v.size();
    if (i == n) {
        if (sum > sum_max) {
            sum_max = sum;
        }
    } else {
        if (uns_que_queden > 0) {
            v[i] = 1;
            int sum2 = sum;
            sum2 = sum2 + iaies[i];
            if (i > 0 and v[i - 1] == 0) {
                sum2 = sum2 + iaies[i - 1] / 2;
            }
            genera(v, i + 1, uns_que_queden - 1, zeros_que_queden, sum2, sum_max, iaies);
        }
        if (zeros_que_queden > 0) {
            v[i] = 0;
            int sum2 = sum;
            if (i > 0 and v[i - 1] == 1) {
                sum2 = sum2 + iaies[i] / 2;
            }
            genera(v, i + 1, uns_que_queden, zeros_que_queden - 1, sum2, sum_max, iaies);
        }
    }
}

int main()
{
    int g, n;
    while (cin >> g >> n) {

        // lectura del num de iaies a les escoles
        vector<int> iaies(n);
        for (int i = 0; i < n; i++) {
            cin >> iaies[i];
        }
        vector<int> v(n, 0);
        int sum_max = 0;
        genera(v, 0, g, n - g, 0, sum_max, iaies);
        cout << sum_max << endl;
    }
}
