#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d,x,y;
    cin >> d >> x >> y;
    if(abs(x) + abs(y) <= d) cout << "Yes\n";
    else cout << "No\n";
}