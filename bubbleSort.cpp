#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool flag;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    int i;
    int arr[] = {2, 4, 14, 24, 2, 11, 1, 9};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "After sort: \n";
    for (i = 0; i < N; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
