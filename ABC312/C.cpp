#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int min_bound(int a[],int a_size,int num);

int main()
{
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    map<int,int> a_num;
    rep(i,n)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
        a_num[tmp]++;
    }
    rep(i,m) cin >> b[i];
    //売り手の人数が変わるのはa[i]のみ
    //ソートすれば添え字+1＝人数にできる?
    sort(a,a+n);
    sort(b,b+m,greater<int>());
    int buyer,seller=0;
    int i = 0;
    if(b[0] < a[0])
    {
        cout << b[0]+1 << endl;
    }
    else for(auto [key,val]: a_num)
    {
        buyer = min_bound(b,m,110);
        seller += val;
        if(seller >= buyer)
        {
            cout << a[i] << endl;
            break;
        }
        i += val;
    }
    return 0;
}
// a{10000,120,100,80} num 110 numより小さいを真、大きいを偽、leftは常に偽,rightは常に真
int min_bound(int a[],int a_size,int num)
{
    
    int left,right;
    int center;
    left = -1;
    right = a_size;
    while(right - left > 1)
    {
        center = left + ((right - left) / 2);
        if(a[center] > num)
        {
            left = center;
        }
        else if(a[center] <= num)right = center;
    }
    return right;
}