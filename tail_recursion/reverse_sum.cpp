#include <iostream>

using namespace std;

int countdown(int x, int tailSum = 0)
{
    if (x == 0)
        return tailSum;
    return countdown(x - 1, x + tailSum);
}

int main()
{
    cout << countdown(5);
}
