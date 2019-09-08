#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <algorithm>
using namespace std;

// 最大値、要素たち、という入力方式

bool cmp(int &a, int &b)
{
    return a > b;
}

int main()
{
    vector<int> vc; // <T>でT型のvector
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vc.push_back(x);
    }
    std::sort(vc.begin(), vc.end(), cmp); //比較関数cmpを使用してsort
    int length = 1000;
    bool hoge = true;
    for (int i = 0; hoge && vc.size() < i - 2; i++)
    {
        int a, b, c;
        a = vc[i];
        b = vc[i + 1];
        c = vc[i + 2];
        if (a >= b + c)
        {
            length = 0;
        }
        else
        {
            length = a + b + c;
            hoge = false;
        }
    }
    std::cout << length << endl;
    return 0;
}