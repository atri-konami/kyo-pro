#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define RREP(i,a,b) for(int i=(int)(a); i>=b; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,n,0)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

#define dump(x) (cerr << #x << "=" << x << endl)

template<class T>
ostream& operator<<(ostream& os,const vector<T> v) {
    os << "[";
    for(int i=0; i<v.size(); i++){
        os << v[i] << ",";
    } 
    os << "]";
    return os;
}

template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2> p) {
        os << "(" << p.first << "," << p.second << ")"; return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    vector<vector<int>> G;
    int allp=0;
    vi P,A;

    cin >> N;
    G.resize(N+1);A.assign(N+1,0);P.resize(N+1,0);

    rep(i,N){
        int x;
        cin >> x;
        P[i+1] = x;
        G[i+1].pb(i+1);
        A[i+1] += x;
        allp += x;
    }

    int M;
    cin >> M;

    rep(i,M){
        int a,b,c;
        cin >> a >>b >> c;

        if (a) {
            if ( find(G[b].begin(),G[b].end(),c) != G[b].end()){
                cout << P[c] << " " << P[c] << endl;
            }else{
                int mx,mn;
                mx = min(100,allp-A[b]);
                mn = max(0,allp-A[b] - (N-(int)G[b].size()-1)*100);
                cout << mn << " " << mx << endl;
            }
        }else{
            G[b].pb(c);
            A[b] += P[c];
        }
    }
}
