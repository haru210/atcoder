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
bool compare(pint p1, pint p2)
{
    if(p1.first == p2.second) return p1.second < p2.second;
    else return p1.first > p2.second;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int a[m];
    int vote[n+1] = {};
    rep(i,m) cin >> a[i];
    //愚直にシミュレーションでいける？
    //順位が変わるのは票が入った人だけ
    int most_vote = 0;
    int mv_per = inf;
    rep(i,m)
    {
        vote[a[i]]++;
        if((most_vote < vote[a[i]]) || (most_vote == vote[a[i]] && a[i] < mv_per))
        {
            most_vote = vote[a[i]];
            mv_per = a[i];
        }
        cout << mv_per << endl;
    }
    return 0;
}