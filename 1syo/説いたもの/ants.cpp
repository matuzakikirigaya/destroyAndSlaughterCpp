#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// 最大値、要素たち、という入力方式

bool cmp(int &a, int &b)
{
    return a < b;
}

int main()
{
    vector<int> vc; // <T>でT型のvector
    int l;
    cin >> l;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vc.push_back(x);
    }
    std::sort(vc.begin(), vc.end(), cmp); //比較関数cmpを使用してsort

    const int size = vc.size();
    int x;
    for (int i = 0; i < size; i++)
    {
        int p = vc[i];
        int min = std::min(p, l - p);
        if (x < min)
        {
            x = min;
        }
    }
    std::cout << x << endl;
    for (int i = 0; i < size; i++)
    {
        int p = vc[i];
        int max = std::max(p, l - p);
        if (x < max)
        {
            x = max;
    }
    std::cout << x << endl;
}