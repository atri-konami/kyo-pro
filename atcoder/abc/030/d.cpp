#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    int here;
    int to;
};

int main(){
    ll N,a,k;
    vector<int> v;
    cin >> N >> a >> k;
    vector<Node> dict(N+1);

    for(int i=1;i<=N;i++){
        cin >> dict[i].to;
        dict[i].here=-1;
    }

    int b;
    while(true){
        b = dict[a].to;
        if(dict[b].here != -1){
            break;
        }else{
            v.push_back(b);
            dict[b].here=v.size()-1;
            a=b;
        }
    }

    k -= dict[b].here;
    ll mod = v.size()-dict[b].here;

    cout << v[k%mod+dict[b].here-1] << endl;
}
