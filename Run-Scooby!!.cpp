#include <bits/stdc++.h>
using namespace std;
//using dfs 
const int MAXN = 50;
char building[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n && building[x][y] != '*';
}

bool bfs(int sx, int sy, int ex, int ey, int n) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == ex && y == ey) {
            return true;
        }
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny, n) && !visited[nx][ny] && building[nx][ny] != 'G') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    int sx, sy, hx, hy, ex, ey, gx, gy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> building[i][j];
            if (building[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (building[i][j] == 'H') {
                hx = i;
                hy = j;
            } else if (building[i][j] == 'E') {
                ex = i;
                ey = j;
            } else if (building[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    
    bool scoobySafe = bfs(sx, sy, ex, ey, n);
    bool shaggySafe = bfs(hx, hy, ex, ey, n);
    
    if (scoobySafe || shaggySafe) {
        cout << "Scooby-Dooby-Doo!" << endl;
    } else {
        cout << "Ruh-roh–RAGGY!!!" << endl;
    }
    
    return 0;
}
