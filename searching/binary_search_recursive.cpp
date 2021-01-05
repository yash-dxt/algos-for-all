#include <iostream>

using namespace std;

int binarySearch(int arr[], int startIndex, int endIndex, int numberToFind);

int main()
{
    int arr[10] = {1, 4, 5, 7, 9, 11, 13, 15, 19, 21};
    cout << binarySearch(arr, 0, 9, 13);
}

int binarySearch(int arr[], int startIndex, int endIndex, int numberToFind)
{
    int left = startIndex;
    int right = endIndex;
    if (left <= right)
    {
        int middle = (left + right) / 2; // make this better to solve overflow issue just in case.

        if (arr[middle] == numberToFind)
        {
            return middle;
        }
        if (arr[middle] < numberToFind)
        {
            left = middle + 1;
            return binarySearch(arr, left, right, numberToFind);
        }
        if (arr[middle] > numberToFind)
        {
            right = middle - 1;
            return binarySearch(arr, left, right, numberToFind);
        }
    }
    else
    {
        return -1;
    }
}
