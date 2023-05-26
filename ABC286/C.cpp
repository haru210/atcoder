#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void slideStr(string& d); //操作A
/*
A円払う操作を操作A、B円払う操作を操作B、とする
A円払う操作はN買い行えば元に戻る
A円払う操作を行う回数を全探索し、それぞれの場合で何回操作Bを行えば回文になるかを確かめ、それぞれでかかった値段をminで比較し、出力する。
計算量はO(N*(N/2))より、十分高速
*/
int main()
{
    int n, a, b;
    int left, right;
    string s;
    cin >> n >> a >> b >> s;
    rep(i, n) //操作Aを行う回数
    {
       s = slideStr(s, n);
    }
    left = 0;
    right = n - 1;
    while(left >= right)
    {
        //操作B
    }
    return 0;
}

string slideStr(string d, int size)
{
    string tmp = "";
    for(int i = 0; i < size - 1; i++)
    {
        tmp += d[i + 1]; 
    }
    tmp += d[size - 1];
    return tmp;
}