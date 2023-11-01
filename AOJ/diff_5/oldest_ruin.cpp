#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

//ool is_piller[5001][5001]  = {false};

int main()
{
    int n;
    ll ans = 0;
    cin >> n;
    pint piller[n];
    map<pint,int> is_piller;
    rep(i,n)
    {
        cin >> piller[i].first >> piller[i].second;
        is_piller[piller[i]]++;
    
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            //2本決めれば二つの回転で二通りしかない！
            int area = 0;
            int i_x = piller[i].first;  int i_y = piller[i].second;
            int j_x = piller[j].first;  int j_y = piller[j].second;
            int delta_x = j_x - i_x;
            int delta_y = j_y - i_y;
            if(j_x - delta_y > 0 && j_x - delta_y < 5001 && j_y + delta_x > 0 && j_y + delta_x  < 5001)
            {
                if(i_x - delta_y > 0 && i_x - delta_y < 5001 && i_y + delta_x > 0 && i_y + delta_x  < 5001)
                {
                    if(is_piller[make_pair(j_x - delta_y,j_y + delta_x)] >= 1 && is_piller[make_pair(i_x - delta_y,i_y + delta_x)] >= 1)
                    {
                        area = delta_x * delta_x + delta_y * delta_y;
                    }
                }
            }
            if(j_x + delta_y > 0 && j_x + delta_y < 5001 && j_y - delta_x > 0 && j_y - delta_x  < 5001)
            {
                if(i_x + delta_y > 0 && i_x + delta_y < 5001 && i_y - delta_x > 0 && i_y - delta_x  < 5001)
                {
                    if(is_piller[make_pair(j_x + delta_y,j_y - delta_x)] >= 1&& is_piller[make_pair(i_x + delta_y,i_y - delta_x)] >= 1)
                    {
                        area = delta_x * delta_x + delta_y * delta_y;
                    }
                }
            }
            if(ans < area) ans = area;
        }
    }
    cout << ans << endl;
    return 0;
}