#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    int tmp;
    int before = 0;
    int sum = 0;
    cin >> n;
    vector<int> d;
    rep(i, n)
    {
        cin >> tmp;
        d.push_back(tmp);
    }
    sort(d.begin(),d.end());
    reverse(d.begin(), d.end());
    rep(i, n)
    {
        if(d[i] != before)
        {
            sum++;
            before = d[i];
        }
    }
    cout << sum << endl;
    return 0;
}