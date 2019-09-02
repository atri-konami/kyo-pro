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

bool sheet[3][3];
int glores;

int bingocheck() {
    int bingo = 0;
    for(int y = 0; y < 3; y++) {
        if (sheet[y][0] && sheet[y][1] && sheet[y][2]){
            bingo++;
        }
    }

    for(int x = 0; x < 3; x++) {
        if (sheet[0][x] && sheet[1][x] && sheet[2][x]) {
            bingo++;
        }
    }

    return bingo;
}

void search() {
    int res = 0;
    rep(i, 3) rep(j, 3) {
        if (sheet[i][j]) {
            sheet[i][j] = false;
            int bingo = bingocheck();
            if (bingo == 0) {
                res++;
            }

            sheet[i][j] = true;
        }
    }
    glores += res > 0 ? 1 : 0;
}

void sim(int n) {
    if (n == 0) {
        if (bingocheck() > 0) search();
        return ;
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!sheet[i][j]) {
                    sheet[i][j] = true;
                    sim(n-1);
                    sheet[i][j] = false;
                }
            }
        }
    }
}

int powerInt(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * powerInt(n-1);
    }
}

void solve(){
    int n;
    cin >> n;

    rep(i, 3) rep (j, 3) sheet[i][j] = false;
    if ( n < 3 ) {
        cout << 0 << endl;
    } else {
        sim(n);
        cout << glores / powerInt(n) << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(12);
    solve();
}
