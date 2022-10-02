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
    int i;
    int arr[] = {2, 4, 14, 24, 2, 11, 1, 9};
    int N = sizeof(arr) / sizeof(arr[0]);
    shakerSort(arr, N);
    cout << "After sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
