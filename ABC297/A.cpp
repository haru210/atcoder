#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    bool flag = false;
    cin >> n >> d;
    int t[110];
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for(int i = 1; i < n; i++)
    {
        if((t[i] - t[i - 1]) <= d)
        {
            cout << t[i] << endl;
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout << -1 << endl;
    }
    return 0;
}