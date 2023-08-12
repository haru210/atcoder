#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,q;
    int uppered = -1; //-1なら変化なし1なら大文字化、0なら小文字化
    int last_capital = -1;
    string s;
    cin >> n >> s >> q;
    int changed[n] = {0};
    tuple<int,int,char> op[q];
    rep(i,q)
    {
        cin >> get<0>(op[i]) >> get<1>(op[i]) >> get<2>(op[i]);
    }
    rep(i,q)
    {
        if(get<0>(op[i]) == 1)
        {
            s[get<1>(op[i]) - 1] = get<2>(op[i]);
            changed[get<1>(op[i]) - 1] = i;
        }
        else if(get<0>(op[i]) == 2)
        {
            uppered = 0;
            last_capital = i;
        }
        else if(get<0>(op[i]) == 3)
        {
            uppered = 1;
            last_capital = i;
        }
    }
    rep(i,n)
    {
        if(uppered == 0)
        {
            if(changed[i] < last_capital)
            {
                s[i] = tolower(s[i]);
            }
        }
        if(uppered == 1)
        {
            if(changed[i] < last_capital)
            {
                s[i] = toupper(s[i]);
            }
        }
    }
    cout << s << endl;
    return 0;
}