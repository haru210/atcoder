#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,m;
    cin >> n >> m;
    queue<int> a;
    queue<int> b;
    queue<int> c;
    int tmp;
    rep(i,n)
    {
        cin >> tmp;
        a.push(tmp);
    }
    rep(i,m)
    {
        cin >> tmp;
        b.push(tmp);
    }
    while(true){
        int t;
        if(a.empty() && b.empty()) break;
        else if(a.empty() || b.empty())
        {
            if(a.empty())
            {
                t = b.front();
                b.pop();
            }
            else if(b.empty())
            {
                t = a.front();
                a.pop();
            }
        }
        else
        {
            int ta,tb;
            ta = a.front();
            tb = b.front();
            if(tb < ta)
            {
                t = tb;
                b.pop();
            }
            else
            {
                t =ta;
                a.pop();
            }
        }
        c.push(t);
    }
    while(!c.empty())
    {
        cout << c.front() << endl;
        c.pop();
    }
    return 0;
}