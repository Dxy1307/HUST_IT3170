// CBUS
#include<bits/stdc++.h>
using namespace std;
#define MAX 40

int n, K;
int x[MAX];
bool visited[MAX];
int d[MAX][MAX];
int cmin = 10000;
int load = 0;
int f = 0;
int f_min = 10000;

void input() {
    cin >> n >> K;
    for(int i = 0; i <= 2*n; i++) {
        for(int j = 0; j <= 2*n; j++) {
            cin >> d[i][j];
            if(cmin > d[i][j] && d[i][j] != 0) {
                cmin = d[i][j];
            }
        }
    }
    x[0] = 0;
}

void updateBest() {
    f += d[x[2*n]][0];
    f_min = min(f_min, f);
    f -= d[x[2*n]][0];
}

bool check(int v, int k) {
    if (visited[v]) return false;
    if(v > n) {
        if(visited[v-n] == false) return false;
    } else {
        if(load + 1 > K) return false;
    }
    return true;
}

void TRY(int k) {
    for(int v = 1; v <= 2*n; v++) {
        if(check(v, k)) {
            x[k] = v;
            f += d[x[k-1]][v];
            visited[v] = true;
            if(v <= n) load++;
            else load--;
            if(k == 2*n)
                updateBest();
            else {
                if(f + cmin*(2*n-k) < f_min) {
                    TRY(k+1);
                }
            }
            if(v <= n) load--;
            else load++;
            visited[v] = false;
            f -= d[x[k-1]][v];
        }
    }
}

int main() {
    input();

    TRY(1);
    cout << f_min << endl;

    return 0;
}
// Dxy