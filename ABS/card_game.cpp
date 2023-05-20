#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//大きい順にソートし、一番目から交互にとっていく（貪欲法)

int main()
{
    int n;
    int alice = 0;
    int bob = 0;
    int a[100];

    //入力
    cin >> n;
    rep(i, n)
    {
        cin >> a[i];
    }
    //ソート
    sort(a, a+n);
    reverse(a, a+n);
    //カードをとる
    for(int i = 0;i < n - 1;i+= 2)
    {
        alice += a[i];
        bob += a[i + 1];   
    }
    //最後の一枚を処理
    if(n%2 == 1)
    {
        alice += a[n - 1];
    }
    cout << alice - bob << endl;
    return 0;
}

//コーナーケースの処理を怠らない!