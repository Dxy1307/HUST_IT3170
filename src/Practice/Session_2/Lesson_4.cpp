// Capacitaed Vehicle Routing
#include <iostream>
using namespace std;
const int MAX = 50;
int n, K, Q;
int d[MAX];
bool visited[MAX];
int x[MAX];
int y[MAX];
int load[MAX];
int c[MAX][MAX];
int cmin = 50;
int segment;
int nbRoutes;
int f;
int fr;

void input() {
    f = 0;
    fr = INT32_MAX;
    segment = 0;
    d[0] = 0;
    y[0] = 0;
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; ++i)
        cin >> d[i];
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            cin >> c[i][j];
            if(c[i][j] != 0 && cmin > c[i][j])
                cmin = c[i][j];
        }
    }
    for(int i = 0; i <= n; ++i) {
        load[i] = 0;
        visited[i] = false;
    }
}

bool checkX(int v, int k) {
    if(v > 0 && visited[v])
        return false;
    if(load[k] + d[v] > Q)
        return false;
    return true;
}

bool checkY(int v, int k) {
    if(v == 0) return true;
    if(load[k] + d[v] > Q) return false;
    if(visited[v]) return false;
    return true;
}

void TRY_X(int s, int k) {
    if(s == 0) {
        if (k < K)
            TRY_X(y[k+1], k+1);
        return;
    }
    for(int v = 0; v <= n; ++v) {
        if(checkX(v, k)) {
            x[s] = v;
            visited[v] = true;
            f += c[s][v];
            load[k] += d[v];
            segment += 1;
            if(v > 0) {
                if(f + (n + nbRoutes - segment)*cmin < fr) 
                    TRY_X(v, k);
            } else {
                if(k == K) {
                    if(segment == n + nbRoutes) {
                        if(f + c[v][0] < fr)
                            fr = f + c[v][0];
                    }
                }
                else {
                    if(f + (n + nbRoutes -segment)*cmin < fr)
                        TRY_X(y[k+1], k+1);
                }
            }
            visited[v] = false;
            f = f - c[s][v];
            load[k] -= d[v];
            segment--;
        }
    }
}

void TRY_Y(int k) {
    int s = 0;
    if(y[k-1] > 0) s = y[k-1] + 1;
    for(int v = s; v <= n; v++) {
        if(checkY(v, k)) {
            y[k] = v;
            if(v > 0) segment++;
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];
            if(k < K) 
                TRY_Y(k+1);
            else {
                nbRoutes = segment;
                TRY_X(y[1], 1);
            }                
            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
            if(v > 0) segment--;
        }
    }
}

void solve() {
    TRY_Y(1);
    cout << fr << endl;
}

int main() {
    input();
    solve();

    return 0;
}
// Dxy