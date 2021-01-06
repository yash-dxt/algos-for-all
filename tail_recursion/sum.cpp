#include <iostream>

using namespace std;

int sum(int a[], int lastIndex, int total = 0)
{
    if (lastIndex == 0)
        return total + a[0];

    return sum(a, lastIndex - 1, total + a[lastIndex]);
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    cout << sum(a, 3);
}
