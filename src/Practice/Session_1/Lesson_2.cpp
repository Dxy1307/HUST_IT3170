// Tìm đường ngắn nhất thoát khỏi mê cung
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, distance;
};

bool isValid(int x, int y, int n, int m, vector<vector<int>> &maze, vector<vector<bool>> &visited) {
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y]);    
}

int shortestPath(vector<vector<int>> &maze, int r, int c, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Cell> q;

    q.push({r, c, 0});
    visited[r][c] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty()) {
        Cell temp = q.front();
        q.pop();

        if(temp.x == 0 || temp.x == n - 1 || temp.y == 0 || temp.y == m - 1)
            return temp.distance;

        for(int i = 0; i < 4; ++i) {
            int newX = temp.x + dx[i];
            int newY = temp.y + dy[i];

            if(isValid(newX, newY, n, m, maze, visited)) {
                q.push({newX, newY, temp.distance + 1});
                visited[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<vector<int>> maze(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> maze[i][j];

    int res = shortestPath(maze, r - 1, c - 1, n, m);
    cout << res << endl;

    return 0;
}
// Dxy