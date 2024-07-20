#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int main()
{
    int n, k;
    ll cnt = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do{
        bool is_pal = false;
        for(int i = 0; i < (n - k + 1); i++) //開始位置確認
        {
            int left = i;
            int right = (i + k - 1);
            bool tmp = true;
            while(right > left)
            {
                if(s[left] != s[right])
                {
                    tmp = false;
                    break;
                }
                right--;
                left++;
            }
            if(tmp){
                is_pal = true;
                break;
            }
        } 
        if(!is_pal) cnt++;
    }while(next_permutation(s.begin(), s.end()));
    cout << cnt << endl;
    return 0;
}