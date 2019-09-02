#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,X,Y;

    cin >> N >> M >> X >> Y;

    vector<int> a(N),b(M);

    for(auto &aa:a) cin >> aa;
    for(auto &bb:b) cin >> bb;

    int t=0,sum=0,ai=-1,bi=-1;

    while(true){
        int aio = ai,bio=bi;

        for(int i=ai+1; i<a.size();i++){
            if(t <= a[i]){
                ai = i;
                break;
            }
        }

        if(aio == ai) break;

        t += a[ai] - t + X;

        for(int i=bi+1; i<b.size();i++){
            if(t <= b[i]){
                bi = i;
                break;
            }
        }

        if(bio == bi) break;

        t += b[bi] - t + Y;

        sum++;
    }

    cout << sum << endl;
}
