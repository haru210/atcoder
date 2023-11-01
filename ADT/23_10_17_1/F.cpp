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
    int n;
    pint now = make_pair(0,0); //first,second <=> x,y;
    map<pint,int> dic;
    string s;
    cin >> n >> s;
    dic[now]++;
    bool ok = false;
    rep(i,n)
    {
        switch(s[i])
        {
            case 'R':
            now.first++;
            break;

            case 'L':
            now.first--;
            break;

            case 'U':
            now.second++;
            break;

            case 'D':
            now.second--;
            break;
        }
        if(dic[now] >= 1) 
        {
            ok = true;
            break;
        }
        dic[now]++;
    }
    YesNo(ok);
    return 0;
}