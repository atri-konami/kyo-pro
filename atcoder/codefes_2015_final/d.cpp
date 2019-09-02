#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    int d[100010];
    vector<pair<int,int>> range;

    memset(d,0,sizeof(d));

    cin >> N;

    for (int i=0; i<N; i++)
    {
        int s,t;
        cin >> s >> t;

        d[s]++;d[t]--;

        range.emplace_back(s,t);
    }

    for(int i=1;i<100010; i++)
    {
        d[i] = d[i] + d[i-1];
    }

    int mx = *max_element(d,d+100010);
    vector<int> vidx;

    for(int i=1;i<100010;i++)
    {
        if ( d[i] == mx ) {
            vidx.push_back(i);
        }
    }

    int res = mx;

    if ( vidx.size() > 1 ){
        for(int i=0;i<range.size();i++){
            if( range[i].first <= vidx[0] && vidx[vidx.size()-1] < range[i].second ) {
                res--;
                break;
            }
        }
    }else{
        res--;
    }

    cout << res << endl;
}
