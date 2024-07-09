#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    deque<int> deq;
    int q;
    cin >> q;
    rep(i, q)
    {
        int t, x;
        cin >> t >> x;
        if(t == 1)
        {
            deq.push_front(x);
        }
        if(t == 2)
        {
            deq.push_back(x);
        }
        if(t == 3)
        {
            cout << deq[x - 1] << endl;
        }
    }
    return 0;
}