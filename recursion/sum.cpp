#include <iostream>

using namespace std;

int sum(int a[], int lastIndex)
{
    if (lastIndex == 0)
        return a[0];

    return a[lastIndex] + sum(a, lastIndex - 1);
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    cout << sum(a, 3);
}
