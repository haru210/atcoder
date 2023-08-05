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
    int n,m;
    cin >> n >> m;
    string s[n];
    rep(i,n)
    {
        cin >> s[i];
    }
    //縦を先に探索して昇順に出すぞ！
    rep(i,n - 8)
    {
        rep(j,m-8)
        {
            bool ok = true;
            //左上探索
            for(int k = j; k < j + 4;k++)
            {
                for(int l = i; l < i + 4; l++)
                {
                    if(k < j + 3 && l < i + 3)
                    {
                        if(s[l][k] != '#') ok = false;
                    }
                    else
                    {
                        if(s[l][k] != '.') ok = false;
                    }
                }
            }
            //右下探索
            for(int k = j+5; k < j + 9;k++)
            {
                for(int l = i+5; l < i + 9; l++)
                {
                   if(k >= j+6 && l >= i+6)
                   {
                        if(s[l][k] != '#') ok = false;
                   }
                   else
                   {
                        if(s[l][k] != '.') ok = false;
                   }
                }
            } 
            if(ok) cout << i+1 << ' ' << j+1 << endl;
        }
    }
    return 0;
}
