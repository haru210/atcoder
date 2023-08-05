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
    string s;
    int cnt = 0;
    cin >> s;
    rep(i,10000)
    {
        bool flag[10] = {0};
        int tmp = i;
        for(int j = 0; j < 4;j++)
        {
            flag[tmp %10] = true;
            tmp /= 10;
        }
        bool ok = true;
        rep(j,10)
        {
            if(s[j] == 'o' && flag[j] == false) ok = false;
            if(s[j] == 'x' && flag[j] == true) ok = false;
        }
        if(ok) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
//各桁を取り出す際余分にした分は0になる