#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

random_device seed_gen;
mt19937 engine(seed_gen());
//1個ずつ持って帰る場合、
int main()
{
    int n;
    cin >> n;
    int min_t = inf;
    int min_cnt = inf;
    pint boxes[n][n];
    bool is_baggage[n][n];
    vector<char> min_ans(16000);
    rep(i, n)
    {
        rep(j, n) cin >> boxes[i][j].first;
    }
    rep(i, n)
    {
        rep(j, n) cin >> boxes[i][j].second;
    }
    int ti = clock();
    while((clock() - ti) / (long double)CLOCKS_PER_SEC < 1.97)
    {
        vector<pair<int, pint>> rest;
        vector<char> ans;
        rep(i, n)
        {
            rep(j, n)
            {
                if(i == 0 && j == 0) continue;
                rest.push_back(make_pair(i + j, make_pair(i, j)));
            }
        }
        sort(rest.begin(), rest.end());
        rep(i, n)
        {
            rep(j, n) is_baggage[i][j] = true;
        }
        is_baggage[0][0] = false;
        int cnt = 0;
        int x = 0;
        int y = 0;
        while(!rest.empty() && (clock() - ti) / (long double)CLOCKS_PER_SEC < 1.97)
        {
            if(cnt >= 2 * n * n * n) break;
            pair<int, pint> next;
            while(!rest.empty())
            {
                next = rest[rest.size() - 1];
                rest.pop_back();
                if(is_baggage[next.second.first][next.second.second])
                {
                    break;
                }
            }
            if(rest.empty() && !is_baggage[next.second.first][next.second.second]) break;
            int ny = next.second.first;
            int nx = next.second.second;
            is_baggage[ny][nx] = false;
            vector<int> bag_hps;
            bag_hps.push_back(boxes[ny][nx].second);
            while((ny != y || nx != x))
            {
                if(ny != y)
                {
                    if(ny > y)
                    {
                        ans.push_back('D');
                        cnt++;
                        y++;
                    }
                    else
                    {
                        ans.push_back('U');
                        cnt++;
                        y--;
                    }
                }
                else
                {
                    if(nx > x)
                    {
                        ans.push_back('R');
                        cnt++;
                        x++;
                    }
                    else
                    {
                        ans.push_back('L');
                        cnt++;
                        x--;
                    }
                }
            }
            ans.push_back('1');
            vector<char> op;
            rep(i, x)
            {
                op.push_back('L');
                cnt++;
            }
            rep(i, y)
            {
                op.push_back('U');
                cnt++;
            }
            if(cnt >= 2 * n * n * n) break;
            rep(i, 2 * (x + y))
            {
                int t1 = engine() % op.size();
                int t2 = engine() % op.size();
                swap(op[t1], op[t2]);
            }
            bool stacked = false;
            rep(i, op.size())
            {
                ans.push_back(op[i]);
                if(op[i] == 'U')
                {
                    y--;
                }
                if(op[i] == 'L')
                {
                    x--;
                }
                int w = boxes[y][x].first;
                bool can_pick = true;
                if(!is_baggage[y][x]) can_pick = false;
                if(can_pick) rep(j, bag_hps.size())
                {
                    if(bag_hps[j] <= w * (x + y)) can_pick = false;
                }
                if(can_pick)
                {
                    rep(j, bag_hps.size())
                    {
                        bag_hps[j] -= w * (x + y);
                    }
                    ans.push_back('1');
                    is_baggage[y][x] = false;
                    bag_hps.push_back(boxes[y][x].second);
                }
            }
        }
        if(rest.empty())
        {
            if(min_t > cnt)
            {
                min_t = cnt;
                min_cnt = ans.size();
                rep(i, ans.size())
                {
                    min_ans[i] = ans[i];
                }
            }
        }
    }
    rep(i, min_cnt)
    {
        cout << min_ans[i] << endl;
    }
    return 0;
}