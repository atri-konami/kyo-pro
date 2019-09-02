/* vim:set foldmethod=marker: */
#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int N;
    vector<int> dat,sum;

    SegTree(int n)
    {
        N = 1;
        while(N<n) N<<=1;
        dat.assign(2*N-1,0);
        sum.assign(2*N-1,0);
    }

    void add(int a,int b,int x) { add(a,b,x,0,0,N); }

    int add(int a,int b,int x,int k,int l,int r)
    {
        if ( r <= a || b <= l ) return dat[k];
        if ( a <= l && r <= b )
        {
            sum[k] += x;
            return dat[k] += x;
        }

        return dat[k] = min(add(a,b,x,k*2+1,l,(l+r)/2),add(a,b,x,k*2+2,(l+r)/2,r)) + sum[k];
    }

    int minimum(int a,int b) { return minimum(a,b,0,0,N); }

    int minimum(int a,int b,int k,int l,int r) 
    {
        if ( r <= a || b <= l ) return INT_MAX;
        if ( a <= l && r <= b ) return dat[k];

        return min(minimum(a,b,k*2+1,l,(l+r)/2), minimum(a,b,k*2+2,(l+r)/2,r)) + sum[k];
    }
};

//{{{
#define all(x) (x).begin(),(x).end()
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define RREP(i,a,b) for(int i=(int)(a); i>=b; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,n,0)
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

#define dump(x) (cerr << #x << "=" << x << endl)
template<class T> ostream& osContainer(ostream& os,T c) { os<<'[';for(decltype(c.begin()) it=c.begin();it!=c.end();it++)os<<*it<<',';os<<']';return os; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { return osContainer(os,v); }
template<class T> ostream& operator<<(ostream& os,const set<T>& s) { return osContainer(os,s); }
template<class T> ostream& operator<<(ostream& os,const multiset<T>& s) { return osContainer(os,s); }
template<class T,class S> ostream& operator<<(ostream& os,const map<T,S>& m) { return osContainer(os,m); }
template<class T,class S> ostream& operator<<(ostream& os,const multimap<T,S>& m) { return osContainer(os,m); }
template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p){ os << '(' << p.first << ',' << p.second << ')'; return os; }

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
//}}}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(12);

    int n,q;
    cin >> n >> q;

    SegTree seg(n);

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        seg.add(l-1, r, 1);
    }

    rep(i, n) {
        cout << seg.minimum(i, i+1) % 2;
    }

    cout << endl;
}
