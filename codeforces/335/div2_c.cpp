#include <bits/stdc++.h>
using namespace std;

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

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    os << "[";
    for(int i=0; i<v.size(); i++) os << v[i] << ",";
    os << "]";
    return os;
}

template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p) {
        os << "(" << p.first << "," << p.second << ")"; return os;
}

int vfind(vector<int>& v,int n)
{
    rep(i,v.size())
    {
        if (v[i] == n ) return i;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> p(N);
    vector<int> idx(N+1);

    rep(i,N){
        cin >> p[i];

        idx[p[i]] = i;
    }


    vector<int> v;

    int t=0;

    int mx=INT_MIN;

    rep(i,N){
        v.pb(p[t]);

        if ( p[t] != N && idx[p[t]+1] > t ){
            t = idx[p[t]+1];
        } else {
            mx = max((int)v.size(),mx);

            if ( p[t] == N && v.front() == 1 ) break;
            t = (p[t] == N ? idx[1] : idx[p[t]+1]);
            v.clear();
        }
    }

    cout << N-mx << endl;
}
