#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<char>> vc;
int m;
int n;
vector<vector<int>> start;
vector<vector<int>> poyori;

// 最大値、要素たち、という入力方式
// グローバル変数を使わなければならないという教訓

int confirm(int a, int b)
{
    if (0 <= a && a < n && 0 <= b && b < m)
    {
        if (vc[a][b] == '#')
            return 0;
        if (vc[a][b] == '.' || vc[a][b] == 'S')
        {
            vc[a][b] = '#';
            return 1;
        }
        if (vc[a][b] == 'G')
        {
            return 2;
        }
    }
    return 0;
}
bool irerukaDouka(int a, int b)
{
    int c = confirm(a, b);
    if (c == 1)
    {
        vector<int> pointersNoNaka;
        pointersNoNaka.push_back(a);
        pointersNoNaka.push_back(b);
        poyori.push_back(pointersNoNaka);
        return false;
    }
    if (c == 2)
    {
        return true;
    }
    return false;
}
bool nextPoints(int a, int b)
{
    if (irerukaDouka(a + 1, b))
    {
        return true;
    }
    if (irerukaDouka(a - 1, b))
    {
        return true;
    }
    if (irerukaDouka(a, b - 1))
    {
        return true;
    }
    if (irerukaDouka(a, b + 1))
    {
        return true;
    };
    return false;
}
int nextStep(int sum)
{
    for (std::vector<vector<int>>::const_iterator it = poyori.begin(), e = poyori.end(); it != e; ++it)
    {
        bool c = nextPoints((*it)[0], (*it)[1]);

        if (c)
        {
            return sum + 1;
        }
    }
    nextStep(sum + 1);
}

int main()
{ // <T>でT型のvector
    cin >> n;
    cin >> m;
    const int N = n;
    const int M = m;
    for (int a = 0; a < N; a++)
    {
        vector<char> vacuum;
        vc.push_back(vacuum);
        for (int b = 0; b < M; b++)
        {
            char x;
            cin >> x;
            if (x == 'S')
            {
                vector<int> startOne;
                startOne.push_back(a);
                startOne.push_back(b);
                poyori.push_back(startOne);
            }
            vc[a].push_back(x);
        }
    }
    int sum = nextStep(0);
    cout << sum << endl;
}