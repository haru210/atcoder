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
    ll n,t;
    map<ll, ll> isScore;
    cin >> n >> t;
    ll a[t], b[t];
    rep(i,t) cin >> a[i] >> b[i];
    ll var = 1;
    ll score[n] = {};
    isScore[0] = n;
    rep(i,t)
    {
        a[i]--;
        //一つ->複数 -1 一つ->一つ 0 複数->一つ
        //変更後のスコアがその選手と同じになることはあり得ない(変動は1以上なので)
        bool wasOrigin = false, isOrigin = false; //変更前、変更後その数字は一つだけか
        if(isScore[score[a[i]]] == 1) wasOrigin = true;
        if(isScore[score[a[i]] + b[i]] == 0) isOrigin = true;
        if(isOrigin != wasOrigin)
        {
            if(isOrigin == true) var++;
            if(wasOrigin == true) var--;
        }
        cout << var << endl;
        isScore[score[a[i]]]--;
        score[a[i]] += b[i];
        isScore[score[a[i]]]++;
    }
    return 0;
}