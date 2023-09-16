#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
    srand((unsigned)time(NULL));
    int y_game=0,t_game=0,s_game=0;
    ll avg_game=0;
    ll cnt;
    cout << "ŽŽs‰ñ”H\n";
    cin >> cnt;
    rep(i,cnt)
    {
        int left_cnt = 3;
        int game = 0;
        int result;
        int yoshino=0,takeuchi=0,sumioka=0;
        while(true)
        {
            game++;
            int* a_side;
            int* b_side;
            int card;

            if(left_cnt == 2)
            {
                if(sumioka >= 5) card = 0; 
                if(takeuchi >= 5)card = 1;
                if(yoshino >= 5) card = 2;
            }
            else card = game % 3;
            switch(card)
            {
                case 0:
                    a_side = &takeuchi;
                    b_side = &yoshino;
                break;

                case 1:
                    a_side = &sumioka;
                    b_side = &yoshino;
                break;

                case 2:
                    a_side = &sumioka;
                    b_side = &takeuchi;
                break; 
            }

            result = rand() % 3;
            if(result == 0) continue;
            if(result == 1)
            {
                *a_side += 1;
                *b_side -= 1;
            } 
            if(result == 2)
            {
                *a_side -= 1;
                *b_side += 1;
            }

            int out_count= 0;
            if(takeuchi >= 5) out_count++;
            if(yoshino >= 5) out_count++;
            if(sumioka >= 5) out_count++;

            if(out_count == 1) left_cnt = 2;
            if(out_count == 2)
            {
                if(takeuchi < 5) t_game++;
                if(yoshino < 5) y_game++;
                if(sumioka < 5) s_game++;
                avg_game+= game;
                break;
            }
            if(game >= 10000000) break;
        }
    }
    cout << "’|“à‚ªô‚¤Šm—¦‚Í " <<setprecision(10) << (long double)t_game / (long double)cnt * 100.0 << "%\n";
    cout << "‹g–ì‚ªô‚¤Šm—¦‚Í " <<setprecision(10) << (long double)y_game / (long double)cnt * 100.0 << "%\n";
    cout << "Z‰ª‚ªô‚¤Šm—¦‚Í " <<setprecision(10) << (long double)s_game / (long double)cnt * 100.0 << "%\n";
    cout << "•½‹Ï•K—vƒQ[ƒ€”‚Í"<< setprecision(10) << (long double)avg_game / (long double)cnt << endl;

    return 0;
}