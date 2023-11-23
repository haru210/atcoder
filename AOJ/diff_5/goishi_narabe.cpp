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
    int n;
    cin >> n;
    stack<pint> stone; //石の切り替わりを保存する　色、連続している数
    stone.push(make_pair(-1,0));
    int s_size = 1;
    rep2(i,n)
    {
        int c;
        cin >> c;
        if(i %2 == 1 || stone.top().first == c){
            if(i == 1)
            {
                stone.top().first = c;
            }
            if(c == stone.top().first)
            {
                stone.top().second++;
            }
            else
            {
                stone.push(make_pair(c, 1));
                s_size++;
            }
        }
        else
        {
            int tmp = 0;
            if(s_size != 1)
            {
                tmp = stone.top().second;
                stone.pop();
                s_size--;
                tmp++;
                stone.top().second += tmp;
            }
            else
            {
                stone.top().first = c;
                stone.top().second++;
            }
        }
    }
    int ans = 0;
    rep(i,s_size)
    {
        pint tmp = stone.top();
        stone.pop();
        if(tmp.first == 0) ans += tmp.second;
    }
    cout << ans << endl;
    return 0;
}