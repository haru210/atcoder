#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int min_bound(int a[],int a_size,int num);

int main()
{
    int n,m;
    cin >> n>> m;
    int sell[n],buy[m];
    pair<int,bool> event[n+m]; //true=売り false=買い
    rep(i,n) cin >> sell[i];
    rep(i,m) cin >> buy[i];
    rep(i,n+m)
    {
        if(i < n){
            event[i].first = sell[i];
            event[i].second = true;
        }
        else
        {
            event[i].first = buy[i-n]+1;
            event[i].second = false;
        }
    }
    sort(event,event+(n+m));
    int bx=m,sx=0;
    rep(i,n+m)
    {
        if(event[i].second) sx++;
        if(!event[i].second) bx--;
        if(sx >= bx)
        {
            cout << event[i].first << endl;
            break;
        }
    }
    return 0;
}
