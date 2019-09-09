#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <algorithm>
using namespace std;

// 最大値、要素たち、という入力方式

int n;
int m;

vector<vector<char>> vc;
void hakyuu(int c, int d)
{
    if (0 <= c && c < n && 0 <= d && d < m && vc[c][d] == 'W') //なんか数学でよく使うような表記はだめならしい
    {
        vc[c][d] = '.';
        for (int xOfStart = -1; xOfStart <= 1; xOfStart++)
        {
            for (int yOfStart = -1; yOfStart <= 1; yOfStart++)
            {
                hakyuu(c + xOfStart, d + yOfStart);
            }
        }
    }
    else
    {
    }
}
bool initial(int e, int f)
{
    if (0 <= e && e < n && 0 <= f && f < m && vc[e][f] == 'W') //vector使うときは注意して使ったほうがいいよ
    {
        hakyuu(e, f);
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // <T>でT型のvector
    cin >> n;
    cin >> m;
    for (int a = 0; a < n; a++)
    {
        vector<char> vacuum;
        vc.push_back(vacuum);
        for (int b = 0; b < m; b++)
        {
            char x;
            cin >> x;
            vc[a].push_back(x);
        }
    }
    int countOfLake = 0;
    for (int xOfStart = 0; xOfStart < n; xOfStart++)
    {
        for (int yOfStart = 0; yOfStart < m; yOfStart++)
        {
            if (initial(xOfStart, yOfStart))
            {
                countOfLake++;
            }
        }
    }
    cout << countOfLake << endl;
}