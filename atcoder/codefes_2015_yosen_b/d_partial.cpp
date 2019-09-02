#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    set<int> wm;

    for(int i=1;i<=100000;i++) wm.insert(i);
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int S,C;
        cin >> S >> C;
        assert(S+C <= 100000);

        int cnt = 0;

        while(true)
        {
            int p = *(wm.lower_bound(S));
            wm.erase(p);
            cnt++;
            S=p;

            if(cnt == C) break;
        }

        cout << S << endl;
    }
}
