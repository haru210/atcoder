#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    int k;
    ll sum = 0;
    int day;
    bool key = false;
    cin >> n >> k;
    pair<int,int> medicine[n]; //AとB
    rep(i,n) 
    {
        cin >> medicine[i].first >> medicine[i].second;
        sum += medicine[i].second;
    }
    sort(medicine,medicine + n);
    if(sum <= k)
    {
        day = 1;
        key = true;
    }
    rep(i,n)
    {
        if(key) break;
        sum -= medicine[i].second;
        day = medicine[i].first + 1;
        if(sum <= k) key = true;
    }
    cout << day << endl;
    return 0;
}