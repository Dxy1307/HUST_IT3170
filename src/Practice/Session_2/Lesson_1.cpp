#include <iostream>
#include <vector>
using namespace std;

int countSolutions(vector<int>& a, int M) {
    vector<int> dp(M + 1, 0);
    int sum = 0;
    for(int i = 0; i < a.size(); ++i)
        sum += a[i];
    dp[sum] = 1; // với giá trị nhỏ nhất của mỗi biến là 1 thì có 1 cách

    // Tính toán số lượng nghiệm cho mỗi giá trị từ 1 đến M
    for (int i = 0; i < a.size(); ++i) {
        for (int j = a[i]; j <= M; ++j) {
            dp[j] += dp[j - a[i]];
        }
    }

    return dp[M];
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int& ai : a) {
        cin >> ai;
    }

    cout << countSolutions(a, M) << endl;
    return 0;
}
// Dxy