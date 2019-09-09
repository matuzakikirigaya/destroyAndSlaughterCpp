#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<char>> vc;
int m;
int n;

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
bool irerukaDouka(int a, int b, vector<vector<int>> pointers)
{
    int c = confirm(a, b);
    if (c == 1)
    {
        vector<int> pointersNoNaka;
        pointersNoNaka.push_back(a);
        pointersNoNaka.push_back(b);
        pointers.push_back(pointersNoNaka);
        cout << pointers[0][0] << pointers[0][1] << endl;
        return false;
    }
    if (c == 2)
    {
        return true;
    }
    return false;
}
bool nextPoints(int a, int b, vector<vector<int>> pointers)
{
    if (irerukaDouka(a + 1, b, pointers))
    {
        return true;
    }
    if (irerukaDouka(a - 1, b, pointers))
    {
        return true;
    }
    if (irerukaDouka(a, b - 1, pointers))
    {
        return true;
    }
    if (irerukaDouka(a, b + 1, pointers))
    {
        return true;
    };
    cout << "tugi" << pointers[0][0] << endl;
    return false;
}
int nextStep(vector<vector<int>> pointers, int sum)
{
    vector<vector<int>> pointers2;
    for (std::vector<vector<int>>::const_iterator it = pointers.begin(), e = pointers.end(); it != e; ++it)
    {
        cout << "hoge" << endl;
        bool c = nextPoints((*it)[0], (*it)[1], pointers2);
        cout << "hoge" << endl;
        cout << pointers2[0][0] << endl;
        if (c)
        {
            return sum;
        }
    }
    nextStep(pointers2, sum + 1);
}

int main()
{ // <T>でT型のvector
    vector<vector<int>> start;
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
                start.push_back(startOne);
            }
            vc[a].push_back(x);
        }
    }
    int sum = nextStep(start, 0);
    cout << sum << endl;
}