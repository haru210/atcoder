#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

random_device seed_gen;
mt19937 engine(seed_gen());
// pint -> (x,y)
int main()
{
    
    int n;
    cin >> n;
    pint mack[n], sard[n];
    rep(i, n) cin >> mack[i].first >> mack[i].second;
    rep(i, n) cin >> sard[i].first >> sard[i].second;
    int ti = clock();
    vector<pint> ans;
    int max_score = 0;
    while((clock() - ti) / (long double)CLOCKS_PER_SEC < 1.99)
    {
        vector<pint> tmp;
        pint center = make_pair(engine() % 99998, engine() % 99998);
        int width = engine() % (99999 - center.first) + 1;
        int height = engine() % (99999 - center.second) + 1;
        tmp.push_back(center);
        tmp.push_back(make_pair(center.first + width, center.second));
        tmp.push_back(make_pair(center.first + width, center.second + height));
        tmp.push_back(make_pair(center.first, center.second + height));
        int macks = 0;
        int sards = 0;
        rep(i, n)
        {
            if(center.first <= mack[i].first && mack[i].first <= center.first + width && center.second <= mack[i].second && mack[i].second <= center.second + height)
            {
                macks++;
            }
            if(center.first <= sard[i].first && sard[i].first <= center.first + width && center.second <= sard[i].second && sard[i].second <= center.second + height)
            {
                sards++;
            }
        }
        int now_score = macks - sards;
        if(now_score > max_score)
        {
            ans = tmp;
            max_score = now_score;
        }
    }
    cout << 4 << endl;
    rep(i, 4)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}