// Giá trị nhỏ nhất trong khoảng
#include <bits/stdc++.h>
using namespace std;

int arr[10000000];
int tab[30][1000000];

void preCompute(int n, int k) {
    for(int j = 1; j <= n; ++j)
        tab[0][j] = arr[j];

    for(int i = 1; i <= k; ++i)
        for(int j = 1;  j + (1 << i) - 1 <= n; ++j)
            tab[i][j] = min(tab[i - 1][j], tab[i - 1][j + (1 << (i - 1))]);
}

int query(int l, int r) {
    int k = (int)log2(r - l + 1);
    return min(tab[k][l], tab[k][r - (1 << k) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];

    int k = (int)log2(n);
    preCompute(n, k);

    int m;
    cin >> m;

    int Q = 0;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Q += query(a + 1, b + 1);
    }

    cout << Q << endl;

    return 0;
}
// Dxy