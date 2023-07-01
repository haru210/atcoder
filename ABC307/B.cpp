#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
bool PalindromeCheck(string s);
int main()
{
    int n;
    cin >> n;
    string s[100];
    string tmp;
    bool flag = false;;
    rep(i, n) cin >> s[i];
    rep(i, n)
    {
        rep(j,n)
        {
            if(i == j) continue;
            tmp = "";
            tmp += s[i];
            tmp += s[j];
            if(PalindromeCheck(tmp))
            {
               flag = true; 
            }
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

bool PalindromeCheck(string s)
{
  int left = 0;
  int right = s.size() - 1;
  while(right > left)
  {
    if(s[left] != s[right]) return false;
    else
    {
        left++;
        right--;
    }
  }
  return true;
}