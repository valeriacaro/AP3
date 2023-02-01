#include <iostream>
#include <vector>
using namespace std;

const int UNDEF = -1;
int M, N;
vector<int> A;
vector<int> B;
vector<vector<int>> common_subsequence;

int max_length(int M, int N){
  if (common_subsequence[M][N] != UNDEF) return common_subsequence[M][N];
  if (M == 0 or N==0) return 0;
  if (A[M-1] == B[N-1]) return common_subsequence[M][N] = 1 + max_length(M-1, N-1);
  else return common_subsequence[M][N] = max(max_length(M-1, N), max_length(M, N-1));
}
int main(){
  while (cin >> M >> N){
    A = vector<int> (M);
    for (int& num : A) cin >> num;
    B = vector<int> (N);
    for (int& num : B) cin >> num;
    common_subsequence = vector<vector<int>> (M+1, vector<int> (N+1, UNDEF));
    cout << max_length(M, N) << endl;
  }
}
