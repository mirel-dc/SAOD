#include <iostream>
using namespace std;

void shakerSort(int arr[], int n)
{
    int left = 0, right = n - 1, i;
    while (left <= right)
    {
        for (i = right; i >= left; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
        right--;
    }
}

int main()
{
    int i, N = 10;

    int arr[N];
    for (i = 0; i < N - 1; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;
    shakerSort(arr, N);
    cout << "After sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
