#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    if(N < M){
        cout << "NO" << endl;
        return 0;
    }

    vector<int> A(N),B(M);

    for(auto &a:A) cin >> a;
    for(auto &b:B) cin >> b;

    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());

    for(int i=0; i<M;i++){
        if(A[i] < B[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" <<endl;
}
