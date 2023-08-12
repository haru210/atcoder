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
    int n;
    int x;
    cin >> n;
    int c[n];
    bool bet[n] = {false};
    vector<pair<int,int>> bet_size;
    int a[n][37];
    rep(i,n)
    {
        cin >> c[i];
        rep(j,c[i])
        {
            cin >> a[i][j];
        }
    }
    cin >> x;
    rep(i,n)
    {
        rep(j,c[i])
        {
            if(a[i][j] == x) bet[i] = true; 
        }
    }
    rep(i,n)
    {
        if(bet[i] == true) bet_size.push_back(make_pair(c[i],i));
    }
    sort(bet_size.begin(),bet_size.end());
    int num = 0;
    rep(i,bet_size.size())
    {
        if(bet_size[i].first == bet_size[0].first)
        {
            num++;
        }
    }
    cout << num << endl;
    if(num != 0){
        rep(i,num)
        {
            cout << bet_size[i].second + 1 << ' ';
        }
    }
    if(num != 0)  cout << endl;
    return 0;
}