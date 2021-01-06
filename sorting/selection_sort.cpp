#include <iostream>

using namespace std;

void swapNumbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << endl;
    }
}

void selectionSort(int a[], int length)
{
    int min_index;
    for (int i = 0; i < length; i++)
    {
        min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[min_index] > a[j])
            {
                min_index = j;
            }
        }
        swapNumbers(&a[i], &a[min_index]);
    }
}

int main()
{

    int a[3] = {1, 4, 2};
    selectionSort(a, 3);
    printArray(a, 3);
}
