#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    long long  a, b;
    long long sum;
    cin >> a >> b;
    sum = a / b;
    if(a %b !=0)sum++;
    cout << sum << endl;
    return 0;
}