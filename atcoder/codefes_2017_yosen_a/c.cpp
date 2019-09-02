/* vim:set foldmethod=marker: */
#include <bits/stdc++.h>
using namespace std;

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
//
char Mat[101][101];
int cnt['z'+1];

void solve(){
    int H, W;

    cin >> H >> W;

    rep (i, H) {
        cin >> Mat[i];
    }

    rep(i, H) rep (j, W) {
        cnt[Mat[i][j]]++;
    }

    int isOdd = 0;
    int isnot4baisu = 0;
    REP(i, 'a', 'z' + 1) {
        if (cnt[i] % 2) {
            isOdd ++;
        } else if (cnt[i] % 4) {
            isnot4baisu ++;
        }
    }

    if (isnot4baisu > 0 && (H % 2 == 0 && W % 2 == 0)){
        cout << "No" << endl;
        return;
    }

    if (isOdd > 1) {
        cout << "No" << endl;
        return;
    }

    if (isOdd == 1 && (H % 2 == 0 || W % 2 == 0)) {
        cout << "No" << endl;
        return;
    }

    if (isOdd == 0 && H % 2 == 1 && W % 2 == 1) {
        cout << "No" << endl;
        return;
    }

    int mincnt = min(H/2, W/2);
    int is4bai = 0;
    REP(i, 'a', 'z' + 1) {
        is4bai += cnt[i] / 4;
    }

    int Min2by = H/2 > W/2 ? W%2 : H%2;

    if (is4bai < mincnt * 3 - Min2by) {
        cout << "No" <<endl;
        return;
    }

    cout << "Yes" <<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(12);
    solve();
}
