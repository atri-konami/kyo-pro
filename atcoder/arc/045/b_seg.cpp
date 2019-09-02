#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> seg;

void init(int m)
{
    n=1;

    while(n<m) n<<=1;

    seg.resize(n*2-1);
    for(int i=0; i<n*2-1; i++) seg[i]=INT_MAX;
}

void update(int k,int x)
{
    k += n-1;
    seg[k] = x;

    while(k>0)
    {
        k = (k-1)/2;
        seg[k] = min(seg[2*k+1],seg[2*k+2]);
    }
}


int query(int a,int b,int k,int l,int r)
{
    if (a >= r || b <= l) return INT_MAX;
    if (a <= l && r <= b) return seg[k];

    int vl = query(a,b,k*2+1,l,(l+r)/2),
        vr = query(a,b,k*2+2,(l+r)/2,r);

    return min(vl,vr);
}

void solve()
{
    int N,M;

    cin>>N>>M;

    init(N);

    vector<pair<int,int>> pv;
    vector<int> S(N+1,0);

    for(int i=0; i<M; i++)
    {
        int s,t;
        cin>>s>>t;

        S[s-1]++;S[t]--;
        pv.emplace_back(s-1,t);
    }

    update(0,S[0]);

    for(int i=1; i<N; i++)
    {
        S[i] += S[i-1];
        update(i,S[i]);
    }

    int res=0;
    vector<int> resv;

    for(int i=0; i<M; i++)
    {
        pair<int,int> p = pv[i];
        int q = query(p.first,p.second,0,0,n);

        if (q > 1)
        {
            res++;
            resv.push_back(i+1);
        }
    }

    cout << res << endl;

    for(auto x:resv) cout << x << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
