#include <iostream>

using namespace std;

int linearSearch(int arr[], int endIndex, int numberToFind);

int main()
{
    int arr[10] = {1, 4, 5, 7, 9, 11, 13, 15, 19, 21};
    cout << linearSearch(arr, 9, 2);
}

int linearSearch(int arr[], int endIndex, int numberToFind)
{

    for (int i = 0; i < endIndex; i++)
    {
        if (arr[i] == numberToFind)
        {
            return i;
        }
    }
    return -1;
}
