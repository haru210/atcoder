#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

bool compare(pair<string,int> a1,pair<string,int> a2);

int main()
{
    int n;
    cin >> n;
    pair<string,int> m[n];
    rep(i,n)
    {
        cin >> m[i].first >> m[i].second;
    }
    sort(m,m+n,compare);
    cout << m[1].first << endl;
    return 0;
}

bool compare(pair<string,int> a1,pair<string,int> a2)
{
    return a1.second > a2.second;
}