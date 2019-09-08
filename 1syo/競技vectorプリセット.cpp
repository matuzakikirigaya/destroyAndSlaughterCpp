#include <vector> // vectorを使うためにインクルードする
#include <iostream>
using namespace std;
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

    n = vc.size() / 2;
    if (vc[n] == vc.at(n))
    {
        cout << vc[n] << '\n';
    }
}