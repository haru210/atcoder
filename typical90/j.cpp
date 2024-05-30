#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n, q;
    cin >> n;
    int c[n], p[n];
    rep(i, n) cin >> c[i] >> p[i];
    cin >> q;
    int l[q], r[q];
    rep(i, q) cin >> l[i] >> r[i];
    //それぞれのクラスに番号、累積和を振り分ける
    vector<int> c1;
    vector<int> ps1;
    vector<int> c2;
    vector<int> ps2; 
    rep(i, n)
    {
        if(c[i] == 1)
        {
            c1.push_back(i + 1);
            if(ps1.size() == 0)ps1.push_back(p[i]);
            else ps1.push_back(p[i] + ps1[ps1.size() - 1]);
        }
        if(c[i] == 2)
        {
            c2.push_back(i + 1);
            if(ps2.size() == 0)ps2.push_back(p[i]);
            else ps2.push_back(p[i] + ps2[ps2.size() - 1]);
        }
    }
    rep(i, q)
    {
        int left;
        int right;
        if(c1.size() != 0)
        {
            left = lower_bound(c1.begin(), c1.end(), l[i]) - c1.begin();
            right = lower_bound(c1.begin(), c1.end(), r[i]) - c1.begin();
            if(right == c1.end() - c1.begin()) right--;
            else if(c1[right] != r[i]) right--;
            if(left == 0) cout << ps1[right] << ' ';
            else cout << ps1[right] - ps1[left - 1] << ' ';
        }
        else cout << 0 << ' ';
        if(c2.size() != 0)
        {
            left = lower_bound(c2.begin(), c2.end(), l[i]) - c2.begin();
            right = lower_bound(c2.begin(), c2.end(), r[i]) - c2.begin();
            if(right == c2.end() - c2.begin()) right--;
            else if(c2[right] != r[i]) right--;
            if(left == 0) cout << ps2[right] << endl;
            else cout << ps2[right] - ps2[left - 1] << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}