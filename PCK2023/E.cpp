#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<pair<long long, long long> > prime;
    for(long long i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            long long cnt = 0;
            while(n % i == 0)
            {
                n /= i;
                cnt++;
            }
            prime.push_back(make_pair(i, (long long)cnt));
        }
    }
    if(n != 1) prime.push_back(make_pair(n, 1));
    bool ok = true;
    bool is_twice = false;
    bool is_single = false;
    if(prime.size() == 2)
    {
        for(int i = 0; i < prime.size(); i++)
        {
            if(prime[i].second == 2)
            {
                if(is_twice) ok = false;
                else is_twice = true;
            }
            if(prime[i].second == 1)
            {
                if(is_single) ok = false;
                else is_single = true;
            }
        }
    }
    if(ok && is_twice && is_single) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}