#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    map<int,bool> Has;
    vector<int> h(n);
    int t_sum = 0;
    int h_sum = 0;
    rep(i,n)
    {
        cin >> t[i];
        Has[t[i]] = true;
    }
    sort(t.begin(),t.end());
    int cnt = 0;
    rep2(i,2*n)
    {
        if(!Has[i])
        {
            h[cnt] = i;
            cnt++;
        } 
    }
    bool end = false;
    bool side = true; //true太郎の番 false花子の番
    int back = 0;
    while(!end)
    {
        if(side)
        {
            if(t[t.size()-1] > back)
            {
                    
                    auto pos = lower_bound(t.begin(),t.end(),back);
                    if(*pos == back) pos++;
                    back = *pos;
                    t.erase(pos);
            }
            else
            {
                back = 0;
            }
            side = false;
        }
        else if(!side)
        {
            if(h[h.size()-1] > back)
            {
                    auto pos = lower_bound(h.begin(),h.end(),back);
                    if(*pos == back) pos++;
                    back = *pos;
                    h.erase(pos);
            }
            else
            {
                back = 0;
            }
            side = true;
        }
        if(t.empty())
        {
            end = true;
            side = true;            
        }
        if(h.empty()) 
        {
            end = true;
            side = false;
        }
    }
    if(side)
    {
        rep(i,h.size())
        {
            t_sum++;
        }
    }
    if(!side)
    {
        rep(i,t.size())
        {
            h_sum++;
        }
    }
    cout << t_sum << endl;
    cout << h_sum << endl;
    return 0;
}