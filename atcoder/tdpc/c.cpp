#include <bits/stdc++.h>
using namespace std;

inline double elo(int p,int q)
{
    return 1.0/(1+pow(10,(q-p)/400.0));
}

int main()
{
    double dp[1<<10][11];


    int K;
    cin >> K;

    for(int i=0;i<1<<K;i++){
        dp[i][0] = 1;
    }

    vector<int> R(1<<K);

    for(auto &x:R) cin >> x;

    for(int i=1;i<=K;i++)
    {
        for(int k=0;k<1<<K;k++)
        {
            double s = 0;

            for(int j=k+1;j<1<<i;j++)
            {
                s += dp[j][i-1] * elo(R[k],R[j]);
            }

            for(int j=k-1;j>=0;j--)
            {
                s += dp[j][i-1] * elo(R[k],R[j]);
            }

            dp[k][i] = dp[k][i-1] * s;
        }
    }

    for(int i=0;i<1<<K;i++){
        cout << fixed << setprecision(8) << dp[i][K] << endl;
    }
}
