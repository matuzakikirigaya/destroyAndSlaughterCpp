#include <vector> // vectorを使うためにインクルードする
#include <iostream>
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
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vc.push_back(x);
    }
    std::sort(vc.begin(), vc.end(), cmp); //比較関数cmpを使用してsort
}