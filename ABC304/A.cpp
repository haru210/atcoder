#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    int minimum = 0;
    int cnt = 0;
    pair<int, string> s[100];
    cin >> n;
    rep(i, n)
    {
        int tmp;
        string tmp_s;
        cin >> tmp_s >> tmp;
        s[i] = {tmp, tmp_s};
    }

    rep(i, n)
    {
      if(s[i].first < s[minimum].first) minimum = i;
    }
    cnt = minimum;
    rep(i, n)
    {
        cout << s[cnt].second << endl;
        if(cnt >= n - 1) cnt = 0;
        else cnt++;
    }
    return 0;
}