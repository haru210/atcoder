#include <bits/stdc++.h>
using namespace std;

int h,w;
int ans = 10000000;
int row[100][100];
int col[100][100];
bool visited[100][100] = {};
pair<int,int> d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, int depth)
{
    if(x == w -1 && y == h - 1)
    {
        ans = min(ans, depth);
    }
    else{
        visited[y][x] = true;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + d[i].first;
            int ny = y + d[i].second;
            if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            int door_x;
            int door_y;
            //横移動
            if(i < 1)
            {
                if(i == 0)
                {
                    door_x = x;
                    door_y = y;
                } 
                else
                {
                    door_x = x - 1;
                    door_y = y;
                }
                if(row[door_y][door_x] % 3 == (depth + 1) % 3)
                {
                    if(!visited[ny][nx]) dfs(nx, ny, depth+1);
                }
            }
            //縦移動
            else
            {
                if(i == 2)
                {
                    door_x = y;
                    door_y = x;
                }
                if(i == 3)
                {
                    door_x = y - 1;
                    door_y = x;
                }
                if(col[door_y][door_x] % 3 == (depth+1) % 3)
                {
                    if(!visited[ny][nx]) dfs(nx, ny, depth+1);
                }
            }
        }
    }
    visited[y][x] = false;
}

int main()
{
    cin >> h >> w;
    for(int i = 0; i < h; i++) for(int j = 0; j < w - 1; j++) cin >> row[i][j];
    for(int i = 0; i < w; i++) for(int j = 0; j < h - 1; j++) cin >> col[i][j];
    dfs(0,0,0);
    if(ans == 10000000) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}