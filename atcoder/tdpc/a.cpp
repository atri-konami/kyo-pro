#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<char>> v(N+1,vector<char>(N*100+1,0));


    for(auto &x:v) x[0] = 1;

    for(int i=1;i<=N;i++)
    {
        int p;
        cin >> p;

        for(int j=1;j<=N*100;j++)
        {
            v[i][j] |= v[i-1][j];

            if (j >= p)
            {
                v[i][j] |= v[i-1][j-p];
            }
        }
    }

    int res=0;
    for(auto x:v[N])
    {
        if (x)
        {
            res++;
        }
    }

    cout << res << endl;
}
