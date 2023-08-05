#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

bool checked(int sell[],int buy[],int num);

int n,m;
int main()
{
    cin >> n >> m;
    int sell[n],buy[m];
    rep(i,n) cin >> sell[i];
    rep(i,m) cin >> buy[i];
    int left=0,right=1000000001;
    int mid;
    while(right - left > 1)
    {
        mid = (left+right)/2;
        bool ok = checked(sell,buy,mid);
        if(ok)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << right << endl;
    return 0;
}

bool checked(int sell[],int buy[],int num)
{
    int sx=0,bx=0;
    rep(i,n)
    {
        if(sell[i] <= num) sx++;
    }
    rep(i,m)
    {
        if(buy[i] >= num) bx++;
    }
    if(sx >= bx) return true;
    else return false;
}
