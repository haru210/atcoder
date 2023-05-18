#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long  a, b;
    long long cnt = 0;
    cin >> a >> b;
    while(a != b)
    {
        if(a < b)
        {
            b = b - a;
        }
        else
        {
            a = a -b;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}