#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const long long l_inf = 9223372036854775807;
const int inf = 2147483647;

string slideStr(string d, int size); //操作A
/*
A円払う操作を操作A、B円払う操作を操作B、とする
A円払う操作はN買い行えば元に戻る
A円払う操作を行う回数を全探索し、それぞれの場合で何回操作Bを行えば回文になるかを確かめ、それぞれでかかった値段をminで比較し、出力する。
計算量はO(N*(N/2))より、十分高速
*/
int main()
{
    int n;
    long long a, b;
    int left, right;
    long long  sum = 0;
    long long  num = l_inf;
    string s;
    cin >> n >> a >> b >> s;
    rep(i, n) //操作Aを行う回数
    {
        left = 0;
        right = n - 1;
        sum = 0;
        while(left <= right)
        {
            if(s[left] != s[right]) sum += b;
            left++;
            right--;
        }
        sum += (a * i);
        num = min(num, sum);
        s = slideStr(s, n);
    }
    cout << num << endl;
    return 0;
}

string slideStr(string d, int size)
{
    string tmp = "";
    for(int i = 0; i < size - 1; i++)
    {
        tmp += d[i + 1]; 
    }
    tmp += d[0];
    return tmp;
}