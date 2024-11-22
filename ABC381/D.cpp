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

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    int start = 0;
    int now = 0; 
    int ans = 0;
    //0から偶数
    while(start < n - 1)
    {
        now = start;
        int now_len = 0;
        map<int, int> var;
        int dup_cnt = 0;
        bool correct = false;
        while(a[now] == a[now + 1])
        {
            correct = true;
            var[a[now]]++;
            if(var[a[now]] > 1)
            {
                dup_cnt++;
            }
            if(dup_cnt == 0)
            {
                now_len = now - start + 2;
                ans = max(ans, now_len);
            }
            while(dup_cnt > 0)
            {
                var[a[start]]--;
                if(var[a[start]] == 1) dup_cnt--;
                start += 2;
            }
            now += 2;
            if(now >= n) break;
        }
        if(now >= n) break;
        if(correct) start = now;
        else start += 2;
    }
    start = 1;
    now = 1;
    while(start < n - 1)
    {
        now = start;
        int now_len = 0;
        map<int, int> var;
        int dup_cnt = 0;
        bool correct = false;
        while(a[now] == a[now + 1])
        {
            correct = true;
            var[a[now]]++;
            if(var[a[now]] > 1)
            {
                dup_cnt++;
            }
            if(dup_cnt == 0)
            {
                now_len = now - start + 2;
                ans = max(ans, now_len);
            }
            while(dup_cnt > 0)
            {
                var[a[start]]--;
                if(var[a[start]] == 1) dup_cnt--;
                start += 2;
            }
            now += 2;
            if(now >= n) break;
        }
        if(now >= n) break;
        if(correct) start = now;
        else start += 2;
    }

    cout << ans << endl;
    return 0;
}