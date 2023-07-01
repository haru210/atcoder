#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int a[200009],b[200009];
pair<double,int> rate[200009];

int main()
{
    int n;
    cin >> n;
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n)
    {
        double tmp = (double)a[i] / ((double)a[i] + b[i]);
        if(a[i] == 0) tmp = 0;
        if(b[i] == 0) tmp = 1;
        rate[i].first = tmp;
        rate[i].first *= (double)-1;
        rate[i].second = i + 1; //1-indexedに調整
    }
    rep(i, n)
    {
        cout <<rate[i].first << endl;
    }
    sort(rate,rate + n);
    rep(i, n)
    {
        cout << rate[i].second << ' ';
    }
    cout << endl;
    return 0;
}