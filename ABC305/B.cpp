#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int distance[7] = {0,3,4,8,9,14,23};
    char p, q;
    cin >> p >> q;
    int p_num, q_num;
    p_num = p - 'A';
    q_num = q - 'A';
    int sum = distance[p_num] - distance[q_num];
    sum = abs(sum);
    cout << sum << endl;
    return 0;
}