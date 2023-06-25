#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int d = 1;
int main()
{
    map<int,pair<int, int>> a;
    map<pair<int,int>,int> rev;
    pair<int,int> correct;
    pair<pair<int,int>, pair<int,int>> answer[10000];
    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            int tmp;
            cin >> tmp;
            a[tmp] = make_pair(i,j); 
            rev[make_pair(i,j)] = tmp;
        }
    }
    int num = 0;
    rep(i, 30)
    {
        for(int j = 0; j <= i; j++)
        {
            if(cnt >= 10000) break;
            correct = make_pair(i,j);
            while(!flag)
            {
                if(cnt >= 10000) break;
                //縦移動
                if(a[num].first != correct.first)
                {
                    //上下移動の係数作り(上移動はy座標がマイナス、下移動はy座標がプラスになることを利用)
                    if(a[num].first > correct.first) d = -1;
                    if(a[num].first < correct.first) d = 1;
                    //基本x座標が変わらない(右上or左下)移動、できない場合は変わる移動（左上移動)
                    //右上or左下移動
                    if(a[num].second == a[num].first && d == -1)
                    {
                        int tmp = rev[make_pair(a[num].first + d, a[num].second - 1)];
                        answer[cnt] = make_pair(a[num],make_pair(a[num].first + d,a[num].second - 1));
                        swap(rev[a[num]], rev[a[tmp]]);
                        swap(a[num].first, a[tmp].first);
                        swap(a[num].second,a[tmp].second);
                        cnt++;
                    }
                    else
                    {
                        int tmp = rev[make_pair(a[num].first + d, a[num].second)];
                        answer[cnt] = make_pair(a[num],make_pair(a[num].first + d,a[num].second));
                        swap(rev[a[num]], rev[a[tmp]]);
                        swap(a[num].first, a[tmp].first);
                        cnt++;

                    }
                }
                //横移動
                else if(a[num].second != correct.second)
                {  
                    //左右移動の係数づくり
                    if(a[num].second > correct.second) d = -1;
                    if(a[num].second < correct.second) d = 1;
                    //左右移動
                    int tmp = rev[make_pair(a[num].first,a[num].second + d)];
                    answer[cnt] = make_pair(a[num],make_pair(a[num].first,a[num].second + d));
                    swap(rev[a[num]], rev[a[tmp]]);
                    swap(a[num].second,a[tmp].second);
                    cnt++;
                }
                //座標があっているかの確認
                if(a[num].first == correct.first && a[num].second == correct.second)
                {
                    flag = true;
                } 
            }
            flag = false;
            num++;
        }
        if(cnt >= 10000) break;
    }
    //出力
    cout << cnt << endl;
    rep(i, 20)
    {
    cout << answer[i].first.second << ' ' << answer[i].first.first << ' ' << answer[i].second.second << ' ' << answer[i].second.first << endl; 
    }
    return 0;
}
 