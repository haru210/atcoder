#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b;
    int sum;
    cin >> a >> b;
    sum = a * b;
    sum %= 2;
    if(sum == 0)
    {
        cout << "Even\n";
    }
    else
    {
        cout << "Odd\n";
    }
    return 0;
}