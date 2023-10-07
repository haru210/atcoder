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

bool compare(pint& s1, pint&s2)
{
    if(s1.first == s2.first)
    {
        return s1.second < s2.second;
    }
    else
    {
        return s1.first > s2.first;
    }
}
int main()
{
    int n;
    cin >> n;
    string s[n];
    pint win[n];
    rep(i,n)
    {
        win[i].second = i;
    }
    rep(i,n) cin >> s[i];
    rep(i,n) rep(j,n)
    {
        if(i == j) continue;
        if(s[i][j] == 'o') win[i].first++;
    }
    sort(win,win+n,compare);
    rep(i,n-1)
    {
        cout << win[i].second + 1 << ' ';
    }
    cout << win[n-1].second + 1 << endl;
    return 0;
}