
#include <iostream>

using namespace std;

bool accept()
{
    cout << "Do you want to proceed(y or n) ? \n";

    char answer = 0;
    cin >> answer;
    if (answer == 'y')
    {
        return true;
    };
    return false;
}

int main()
{
    bool hoge = accept();
    int poyo = hoge;
    string fuga = hoge ? "truedayo" : "falsedayo";
    string poyo2 = poyo ? "truedayo" : "falsedayo";
    cout << "this fuga" << fuga << "\nthis is poyo" << poyo2 << endl;
    return 0;
}
