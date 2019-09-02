#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> par,rnk;

    UnionFind(int n)
    {
        par.resize(n);
        rnk.resize(n);
        for(int i=0; i<n; i++){
            par[i]=i;
            rnk[i]=0;
        }
    }

    void unite(int x,int y)
    {
        x = find(x);y = find(y);
        if(x == y) return;

        if( rnk[x] < rnk[y] )
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if(rnk[x] == rnk[y])
            {
                rnk[x]++;
            }
        }
    }



    bool same(int x,int y)
    {
        return find(x) == find(y);
    }

private:
    int find(int x)
    {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
};

int main(){
    int N,Q;
    cin >> N >> Q;

    UnionFind u(N);

    for(int i=0; i<Q; i++){
        int p,a,b;
        cin >> p >> a >> b;

        if(p){
            cout << (u.same(a,b) ? "Yes" : "No") << endl;
        }else{
            u.unite(a,b);
        }
    }
}
