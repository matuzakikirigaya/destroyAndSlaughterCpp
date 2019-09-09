#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<char>> vc;
int m;
int n;
int startA;
int startB;

// 最大値、要素たち、という入力方式

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
int trueSum;
bool voyager(int a, int b, int sum)
{
    cout << a << b << sum << endl;
    int c = confirm(a, b);
    if (c == 0)
    {
    }
    if (c == 2)
    {
        trueSum = sum;
        return true;
    }
    if (c == 1)
    {
        if (voyager(a - 1, b, sum + 1))
            return true;
        if (voyager(a + 1, b, sum + 1))
            return true;
        if (voyager(a, b - 1, sum + 1))
            return true;
        if (voyager(a, b + 1, sum + 1))
            return true;
    }
    return false;
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
                startA = a;
                startB = b;
            }
            vc[a].push_back(x);
        }
    }
    voyager(startA, startB, 0);
    cout << trueSum << endl;
}