#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void findMaxSubsequence(map<char, int>& v, const string& A, const string& B){
    auto const n = A.size();
    auto const m = B.size();
    vector<vector<int>> M(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                M[i][j] = M[i - 1][j - 1] + v[A[i - 1]];
            }
            else {
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);
            }
        }
    }
    
    string s;
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            s = A[i - 1] + s;
            i--;
            j--;
        }
        else if (M[i - 1][j] >= M[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    cout << M[n][m] << endl << s << endl;
}

int main() {
    int alphaLen;
    char x;
    int v;
    map<char, int> m;
    cin >> alphaLen;
    for (int i = 0; i < alphaLen; i++) {
        cin >> x;
        cin >> v;
        m[x] = v;
    }
    string A, B;
    cin >> A;
    cin >> B;
    findMaxSubsequence(m, A, B);
}
