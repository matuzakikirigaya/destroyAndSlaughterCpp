

#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <algorithm>
using namespace std;

// 最大値、要素たち、という入力方式
vector<int> a;
int n;
int k;

bool nibunki(const int i, const int sum)
{
    if (i == n) //n娘入れるか決めた上でのこれ
    {
        return sum == k;
    }
    if (nibunki(i + 1, sum)) //入れない時の結果
    {
        return true;
    }
    if (nibunki(i + 1, sum + a[i])) //入れるときの結果
    {
        return true;
    }
    return false; //もし正しければどっかには引っかかるため
}

int main()
{
    cin >> n;
    int itt = n;
    while (itt--)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin >> k;
    const bool answer = nibunki(0, 0);
    const string yesOrNo = answer ? "Yes" : "No";
    cout << yesOrNo << endl;
    return 0;
}