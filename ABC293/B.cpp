#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[200000];
bool called[200000] = {0};

int main()
{
    int n;
    cin >> n;
    int uncalled = n;
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        if(!called[i])
        {
            if(!called[a[i] - 1]) uncalled--;
            called[a[i] - 1] = true;
        }
    }
    cout << uncalled << endl;
    rep(i, n)
    {
        if(!called[i])
        {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
    return 0;
}