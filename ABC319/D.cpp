#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

bool check(ll side);
int n, m;
long l[200000];
int main()
{
    cin >> n >> m;
    ll sum = 0;
    int l_max = 0;
    rep(i,n)
    {
        cin >> l[i];
        if(l_max < l[i]) l_max = l[i];
        sum += l[i];
    }
    sum += n;
    ll left = l_max - 1;
    ll right = sum + 1;
    while(right - left > 1)
    {
        ll mid = (left + right) / 2;
        if(check(mid))
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

bool check(ll side)
{
    int sent = 1;
    int word = 0;
    ll tex = 0;
    int space;
    while(word < n)
    {
        if(tex != 0) space = 1;
        if(tex == 0) space = 0;
        if(side - tex >= (l[word] + space))
        {
            tex += l[word];
            tex += space;
            word++;
        }
        else
        {
            sent++;
            tex = 0;
        }
    }
    
    if(sent > m) return false;
    else return true;
}