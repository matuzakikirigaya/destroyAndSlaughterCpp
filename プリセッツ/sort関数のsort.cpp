#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

struct Info
{
    std::string name;
    int age;

    Info(std::string inputted_name, int inputted_age)
    {
        name = inputted_name;
        age = inputted_age;
    }
};

bool cmp(const Info &a, const Info &b)
{
    return a.age < b.age;
}

int main(void)
{
    std::vector<Info> info;
    info.push_back(Info("foo", 17));
    info.push_back(Info("bar", 80));
    info.push_back(Info("baz", 30));

    std::sort(info.begin(), info.end(), cmp); //比較関数cmpを使用してsort

    for (auto itr : info)
    {
        cout << "age:" << itr.age << " name:" << itr.name << endl;
    }

    return 0;
}