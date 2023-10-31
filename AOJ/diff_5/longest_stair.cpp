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
int main()
{
    int n,k;
    int max_chain = -1;
    cin >> n >> k;
    bool card[n+1] = {false};
    rep(i,k)
    {
        int tmp;
        cin >> tmp;
        card[tmp] = true;
    }
    if(!card[0])
    {
        int start = 0;
        int now = 1;
        while(now <= n)
        {
            if(!card[now])
            {
                max_chain = max(max_chain, (now - start - 1));
                start = now;
            }
            now++;
        }
        max_chain = max(max_chain, (now - start - 1));
    }
    if(card[0])
    {
        int start = 0;
        int zero_point = 0;
        while(true)
        {
            zero_point++;
            if(!card[zero_point]) break;
            if(zero_point == n - 1) max_chain = n;
        }
        int now = zero_point + 1;
        while(now <= n)
        {
            if(!card[now])
            {
                max_chain = max(max_chain, (now - (start - 1)-1));
                start = zero_point + 1;
                zero_point = now;
            
            }
            now++;
        }
        max_chain = max(max_chain, (now - (start - 1) - 1));
    }
    cout << max_chain << endl;
    return 0;
}