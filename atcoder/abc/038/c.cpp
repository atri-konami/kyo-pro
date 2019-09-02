#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

inline bool trulyBig(P lp, P rp) {
    return lp.first < rp.first && lp.second < rp.second;
}

int main() {
    vector<P> v;
    vector<P> lhs, rhs;
    int n;

    cin >> n;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    long long res = 1;
    lhs.push_back(v[0]);

    for(int i=1; i<v.size(); i++) {
        int t1 = lhs.back(), t2 = v[i];
        if (trulyBig(t1, t2)) {
            lhs.push_back(t2);
            res += lhs.size();
        } else {
            lhs.clear();
            lhs.push_back(t2);
            res++;
        }
    }

    cout << res << endl;
}
