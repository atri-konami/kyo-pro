#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;

    cin >> N >> M;

    vector<int> v;

    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(),v.end());

    int mx = -1;
    int idx=-1;
    int d;
    for(int i=0;i<=M;i++){
        if(mx < (d=distance(lower_bound(v.begin(),v.end(),i),upper_bound(v.begin(),v.end(),i)))){
            mx = d;
            idx = i;
        }
    }

    if ( mx*2 <= N){
        cout << "?" << endl;
    }else{
        cout << idx << endl;
    }
}


