#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#define VECTOR(a) VECTOR_((a), sizeof(a) / sizeof(a[0]))
template <typename T>

std::vector<T> VECTOR_(T *array, std::size_t size)
{
    return std::vector<T>(array, array + size);
}


int x[] = {1, 2, 3, 4, 5};
int main()
{
    std::string y[] = {"aa", "bb", "cc"};

    std::vector<int> vx = VECTOR(x);
    std::vector<std::string> vy = VECTOR(y);
    std::cout << vx[2] << vy[2] << std::endl; // "3cc"
}