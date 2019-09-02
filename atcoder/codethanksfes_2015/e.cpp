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
    vector<vector<int>> E;

    cin >> N;
    E.resize(N+1);

    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        E[a].pb(b);
        E[b].pb(a);
    }

    if(E[1].size() == 1){
        cout << "A" << endl;
    } else {
        cout << ((N-1)%2 ? "A" : "B") << endl;
    }
}
