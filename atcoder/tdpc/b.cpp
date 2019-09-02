#include <bits/stdc++.h>
using namespace std;

int A,B;
vector<int> a,b;
int memo[1001][1001];

int solve(int x,int y)
{
    if (memo[x][y] > 0) return memo[x][y];

    if (x < 0 || y < 0) return INT_MAX;

    if (!x && !y) return 0;

    if (!x && y==1) return b[B-y];

    if (x==1 && !y) return a[A-x];

    if (!x && y>1) return memo[x][y] = b[B-y] + solve(x,y-2);

    if (x>1 && !y) return memo[x][y] = a[A-x] + solve(x-2,y);

    return memo[x][y] = max(a[A-x]+min(solve(x-2,y),solve(x-1,y-1)), b[B-y]+min(solve(x-1,y-1),solve(x,y-2)));
}

int main()
{
    memset(memo,-1,sizeof(memo));
    cin >> A >> B;
    a.resize(A);b.resize(B);

    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;

    cout << solve(A,B) << endl;
}
