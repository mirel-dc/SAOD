#include <iostream>
#include <ctime>
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
    srand(time(NULL));
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

    bubbleSort(arr, N);
    cout << "After sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
