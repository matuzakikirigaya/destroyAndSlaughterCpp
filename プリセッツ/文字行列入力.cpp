#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<char>> vc;
int m;
int n;

// 最大値、要素たち、という入力方式

int main()
{
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
            vc[a].push_back(x);
        }
    }
    cout << "1,1は" << vc[1][1] << endl;
}