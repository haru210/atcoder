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
    int q;
    cin >> q;
    vector<ll> que; //n番目の蛇の頭の位置
    vector<ll> snake;
    ll last = 0; //次の頭が入る位置
    ll pos = 0; //何人抜けたか
    ll diff = 0; //抜けた蛇の長さの総和
    rep(i, q)
    {
        int query;
        cin >> query;
        if(query == 1)
        {
            ll l;
            cin >> l;
            snake.push_back(l);
            if(que.empty()) 
            {
                que.push_back(0);
                last = l;
            }
            else
            {
                que.push_back(last);
                last += l;
            }
        }
        if(query == 2)
        {
            diff += snake[pos];
            pos++;
        }
        if(query == 3)
        {
            int k;
            cin >> k;
            k--;
            cout << que[k + pos] - diff << endl;
        }
        
    }
    return 0;
}