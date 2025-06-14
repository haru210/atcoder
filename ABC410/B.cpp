#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
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
    int n, q;
    cin >> n >> q;
    int box[n] = {};
    rep(i, q)
    {
        int x;
        cin >> x;
        if(x > 0)
        {
            x--;
            box[x]++;
            cout << x + 1 << ' ';
        }
        else
        {
            int minball = inf;
            int minbox = -1;
            rep(i, n)
            {
                if(box[i] < minball)
                {
                    minball = box[i];
                    minbox = i;
                }
            }
            box[minbox]++;
            cout << minbox + 1 << ' ';
        }
    }
    return 0;
}