#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000000;

int solve(int N)
{
    if (N == 0) return 0;
    if (N/10 == 0) return 1;

    int i,div,mod;
    for(i=MAX_N; i>0; i/=10)
    {
        div = N/i,mod = N%i;
        if(div>0) break;

    }

    int s = solve(mod),t = solve(i-1);
    int res = t + s;

    if (div > 1)
    {
        res += i;
    }
    else
    {
        res += mod+1;
    }


    for(int i=div-1; i>0;i--) res += t;

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    cout << solve(N) << endl;
}





