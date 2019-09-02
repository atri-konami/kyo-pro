#include <bits/stdc++.h>
using namespace std;

int H,W;
char F[501][501];
bool checked[501][501];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

inline bool in(int y,int x)
{
    return 0 <= y && y < H && 0 <= x && x < W;
}

bool dfs(int y,int x)
{
    if(F[y][x] == 'g') return true;

    checked[y][x] = true;

    for(int i=0; i<4; i++)
    {
        int ddy = y+dy[i],ddx = x+dx[i];
        if(in(ddy,ddx) && F[ddy][ddx] != '#' && !checked[ddy][ddx] && dfs(ddy,ddx)) return true;
    }

    return false;
}

int main()
{
    memset(checked,0,sizeof(checked));
    cin >> H >> W;

    int sx,sy;

    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            cin >> F[i][j];
            if(F[i][j] == 's')
            {
                sx = j;sy = i;
            }
        }

        cin.ignore();
    }

    cout << (dfs(sy,sx) ? "Yes" : "No") << endl;
}
