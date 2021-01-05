#include <iostream>

using namespace std;

int factorial(int x, int tailFactorial = 1)
{
    if (x == 1)
        return tailFactorial;
    return factorial(x - 1, x * tailFactorial);
}

int main()
{
    cout << factorial(3);
}
