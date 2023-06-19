#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    int size;
    string s;
    cin >> n;
    s = to_string(n);
    size = s.size();
    int sum = (n / pow(10,size - 3));
    sum *= pow(10, size - 3);
    cout << sum << endl;

    return 0;
}