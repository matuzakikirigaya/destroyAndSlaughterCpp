#include <cstdio>
#include <iostream>
int n[6], m;
int s[6] = {0,
            0,
            0,
            0,
            0,
            0};

void f500()
{
    if (n[5] > 0 && m - 500 > 0)
    {
        n[5] = n[5] - 1;
        m = m - 500;
        s[5] = s[5] + 1;
        f500();
    }
}
void f100()
{
    if (n[4] > 0 && m - 100 > 0)
    {
        n[4] = n[4] - 1;
        m = m - 100;
        s[4] = s[4] + 1;
        f100();
    }
}
void f50()
{
    if (n[3] > 0 && m - 50 > 0)
    {
        n[3] = n[3] - 1;
        m = m - 50;
        s[3] = s[3] + 1;
        f50();
    }
}
void f10()
{
    if (n[2] > 0 && m - 10 > 0)
    {
        n[2] = n[2] - 1;
        m = m - 10;
        s[2] = s[2] + 1;
        f10();
    }
}
void f5()
{
    if (n[1] > 0 || m - 5 > 0)
    {
        n[1] = n[1] - 1;
        m = m - 5;
        s[1] = s[1] + 1;
        f5();
    }
}
void f1()
{
    if (n[1] > 0 && m - 1 > 0)
    {
        n[0] = n[0] - 1;
        m = m - 5;
        s[0] = s[0] + 1;
        f1();
    }
}
int solve()
{
    int sum = 0;
    f500();
    f100();
    f50();
    f10();
    f5();
    f1();
    for (int i = 0; i < 6; i++)
    {
        sum = sum + s[i];
    }
    return sum;
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &n[i]);
    }
    scanf("%d", &m);
    std::cout << solve() << std::endl;
}