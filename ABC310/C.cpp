#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    string s[n];
    string re;
    int sum = 0;
    rep(i,n) cin >> s[i];
    map<string,int> num;
    rep(i,n)
    {
        re = s[i];
        reverse(re.begin(),re.end());
        if(num[s[i]] == 0 && num[re] == 0){
            num[s[i]]++;
        }
    }
    for(auto [key,val] : num)
    {
        if(num[key] != 0) sum++;
    }
    cout << sum << endl;
    return 0;
}