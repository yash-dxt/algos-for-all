#include <iostream>

using namespace std;

int countdown(int x)
{
    if (x == 1)
        return 1;
    return x + countdown(x - 1);
}

int main()
{
    cout << countdown(5);
}
