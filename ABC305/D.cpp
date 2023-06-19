#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

ll a[200100];
int r;
int l;
 
int main()
{
    int n, q;
    int startnum;
    int time;
    cin >> n;
    rep(i, n) cin >> a[i];
    cin >> q;
    rep(k, q){
        cin >> l >> r;
        startnum = lower_bound(a, a+n, l) - a;
        time = r - l;
        if(startnum %2 == 1) 
        {
            if(a[startnum] > r)
            {
                time -= (r - l);
            }
            else{
            time -= (a[startnum] - l);
            }
        }
        int i = (startnum + 1);
        while(true)
        {
            if(a[i] >= r) break;
            if(i %2 == 1)
            {
                time -= (a[i] - a[i- 1]);
            }
            i++;
        }
        if(i %2 == 1)
        {
            time -= (r - a[i-1]);
        }
       cout << time << endl;
    }
    return 0;
}