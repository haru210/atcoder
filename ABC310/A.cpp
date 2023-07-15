#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,p,q;
    int order = inf;
    cin >> n >> p >> q;
    rep(i, n){
        int tmp;
        cin >> tmp;
        order = min(order,tmp);
    }
    order = min(order + q,p);
    cout << order << endl;
    return 0;
}