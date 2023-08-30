#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int a[810][810];
int s[810][810] = {0};
int main()
{
    int n,k;
    int a_max = 0;
    cin >> n >> k;
    rep2(i,1,n) rep2(j,1,n)
    {
        cin >> a[i][j];
        a_max = max(a_max,a[i][j]);
    }
    //答え:=xとして、xを固定したとき、中央値がx以下の区画があるか求める
    //xを0~max(A_i)で二分探索
    int left = -1,right = a_max+1;
    int mid;
    int lim = (k*k / 2) + 1;
    rep(i,810)
    {
        s[i][0] = 0;
        s[0][i] = 0; 
    }
    while(right - left > 1)
    {
        mid = (left+right) / 2;
        rep(i,n)
        {
            rep(j,n)
            {
                s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j];
                if(a[i+1][j+1] > mid) s[i+1][j+1]++;
            }
        }
        bool ok = false;
        rep2(i,1,n-k+1)
        {
            rep2(j,1,n-k+1)
            {
                if((s[i+k-1][j+k-1] +s[i-1][j-1]-s[i-1][j+k-1]-s[i+k-1][j-1]) < lim){
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok)right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}